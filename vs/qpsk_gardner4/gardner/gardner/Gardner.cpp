#include "Gardner.h"
//#include "RWfiles.h"
#include <Windows.h>


const float c1 = 0.0000226;	//环路滤波器参数  4.741218e-6   c1和c2由于精度原因扩大了100倍
const float c2 = 0.0271; // 0.35552;
const float FirCoe[33] = { 0.020235, 0.009104, -0.007819, -0.028095, -0.047882, -0.062429, -0.066824, -0.056881, -0.030002, 0.014145, \
							0.073285, 0.142611, 0.215306, 0.283433, 0.339066, 0.375469, 0.388133, 0.375469, 0.339066, 0.283433, 0.215306, \
							0.142611, 0.073285, 0.014145, -0.030002, -0.056881, -0.066824, -0.062429, -0.047882, -0.028095, -0.007819, 0.009104, 0.020235 };


static double now()
{
	LARGE_INTEGER freq;
	LARGE_INTEGER counter;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&counter);
	return counter.QuadPart / double(freq.QuadPart); //
}

/*
template<typename T, int ntaps>
void rcosFir<T, ntaps>::rcosFir_fnc(T *dinI, T *dinQ, T *doutI, T *doutQ)
{	
	for (int i = 0; i < len_sig; i++)
	{
		T accI = 0;
		T accQ = 0;

		for (int k = 0; k < ntaps; ++k)
		{
			accI += FirCoe[k] * dinI[i+k];
			accQ += FirCoe[k] * dinQ[i+k];
		}
		doutI[i] = accI;
		doutQ[i] = accQ;
	}
}
*/
//T *fir_outI = new T[len_sig];
//T *fir_outQ = new T[len_sig];
//auto start = now();
//rcosfir_inst.rcosFir_fnc(dinI, dinQ, fir_outI, fir_outQ);
//auto end = now();
//printf("fir:%.6f\n", end - start);

template<typename T>
void gardner<T>::gardner_fnc(T *dinI, T *dinQ, T *doutI, T *doutQ)
{

	//----设置各参数初始值------

	T timerr = 0;
	T lp, accum1 = 0;
		
	int T_interval = 4; 
	double tmp = 0.0;
	int currentpoint = 11;
	int adbufflenth = 0;
	int cnt = 0;
	T accum_tmp = 0;
//	float *msg_I = new float[len_code];
//	float *msg_Q = new float[len_code];
	T delta = 0;
	while (currentpoint < len_sig)
	{
		//-----time error detect------------
		T a_2I = dinI[currentpoint - 2 * T_interval];
		T a_2Q = dinQ[currentpoint - 2 * T_interval];
		T a_1I = dinI[currentpoint - T_interval];
		T a_1Q = dinQ[currentpoint - T_interval];
		T a0I = dinI[currentpoint];
		T a0Q = dinQ[currentpoint];
		if (a0I*a_2I > 0 && a0Q*a_2Q > 0)
			timerr = 0;
		else
			timerr = (a0I - a_2I) * a_1I + (a0Q - a_2Q) * a_1Q;

		//------loop filter--------------
		T multimpl = c1*timerr;
		accum_tmp = accum_tmp + multimpl;
		T multimp2 = c2*timerr;
		lp = (multimp2 + accum_tmp);		//c1和c2由于精度原因扩大了100倍，此处的输出再缩小100倍

		delta = delta + lp;

		doutI[cnt] = dinI[currentpoint];
		doutQ[cnt] = dinQ[currentpoint];
		cnt += 1;
//		accum[cnt] = accum_tmp;
		if (delta>1)
		{
			tmp = std::floor(delta);
			delta = delta - tmp;
			currentpoint = currentpoint + int(tmp);
		}

		if (delta < -1)
		{
			tmp = floor(delta);
			delta = delta - tmp - 1;
			currentpoint = currentpoint + int(tmp) + 1;
		}
		currentpoint = currentpoint + 2 * T_interval;
		
	}
		
//	auto end = now();
//	printf("%.6f\n", end - start);
}

//template<typename T>
void gardner_top(dtype *dinI, dtype *dinQ, dtype *doutI, dtype *doutQ)
{

	dtype *fir_outI = new dtype[len_sig + len_fir - 1];
	dtype *fir_outQ = new dtype[len_sig + len_fir - 1];
	auto start = now();

	ipp::fir<dtype> fs(FirCoe, len_fir);
	fs.filter(dinI, fir_outI, len_sig);
	fs.filter(dinQ, fir_outQ, len_sig);
	auto end = now();
	printf("fir:%.6f\n", end - start);
	gardner<dtype> gardner_fnc_inst;
	gardner_fnc_inst.gardner_fnc(fir_outI, fir_outQ, doutI, doutQ);
	
	delete[]fir_outI;
	delete[]fir_outQ;
}



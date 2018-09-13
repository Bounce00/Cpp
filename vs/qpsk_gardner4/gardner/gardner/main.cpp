#include <iostream>
#include <cmath>
#include "Gardner.h"
#include "RWfiles.h"
#include <memory>
#include <vector>

using namespace std;



int main()
{
	
	
	char *faI = "sigRandCode_noise12_5db_I.txt";
	char *faQ = "sigRandCode_noise12_5db_Q.txt";
//	std::vector<float> sig_inI;
//	sig_inI.resize(len_sig);

	std::vector<std::shared_ptr<dtype>> sig_inI, sig_inQ, sig_outI, sig_outQ, accum;

	sig_inI.push_back(std::shared_ptr<dtype>((dtype*)malloc(sizeof(dtype) * (len_sig + len_fir - 1)),free));
	sig_inQ.push_back(std::shared_ptr<dtype>((dtype*)malloc(sizeof(dtype) * (len_sig + len_fir - 1)), free));
	sig_outI.push_back(std::shared_ptr<dtype>((dtype*)malloc(sizeof(dtype) * (len_code + 100 - 1)), free));
	sig_outQ.push_back(std::shared_ptr<dtype>((dtype*)malloc(sizeof(dtype) * (len_code + 100 - 1)), free));
	accum.push_back(std::shared_ptr<dtype>((dtype*)malloc(sizeof(dtype) * (len_code + 100 - 1)), free));


	ReadFileVec(faI, sig_inI[0].get());
	ReadFileVec(faQ, sig_inQ[0].get());

//	delete []sig_inI;
//	delete []sig_inQ;
	

	float *fir_outI = new float[len_sig];
	float *fir_outQ = new float[len_sig];
	gardner_top(sig_inI[0].get(), sig_inQ[0].get(), sig_outI[0].get(), sig_outQ[0].get());
	/*
	char *fp11 = "fir_outI.txt";
	char *fp12 = "fir_outQ.txt";
	char *fp2 = "accum.txt";

	float *sig_oI = new float[len_sig] ;
	float *sig_oQ = new float[len_sig] ;
	for (int j = 0; j < len_code; j++)
	{
		sig_oI[j] = fir_outI[j];
		sig_oQ[j] = fir_outQ[j];
	}
//	delete[]sig_out;
	WriteFileVec(fp11, sig_oI);
	WriteFileVec(fp12, sig_oQ);
	WriteFileVec(fp2, accum[0].get());
	*/
	return 1;
}




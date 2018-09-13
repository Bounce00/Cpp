#ifndef _GARDNER_H
#define _GARDNER_H

#include <iostream>
#include <cmath>
#include "ipp.hpp"

using namespace std;

typedef unsigned int uint;
typedef float dtype;
extern const float c1;// = 0.000474;	//��·�˲�������  4.741218e-6   c1��c2���ھ���ԭ��������100��
extern const float c2;// = 0.35552;

const long int len_sig = 3999020;// 3999020;
const int len_code = 500000;// 500000;
const int len_fir = 33;
extern const float FirCoe[33];


//------gardner��: ʱ�������ȡ����·�˲���NCO-----------
template<typename T>
class gardner
{
public:
	void gardner_fnc(T *dinI, T *dinQ, T *doutI, T *doutQ);
};
/*
template<typename T, int ntaps>
class rcosFir
{
public:
//	rcosFir();
	void rcosFir_fnc(T *dinI, T *dinQ, T *doutI, T *doutQ);
};
*/
//template<typename T>
void gardner_top(dtype *dinI, dtype *dinQ, dtype *doutI, dtype *doutQ);

#endif



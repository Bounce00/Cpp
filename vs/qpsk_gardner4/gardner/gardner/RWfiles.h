#ifndef _RWFILES_H
#define _RWFILES_H

#include <fstream>
#include <iostream>
#include "Gardner.h"
#include <vector>
using namespace std;



void  ReadFileVec(char *fp, dtype OutBuf[len_sig])
{
	int i;
	//	int j;
	dtype val;

	ifstream fp_strmi(fp);
	if (!fp_strmi.is_open())
	{
		cerr << "Error!\nThis file is unable to open!" << '\n';
	}
	else
	{
		for (i = 0; i<len_sig; i++)
		{
			fp_strmi >> val;
			OutBuf[i] = val;
		}
	}

	fp_strmi.close();
	//	cout << setw(60) << setfill('-') << '-' << '\n';
	cout << "Read file successfully!\n";
	//	cout << setw(60) << setfill('-') << '-' << '\n';
	//	return 1;
}


//write to file
void WriteFileVec(char *fp, dtype *output)
{

	ofstream result;

	// Open a file to save the results
	result.open(fp);
	dtype tmp;
	// Apply stimuli, call the top-level function and save the results
	for (int i = 0; i < len_code; i++)
	{
		tmp = output[i];

		result << tmp;
//		result << setw(15) << '\t' << tmp2;
		result << endl;
	}
	result.close();
}



#endif



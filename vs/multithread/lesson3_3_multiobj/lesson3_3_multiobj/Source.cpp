#include <Windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI ThreadFun(LPVOID lpThreadParameter);

int main()
{
	cout << "main start" << endl;
	HANDLE hThread1 = CreateThread(NULL, 0, ThreadFun, (LPVOID)"A", 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadFun, (LPVOID)"B", 0, NULL);
	HANDLE hThread3 = CreateThread(NULL, 0, ThreadFun, (LPVOID)"C", 0, NULL);
	
	HANDLE handleArr[] = { hThread1,hThread2,hThread3 };

	//wait all
//	DWORD ret = WaitForMultipleObjects(3, handleArr, true, INFINITE);

	//wait anyone 
	DWORD ret = WaitForMultipleObjects(3, handleArr, false, INFINITE);

	cout << ret << endl;
	return 0;
}

DWORD WINAPI ThreadFun(LPVOID lpThreadParameter)
{
	char *p = (char*)lpThreadParameter;
	if (strcmp(p, "A") == 0)
		Sleep(10000);
	else if (strcmp(p, "B") == 0)
		Sleep(3000);
	else
		Sleep(1000);
	cout << p << "thread end" << endl;
	return 0;
}
#include <process.h>
#include <iostream>
#include <Windows.h>

using namespace std;

unsigned __stdcall  ThreadFun(void* param);

int main()
{
	cout << "main thread begins" << endl;
	unsigned ThreadId;
//	HANDLE hThread = (HANDLE)_beginthread(ThreadFun,0,"hello");
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, "hello", 0, &ThreadId);

	WaitForSingleObject(hThread, INFINITE);

	return 0;
}

unsigned __stdcall ThreadFun(void* param)
{
	char *p = (char*)param;
	int n = 0;
	while (++n <= 6)
	{ 
		Sleep(1000);
		cout << n <<p<< endl;
		if (n == 3)
			_endthreadex(666);
	}
	return 0;
		
}
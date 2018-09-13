#include <windows.h>
#include <iostream>

using namespace std;


DWORD WINAPI ThreadFun(LPVOID lpThreadParameter);

int main()
{
	DWORD ThreadId;
	cout << "main thread start" << endl;

	HANDLE hThread = CreateThread(
		NULL,	//设为NULL使用默认安全性
		0,	//默认栈大小
		ThreadFun,//线程处理函数，函数名就是函数指针
		NULL,	//向线程函数传入的参数
		0,//马上激活
		&ThreadId);

	DWORD code;
	GetExitCodeThread(hThread, &code);
	if (code == STILL_ACTIVE)
	{
		cout << "thread is sitll acitive" << endl;
	}


	cout << "main thread end" << endl;

	DWORD ret = WaitForSingleObject(hThread, 2000);
	if (ret == WAIT_TIMEOUT)
		cout << "wait child thread exit timeout" << endl;
	//强制退出线程，避免使用
	TerminateThread(hThread, 888);


	WaitForSingleObject(hThread, INFINITE);

	GetExitCodeThread(hThread, &code);


	cout << code << endl;
	if (code == STILL_ACTIVE)
	{
		cout << "thread is not acitive" << endl;
	}

	return 0;
}




DWORD WINAPI ThreadFun(LPVOID lpThreadParameter)
{
	int n = 0;
	while (n++ <= 6)
	{
		cout << "pirnt No." << n << " hello" << endl;
		Sleep(1000);
	}
	return 0;
}

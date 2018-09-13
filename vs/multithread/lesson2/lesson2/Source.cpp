#include <windows.h>
#include <iostream>

using namespace std;


DWORD WINAPI ThreadFun(	LPVOID lpThreadParameter);

int main()
{
	DWORD ThreadId;
	HANDLE hThread = CreateThread(
		NULL,	//设为NULL使用默认安全性
		0,	//
		ThreadFun,//线程处理函数，函数名就是函数指针
		"hello",	//向线程函数传入的参数
		0,//马上激活
		&ThreadId);

	if (hThread == NULL)
		cout << "thread create failed" << endl;

	cout << "thread handle:" << hThread << endl;
	cout << "thread ID:" << ThreadId << endl;

	cout << "main thread ID:" << GetCurrentThreadId() << endl;
	//close thread handle
//	CloseHandle(hThread);

	getchar();

	//挂起线程
	SuspendThread(hThread);

	getchar();
	
	//恢复线程
	ResumeThread(hThread);

	getchar();

	return 0;
}




DWORD WINAPI ThreadFun(LPVOID lpThreadParameter)
{
	char *str = (char*)lpThreadParameter;
	while (1)
	{
		cout << str << endl;
		cout << "child thread ID:" << GetCurrentThreadId() << endl;

		Sleep(1000);
	}
	return 0;
}

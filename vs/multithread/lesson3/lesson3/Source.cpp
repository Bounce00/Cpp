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
	
	cout << "main thread end" << endl;

	WaitForSingleObject(hThread, INFINITE);

	return 0;
}




DWORD WINAPI ThreadFun(LPVOID lpThreadParameter)
{
	int n = 0;
	while(n++<=6)
	{
		if (n == 3)
			//退出线程，退出码随意规定，避免使用该函数
			ExitThread(666);
		cout << "pirnt No."<<n<<" hello"<< endl;
		Sleep(1000);
	}
	return 0;
}

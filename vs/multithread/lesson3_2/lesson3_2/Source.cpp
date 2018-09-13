#include <windows.h>
#include <iostream>

using namespace std;


DWORD WINAPI ThreadFun(LPVOID lpThreadParameter);

int main()
{
	DWORD ThreadId;
	cout << "main thread start" << endl;

	HANDLE hThread = CreateThread(
		NULL,	//��ΪNULLʹ��Ĭ�ϰ�ȫ��
		0,	//Ĭ��ջ��С
		ThreadFun,//�̴߳����������������Ǻ���ָ��
		NULL,	//���̺߳�������Ĳ���
		0,//���ϼ���
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
	//ǿ���˳��̣߳�����ʹ��
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

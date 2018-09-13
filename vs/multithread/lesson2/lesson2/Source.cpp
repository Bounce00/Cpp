#include <windows.h>
#include <iostream>

using namespace std;


DWORD WINAPI ThreadFun(	LPVOID lpThreadParameter);

int main()
{
	DWORD ThreadId;
	HANDLE hThread = CreateThread(
		NULL,	//��ΪNULLʹ��Ĭ�ϰ�ȫ��
		0,	//
		ThreadFun,//�̴߳����������������Ǻ���ָ��
		"hello",	//���̺߳�������Ĳ���
		0,//���ϼ���
		&ThreadId);

	if (hThread == NULL)
		cout << "thread create failed" << endl;

	cout << "thread handle:" << hThread << endl;
	cout << "thread ID:" << ThreadId << endl;

	cout << "main thread ID:" << GetCurrentThreadId() << endl;
	//close thread handle
//	CloseHandle(hThread);

	getchar();

	//�����߳�
	SuspendThread(hThread);

	getchar();
	
	//�ָ��߳�
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

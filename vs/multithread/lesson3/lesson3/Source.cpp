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
			//�˳��̣߳��˳�������涨������ʹ�øú���
			ExitThread(666);
		cout << "pirnt No."<<n<<" hello"<< endl;
		Sleep(1000);
	}
	return 0;
}

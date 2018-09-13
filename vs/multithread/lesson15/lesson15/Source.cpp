#include <process.h>
//#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

unsigned __stdcall  ThreadFnc1(void* param);
unsigned __stdcall  ThreadFnc2(void* param);

//�Զ�����Ϣ���������Զ�����Ϣ���ϵ���ֵ)
#define MY_MSG WM_USER + 1

int main()
{
	unsigned ThreadId1;
	unsigned ThreadId2;
	HANDLE t1 = (HANDLE)_beginthreadex(NULL, 0, ThreadFnc1, NULL, 0, &ThreadId1);
	HANDLE t2 = (HANDLE)_beginthreadex(NULL, 0, ThreadFnc2, (void *)&ThreadId1, 0, &ThreadId2);

	HANDLE hArr[] = { t1,t2 };

	WaitForMultipleObjects(2, hArr, true, INFINITE);

	//	WaitForSingleObject(hThread, INFINITE);
	//cout << "��Ʊ����" << endl;
	return 0;
}

unsigned __stdcall ThreadFnc1(void* param)
{
	//���յڶ����̷߳�������Ϣ
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		switch (msg.message)
		{
			case MY_MSG:
				printf("�յ���Ϣ��%d\n", (int)msg.wParam);
			default:
				printf("�յ�WM_QUIT��Ϣ\n");
			break;
		}
	}

	return 0;

}

unsigned __stdcall ThreadFnc2(void* param)
{
	//����һ���̷߳���Ϣ
	DWORD threadld = (DWORD)param;
	int i = 1;
	while (1)
	{
		if (i < 10)
			PostThreadMessage(threadld, MY_MSG, (WPARAM)i++, NULL);
		else
			PostThreadMessage(threadld, WM_QUIT, NULL, NULL);
	}
	Sleep(1000);


	return 0;

}


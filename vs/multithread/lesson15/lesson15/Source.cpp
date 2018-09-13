#include <process.h>
//#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

unsigned __stdcall  ThreadFnc1(void* param);
unsigned __stdcall  ThreadFnc2(void* param);

//自定义消息（必须是自定义消息以上的数值)
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
	//cout << "卖票结束" << endl;
	return 0;
}

unsigned __stdcall ThreadFnc1(void* param)
{
	//接收第二个线程发来的消息
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		switch (msg.message)
		{
			case MY_MSG:
				printf("收到消息：%d\n", (int)msg.wParam);
			default:
				printf("收到WM_QUIT消息\n");
			break;
		}
	}

	return 0;

}

unsigned __stdcall ThreadFnc2(void* param)
{
	//给第一个线程发消息
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


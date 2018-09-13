#include <process.h>
//#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

unsigned __stdcall  SellThread1(void* param);
unsigned __stdcall  SellThread2(void* param);

int tickets = 100;	//100张票

HANDLE hMutex = INVALID_HANDLE_VALUE;


int main()
{
	//创建互斥体
	hMutex = CreateMutex(NULL, FALSE, L"售票互斥体");
	//cout << "开始卖票了" << endl;
	printf("开始卖票了\n");
	unsigned ThreadId1;
	unsigned ThreadId2;
	HANDLE t1 = (HANDLE)_beginthreadex(NULL, 0, SellThread1, "WINDOW_A", 0, &ThreadId1);
	HANDLE t2 = (HANDLE)_beginthreadex(NULL, 0, SellThread2, "WINDOW_B", 0, &ThreadId2);

	HANDLE hArr[] = { t1, t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	//	WaitForSingleObject(hThread, INFINITE);
	//cout << "卖票结束" << endl;
	printf("卖票结束\n");
	return 0;
}

unsigned __stdcall SellThread1(void* param)
{
	char *p = (char*)param;

	while (tickets > 0)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0)
		{
			//cout << "窗口" << p << "卖出" << tickets-- << "张票" << endl;
			printf("窗口%s卖出%d张票\n",p,tickets--);
			Sleep(10);
		}
		ReleaseMutex(hMutex);
	}

	return 0;

}

unsigned __stdcall SellThread2(void* param)
{
	char *p = (char*)param;

	while (tickets > 0)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0)
		{
			//cout << "窗口" << p << "卖出" << tickets-- << "张票" << endl;
			printf("窗口%s卖出%d张票\n", p, tickets--);
			Sleep(10);
		}
		ReleaseMutex(hMutex);
	}

	return 0;

}


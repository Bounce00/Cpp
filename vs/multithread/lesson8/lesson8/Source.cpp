#include <process.h>
#include <iostream>
#include <Windows.h>

using namespace std;

CRITICAL_SECTION sc1;
CRITICAL_SECTION sc2;

unsigned __stdcall  ThreadFnc1(void* param);
unsigned __stdcall  ThreadFnc2(void* param);

int main()
{
	InitializeCriticalSection(&sc1);
	InitializeCriticalSection(&sc1);

	//创建两个售票窗口
	cout << "主程序开始" << endl;
	unsigned ThreadId1;
	unsigned ThreadId2;
	HANDLE t1 = (HANDLE)_beginthreadex(NULL, 0, ThreadFnc1, "WINDOW_A", 0, &ThreadId1);
	HANDLE t2 = (HANDLE)_beginthreadex(NULL, 0, ThreadFnc2, "WINDOW_B", 0, &ThreadId2);

	HANDLE hArr[] = { t1, t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	cout << "主程序结束" << endl;
	return 0;
}

unsigned __stdcall ThreadFnc1(void* param)
{
	char *p = (char*)param;
	EnterCriticalSection(&sc1);
	cout << "A进入了1区" << endl;
	Sleep(3000);
	EnterCriticalSection(&sc2);
	cout << "A进入了2区" << endl;
	LeaveCriticalSection(&sc2);
	cout << "A离开2区" << endl;
	LeaveCriticalSection(&sc1);
	cout << "A离开1区" << endl;

	return 0;

}

unsigned __stdcall ThreadFnc2(void* param)
{
	char *p = (char*)param;
	EnterCriticalSection(&sc2);
	cout << "B进入了2区" << endl;
	Sleep(3000);
	EnterCriticalSection(&sc1);
	cout << "B进入了1区" << endl;
	LeaveCriticalSection(&sc1);
	cout << "B离开1区" << endl;
	LeaveCriticalSection(&sc2);
	cout << "B离开2区" << endl;
	
	return 0;

}


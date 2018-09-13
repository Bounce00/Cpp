#include <process.h>
#include <iostream>
#include <Windows.h>

using namespace std;

unsigned __stdcall  SellThread1(void* param);
unsigned __stdcall  SellThread2(void* param);

int tickets = 100;	//100��Ʊ

//1.�ٽ����ṹ
CRITICAL_SECTION Section;


int main()
{
	//2.��ʼ��
	InitializeCriticalSection(&Section);
	//����������Ʊ����
	cout << "��ʼ��Ʊ��" << endl;
	unsigned ThreadId1;
	unsigned ThreadId2;
	HANDLE t1 = (HANDLE)_beginthreadex(NULL, 0, SellThread1, "WINDOW_A", 0, &ThreadId1);
	HANDLE t2 = (HANDLE)_beginthreadex(NULL, 0, SellThread2, "WINDOW_B", 0, &ThreadId2);
	
	HANDLE hArr[] = { t1, t2};
	WaitForMultipleObjects(2, hArr, true, INFINITE);
	
	DeleteCriticalSection(&Section);
//	WaitForSingleObject(hThread, INFINITE);
	cout << "��Ʊ����" << endl;
	return 0;
}

unsigned __stdcall SellThread1(void* param)
{
	char *p = (char*)param;
	
	while (tickets > 0)
	{
		EnterCriticalSection(&Section);
		if (tickets > 0)
		{
			LeaveCriticalSection(&Section);
			cout << "����" << p << "����" << tickets-- << "��Ʊ" << endl;
			Sleep(10);
		}
		
	}
	
	return 0;

}

unsigned __stdcall SellThread2(void* param)
{
	char *p = (char*)param;
	
	while (tickets > 0)
	{
		EnterCriticalSection(&Section);
		if (tickets > 0)
		{
			LeaveCriticalSection(&Section);
			cout << "����" << p << "����" << tickets-- << "��Ʊ" << endl;
			Sleep(10);
		}
		
	}
	
	return 0;

}

 
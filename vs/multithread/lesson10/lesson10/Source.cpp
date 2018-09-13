#include <process.h>
//#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

unsigned __stdcall  SellThread1(void* param);
unsigned __stdcall  SellThread2(void* param);

int tickets = 100;	//100��Ʊ

HANDLE hMutex = INVALID_HANDLE_VALUE;


int main()
{
	//����������
	hMutex = CreateMutex(NULL, FALSE, L"��Ʊ������");
	//cout << "��ʼ��Ʊ��" << endl;
	printf("��ʼ��Ʊ��\n");
	unsigned ThreadId1;
	unsigned ThreadId2;
	HANDLE t1 = (HANDLE)_beginthreadex(NULL, 0, SellThread1, "WINDOW_A", 0, &ThreadId1);
	HANDLE t2 = (HANDLE)_beginthreadex(NULL, 0, SellThread2, "WINDOW_B", 0, &ThreadId2);

	HANDLE hArr[] = { t1, t2 };
	WaitForMultipleObjects(2, hArr, true, INFINITE);

	//	WaitForSingleObject(hThread, INFINITE);
	//cout << "��Ʊ����" << endl;
	printf("��Ʊ����\n");
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
			//cout << "����" << p << "����" << tickets-- << "��Ʊ" << endl;
			printf("����%s����%d��Ʊ\n",p,tickets--);
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
			//cout << "����" << p << "����" << tickets-- << "��Ʊ" << endl;
			printf("����%s����%d��Ʊ\n", p, tickets--);
			Sleep(10);
		}
		ReleaseMutex(hMutex);
	}

	return 0;

}


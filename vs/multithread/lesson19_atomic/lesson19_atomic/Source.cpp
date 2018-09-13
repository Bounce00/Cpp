#include <iostream>
#include <atomic>	//ԭ�Ӳ���ͷ�ļ�
#include <thread>

using namespace std;

atomic<int> N = 0;	//��atomic��֤N������ԭ����

void ThreadFnc()
{
	for (int i = 0; i < 1000000; ++i)
		++N;
}



int main()
{
	thread t1(ThreadFnc);
	thread t2(ThreadFnc);
	t1.join();
	t2.join();

	cout << N << endl;	//�������2000000,��Ϊ�̲߳������¼Ӳ����ص�������ԭ�Ӳ�������˿϶�����2000000

	return 0;
}
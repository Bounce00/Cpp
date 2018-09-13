#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>

using namespace std;
using namespace std::this_thread;

mutex m;

void ThreadFnc1()
{
	try
	{
		for (int i = 0; i < 10; ++i)
		{
		//	m.lock();
			unique_lock<mutex> lck(m);//���·����쳣��Ҳ�ǿ��԰�ȫ��������Ϊlck������������mutex
			lck.lock();//unique_lock�������Ŀ���
			if (i == 3) throw logic_error("�����쳣�ˣ�");

			cout << "A��ӡ" << i << endl;
			sleep_for(chrono::seconds(1));
//			m.unlock();//�׳��쳣ʱ������û��unlock,ʹ��B�޷���ȡmutex������
			lck.unlock();
		}
	}
	catch (logic_error & e)
	{
		cout << "����" << e.what() << endl;
	}
}
void ThreadFnc2()
{

	for (int i = 0; i < 10; ++i)
	{
		m.lock();
		cout << "B��ӡ" << i << endl;
		sleep_for(chrono::seconds(1));
		m.unlock();
	}


}

int main()
{
	thread t1(ThreadFnc1);
	thread t2(ThreadFnc2);
	t1.join();
	t2.join();
	return 0;

}
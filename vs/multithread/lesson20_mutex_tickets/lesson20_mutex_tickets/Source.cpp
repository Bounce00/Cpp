#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

int tickets = 100;
mutex m;
recursive_mutex m2;//���Եݹ����
timed_mutex m3;//����ָ����ס��ʱ��
void SellThread(string	&str);


int main()
{
	thread t1(SellThread, string("��Ʊ����A"));
	thread t2(SellThread, string("��Ʊ����B"));
	t1.join();
	t2.join();
	return 0;

}

void SellThread(string &str)
{
	while (tickets>0)
	{
//		m.lock();
//		m2.lock();
//		m2.lock();
		m3.try_lock_for(seconds(1));
		if (tickets > 0)
		{ 
			
			cout << str.c_str() << "����" << tickets-- << "��Ʊ" << endl;
	//		sleep_for(milliseconds(100));
		}
//		m.unlock();
//		m2.unlock();
//		m2.unlock();
	}
}
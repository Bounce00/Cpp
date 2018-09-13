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
			unique_lock<mutex> lck(m);//哪怕发生异常，也是可以安全解锁，因为lck会析构，解锁mutex
			lck.lock();//unique_lock更加灵活的控制
			if (i == 3) throw logic_error("发生异常了！");

			cout << "A打印" << i << endl;
			sleep_for(chrono::seconds(1));
//			m.unlock();//抛出异常时，导致没有unlock,使得B无法获取mutex，死锁
			lck.unlock();
		}
	}
	catch (logic_error & e)
	{
		cout << "错误" << e.what() << endl;
	}
}
void ThreadFnc2()
{

	for (int i = 0; i < 10; ++i)
	{
		m.lock();
		cout << "B打印" << i << endl;
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
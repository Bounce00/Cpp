#include <iostream>
#include <atomic>	//原子操作头文件
#include <thread>

using namespace std;

atomic<int> N = 0;	//用atomic保证N操作的原子性

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

	cout << N << endl;	//结果不是2000000,因为线程并发导致加操作重叠，不是原子操作，因此肯定少于2000000

	return 0;
}
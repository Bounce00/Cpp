#include <iostream>
#include <thread>

using namespace std;
//有所有的线程辅助函数  get_id()  yield() slepp_for() sleep_until()
using namespace std::this_thread;	
//有seconds  miliseconds类
using namespace std::chrono;

void threadFnc(string &str);

int main()
{
	thread t1(threadFnc, string("hello"));
	cout << t1.get_id() << endl;
	t1.join();
}

void threadFnc(string &str)
{
	cout << "线程ID" << get_id() << endl;
	while (true)
	{
		cout << str.c_str() << endl;
//		sleep_for(seconds(1));
		yield();//让线程睡眠一个极小的时间片，给其他线程执行
		sleep_until(system_clock::now() + milliseconds(1000));
	}
}

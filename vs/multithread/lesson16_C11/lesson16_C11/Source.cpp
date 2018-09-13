#include <iostream>
#include <thread>

using namespace std;

void threadFnc(string &strp);

int main()
{
	//采用默认构造函数
	thread t1;
	cout << t1.get_id() << endl;	//0
	cout << t1.joinable() << endl;	//0

	//使用带参数的构造函数
	thread t2(threadFnc, string("hello"));
	cout << t2.get_id() << endl;
	cout << t2.joinable() << endl;
	//thread对象在销毁之前，必须调用join，否则程序终止；或者detach
	t2.detach();	//与当前线程分离，成为孤儿线程
//	t2.join();

	return 0;
}

void threadFnc(string &strp)
{
	cout << strp.c_str() << endl;
}
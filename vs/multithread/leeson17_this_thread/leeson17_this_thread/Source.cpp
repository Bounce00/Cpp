#include <iostream>
#include <thread>

using namespace std;
//�����е��̸߳�������  get_id()  yield() slepp_for() sleep_until()
using namespace std::this_thread;	
//��seconds  miliseconds��
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
	cout << "�߳�ID" << get_id() << endl;
	while (true)
	{
		cout << str.c_str() << endl;
//		sleep_for(seconds(1));
		yield();//���߳�˯��һ����С��ʱ��Ƭ���������߳�ִ��
		sleep_until(system_clock::now() + milliseconds(1000));
	}
}

#include <iostream>
#include <thread>

using namespace std;

void threadFnc(string &strp);

int main()
{
	//����Ĭ�Ϲ��캯��
	thread t1;
	cout << t1.get_id() << endl;	//0
	cout << t1.joinable() << endl;	//0

	//ʹ�ô������Ĺ��캯��
	thread t2(threadFnc, string("hello"));
	cout << t2.get_id() << endl;
	cout << t2.joinable() << endl;
	//thread����������֮ǰ���������join�����������ֹ������detach
	t2.detach();	//�뵱ǰ�̷߳��룬��Ϊ�¶��߳�
//	t2.join();

	return 0;
}

void threadFnc(string &strp)
{
	cout << strp.c_str() << endl;
}
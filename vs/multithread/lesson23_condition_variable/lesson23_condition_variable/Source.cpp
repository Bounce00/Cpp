#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


condition_variable cv; //��֧��unique_lock<mutex>��Ϊwait�Ĳ���
condition_variable_any cv2;//�����κ�lockable������Ϊwait�Ĳ���
mutex m;

void ThreadFnc(int id)
{
	unique_lock<mutex> lck(m);

	cv.wait(lck);	//�ȴ�������
	cout << "�߳�ID" << id << endl;
}

int main()
{ 
	thread t1(ThreadFnc,1);
	thread t2(ThreadFnc,2);
	thread t3(ThreadFnc,3);
	
	cout << "3s����" << endl;
	sleep_for(seconds(3));

//	cv.notify_all();ȫ������
	cv.notify_one();

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
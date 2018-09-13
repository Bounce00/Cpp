#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


condition_variable cv; //仅支持unique_lock<mutex>作为wait的参数
condition_variable_any cv2;//接收任何lockable参数作为wait的参数
mutex m;

void ThreadFnc(int id)
{
	unique_lock<mutex> lck(m);

	cv.wait(lck);	//等待被唤醒
	cout << "线程ID" << id << endl;
}

int main()
{ 
	thread t1(ThreadFnc,1);
	thread t2(ThreadFnc,2);
	thread t3(ThreadFnc,3);
	
	cout << "3s后唤醒" << endl;
	sleep_for(seconds(3));

//	cv.notify_all();全部唤醒
	cv.notify_one();

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
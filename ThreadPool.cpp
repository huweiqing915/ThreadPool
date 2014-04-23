/*************************************************************************
	> File Name: ThreadPool.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月23日 星期三 14时11分34秒
 ************************************************************************/

#include "ThreadPool.h"

using namespace std;

/*
 *  构造函数除了初始化每个成员变量之外
 *  还需要依次对线程数组中的每个线程注册自身
 */
ThreadPool::ThreadPool(vector<WorkThread>::size_type max_thread):
	_task_queue(),_max_thread(max_thread),_thread_vector(_max_thread),
	_is_started(false), _lock(), _cond(&_lock) 
{
	for(vector<WorkThread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter)
	{
		iter->register_thread_pool(this);  //注册线程池
	}
}

ThreadPool::~ThreadPool()
{
	stop_thread_pool();
}

void ThreadPool::start_thread_pool()
{
	if(_is_started == false)
	{
		_is_started = true;  //必须放在开头，防止线程启动后因为
							 //_is_started这个变量异常退出
		for(vector<WorkThread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter)
		{
			iter->start();
		}
	}
}

void ThreadPool::stop_thread_pool()
{
	if(_is_started == false)
	{
		return ;
	}
	_is_started = false; //跟上面一样必须放在开头，以便于线程及时退出

	_cond.NotifyAll(); //激活所有正在等待任务的线程
					   //让它们退出循环，同时检测到布尔值的变化
					   //而使得线程退出

	for(vector<WorkThread>::iterator iter = _thread_vector.begin(); iter != _thread_vector.end(); ++iter)
	{
		iter->join();
	}
	while(!_task_queue.empty())
	{
		_task_queue.pop(); //清空队列
	}
}

bool ThreadPool::get_task_queue(Task &task)
{
	_lock.lock();
	/*
	 *  必须使用while循环，防止broadcast的破坏
	 */
	while(_is_started && _task_queue.empty())
	{
		_cond.wait();
	}
	/*
	 * 这里布尔值为false存在三种情况：
	 * 1.运行到这里线程池还没有开启
	 * 2.线程拿到了任务，退出了循环，但是线程池此刻关闭
	 * 3.线程正在等待任务，被stop函数中的notify_all函数
	 * 所激活，此时需要退出
	 */
	if(_is_started == false)
	{
		_lock.unlock();
		return false;
	}

	task = _task_queue.front();
	_task_queue.pop();
	_lock.unlock();
	return true;
}

/*
 * 向任务队列中添加任务
 */
bool ThreadPool::add_task_queue(Task task)
{
	_lock.lock();
	bool ret = false;
	if(_is_started)
	{
		_task_queue.push(task);
		_cond.notify(); //激活某个正在等待任务的线程
		ret = true;
	}
	_lock.unlock();
	return ret;
}

bool ThreadPool::is_task_queue_empty() 
{
	_lock.lock();
	bool ret = _task_queue.empty();
	_lock.unlock();
	return ret;
}

queue<Task>::size_type ThreadPool::get_task_queue_size()
{
	_lock.lock();
	queue<Task>::size_type ret = _task_queue.size();
	_lock.unlock();
	return ret;
}


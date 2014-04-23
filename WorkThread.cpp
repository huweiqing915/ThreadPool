/*************************************************************************
	> File Name: WorkThread.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月23日 星期三 14时09分03秒
 ************************************************************************/

#include "WorkThread.h"
#include "ThreadPool.h"
#include <iostream>

using namespace std;

void WorkThread::run()
{
	while(true)
	{
		Task task;
		bool ret = _p_thread_pool->get_task_queue(task);
		if(ret == false)
		{
			return ;
		}
		compute_task(task._num);
	}
}

void WorkThread::compute_task(int num)
{
	cout << "num: " << num << "  square num: " << num * num << endl;
}

void WorkThread::register_thread_pool(ThreadPool *p_thread_pool)
{
	_p_thread_pool = p_thread_pool;
}

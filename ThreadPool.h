/*************************************************************************
	> File Name: ThreadPool.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月23日 星期三 14时11分21秒
 ************************************************************************/

#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include <queue>
#include <vector>
#include "WorkThread.h"
#include "MutexLock.h"
#include "Condition.h"
#include "NonCopyable.h"

struct Task 
{
	int _num;
};

class ThreadPool : public NonCopyable {
public:
	ThreadPool(std::vector<WorkThread>::size_type max_thread);
	~ThreadPool();

	void start_thread_pool();
	void stop_thread_pool();

	bool add_task_queue(Task);
	bool get_task_queue(Task&);

	bool is_task_queue_empty();
	std::queue<Task>::size_type get_task_queue_size();

private:
	std::queue<Task> _task_queue; //任务队列
	std::vector<WorkThread>::size_type _max_thread; //线程的数目
	std::vector<WorkThread> _thread_vector; //用来存储线程
	bool _is_started; //标示线程池是否开启
	MutexLock _lock; //用来保持对队列的互斥操作
	Condition _cond; //实现对队列任务的同步操作
};

#endif

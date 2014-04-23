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
	std::queue<Task> _task_queue;
	std::vector<WorkThread>::size_type _max_thread;
	std::vector<WorkThread> _thread_vector;
	bool _is_started;
	MutexLock _lock;
	Condition _cond;
};

#endif

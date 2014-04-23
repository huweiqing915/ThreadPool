/*************************************************************************
	> File Name: WorkThread.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月23日 星期三 14时08分48秒
 ************************************************************************/

#ifndef WORKTHREAD_H_
#define WORKTHREAD_H_

#include "Thread.h"

class ThreadPool;

class WorkThread : public Thread {
public:
	void run();
	void register_thread_pool(ThreadPool*);
	void compute_task(int);

private:
	ThreadPool *_p_thread_pool;
};

#endif

/*************************************************************************
	> File Name: WorkThread.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月23日 星期三 14时08分48秒
 ************************************************************************/

#ifndef WORKTHREAD_H_
#define WORKTHREAD_H_

#include "Thread.h"

/*
 * 采用前向声明，避免与"ThreadPool.h"互相调用,
 * 如果用#include"ThreadPool.h"，则编译时会报错
 */
class ThreadPool;

class WorkThread : public Thread {
public:
	void run(); 
	void register_thread_pool(ThreadPool*);//注册线程池
	void compute_task(int);  //实际的工作函数，由run来调用

private:
	ThreadPool *_p_thread_pool;  //线程池的指针		
								 //用来指定线程去哪里获取任务
};

#endif

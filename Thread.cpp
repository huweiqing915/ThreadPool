/*************************************************************************
	> File Name: Thread.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 17时32分40秒
 ************************************************************************/

#include "Thread.h"
#include <iostream>

Thread::Thread():_tid(0) 
{ 
}

Thread::~Thread() 
{ 
}

void* Thread::thread_func(void *arg)
{
	Thread *p_thread = static_cast<Thread*>(arg);
	p_thread->run();
	return NULL;
}

void Thread::start()
{
	pthread_create(&_tid, NULL, thread_func, this);
}

void Thread::join()
{
	pthread_join(_tid, NULL);
}

pthread_t Thread::get_tid() const
{
	return _tid;
}

/*************************************************************************
	> File Name: Condition.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 17时10分58秒
 ************************************************************************/

#include "Condition.h"

Condition::Condition(MutexLock *p_lock):_p_lock(p_lock)
{
	pthread_cond_init(&_cond, NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond, &(_p_lock->_mutex));
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::NotifyAll()
{
	pthread_cond_broadcast(&_cond);
}

/*************************************************************************
	> File Name: Condition.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 17时10分49秒
 ************************************************************************/

#ifndef CONDITION_H_
#define CONDITION_H_

#include "NonCopyable.h"
#include "MutexLock.h"
#include <pthread.h>


class Condition : public NonCopyable {
public:
	Condition(MutexLock *p_lock);
	~Condition();

	void wait();
	void notify();
	void NotifyAll();

private:
	pthread_cond_t _cond;
	MutexLock *_p_lock;
};

#endif

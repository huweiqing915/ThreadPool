/*************************************************************************
	> File Name: MutexLock.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 16时41分56秒
 ************************************************************************/

#ifndef MUTEX_LOCK_H_
#define MUTEX_LOCK_H_

#include <pthread.h>
#include "NonCopyable.h"

class MutexLock: public NonCopyable {
public:
	friend class Condition;
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();
private:
	pthread_mutex_t _mutex;
};

#endif

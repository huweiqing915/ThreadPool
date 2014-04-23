/*************************************************************************
	> File Name: main.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月23日 星期三 16时02分28秒
 ************************************************************************/

#include "ThreadPool.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main()
{
	ThreadPool pool(10);
	pool.start_thread_pool();
	srand(time(NULL));
	while(true)
	{
		Task tmp;
		tmp._num = rand()%100;
		pool.add_task_queue(tmp);
		sleep(1);
	}
	return 0;
}


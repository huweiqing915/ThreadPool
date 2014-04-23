/*************************************************************************
	> File Name: NonCopyable.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 17时03分34秒
 ************************************************************************/

#ifndef NON_COPYABLE_H_
#define NON_COPYABLE_H_

class NonCopyable {
protected:
	NonCopyable() { }
	~NonCopyable() { }
private:
	NonCopyable(const NonCopyable&);
	NonCopyable& operator=(const NonCopyable&);
};

#endif

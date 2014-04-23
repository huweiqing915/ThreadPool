/*************************************************************************
	> File Name: NonCopyable.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月22日 星期二 17时03分34秒
 ************************************************************************/

#ifndef NON_COPYABLE_H_
#define NON_COPYABLE_H_

/*
 * 把拷贝构造函数和赋值运算符设为私有，是为了防止对象的复制
 * 把构造函数和析构函数设为protected，是防止生成本类的对象
 */
class NonCopyable {
protected:
	NonCopyable() { }
	~NonCopyable() { }
private:
	NonCopyable(const NonCopyable&);
	NonCopyable& operator=(const NonCopyable&);
};

#endif

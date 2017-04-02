#ifndef _QueueArray
#define _QueueArray


#include "Stack.h"
template < class T, int MAX_SIZE = 10 >
class QueueArray:public Stack<T>
{
private:
	T* info_;
	int first_;
	int next_;
public:
	QueueArray();
	~QueueArray();

	void pop();
	void push(const T& elem);
	bool empty ()const;
	T& front()const;

	bool full()const;
};

#endif // !_QueueArray
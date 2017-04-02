#ifndef _Stack
#define _Stack


template<class T>
class Stack {
public:
	Stack() {}
	virtual ~Stack() {}
	virtual T& front()const = 0;
	virtual void pop() = 0;
	virtual void push(const T& elem) = 0;
	virtual bool empty()const = 0;
};

#endif // !_Stack
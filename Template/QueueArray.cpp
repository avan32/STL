#include "QueueArray.h"

template<class T, int MAX_SIZE>
QueueArray<T, MAX_SIZE>::QueueArray() :
	info_(new T[MAX_SIZE]),
	first_(-1),
	next_(-1)
{
}

template<class T, int MAX_SIZE>
QueueArray<T, MAX_SIZE>::~QueueArray()
{
	delete info_;
}

template<class T, int MAX_SIZE>
void QueueArray<T, MAX_SIZE>::pop()
{
	if (empty())return;
	if (first_ == MAX_SIZE - 1) first_ = 0;
	else first_++;
}

template<class T, int MAX_SIZE>
void QueueArray<T, MAX_SIZE>::push(const T & elem)
{
	if (full()) return;

	if (empty()) {
		first_ = 0; next_ = 1;
		info_[first_] = elem;
		return;
	}

	if (next_ == MAX_SIZE - 1) {
		info_[next_] = elem;
		next_ = 0;
		return;
	}

	info_[next_++] = elem;
};

template<class T, int MAX_SIZE>
bool QueueArray<T, MAX_SIZE>::empty() const
{
	return first_ == next_;
};

template<class T, int MAX_SIZE>
T & QueueArray<T, MAX_SIZE>::front() const
{
	return info_[first_];
}

template<class T, int MAX_SIZE>
bool QueueArray<T, MAX_SIZE>::full() const
{
	return (next_ != MAX_SIZE - 1) ? first_ == next_ + 1 : first_ == 0;
}




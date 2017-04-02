#include "QueueList.h"

template<class T>
QueueList<T>::QueueList():
	first_(0),
	last_(0)
{
}

template<class T>
QueueList<T>::~QueueList()
{
	Node*p;
	while (first_) { p = first_; first_ = first_->link; delete p; }
}

template<class T>
void QueueList<T>::pop()
{
	if (empty()) return;
	Node* p = first_;
	first_ = first_->link;
	delete p;
}

template<class T>
void QueueList<T>::push(const T & elem)
{
	if (empty()) {
		first_ = new Node(elem, 0);
		last_ = first_;
		return;
	}
	Node* p = new Node(elem, 0);
	last_->link = p;
	last_ = p;
}

template<class T>
bool QueueList<T>::empty() const
{
	return first_ == 0;
}

template<class T>
T & QueueList<T>::front() const
{
	return first_->info;
}

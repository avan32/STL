#ifndef _QueueList
#define _QueueList

#include "Stack.h"

template<class T>
class QueueList :public Stack<T>
{
private:
	struct Node {
		T info;
		Node* link;
		Node(const T& elem, Node* addr) :
			info(elem), link(addr) {}
	};
	Node* first_;
	Node* last_;

public:
	QueueList();
	~QueueList();

	void pop();
	void push(const T& elem);
	bool empty()const;
	T& front()const;
};

#endif // !_QueueList



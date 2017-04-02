#include <iostream>

using std::cout;
using std::cin;
using std::endl;

///////////////////////////////////////////ForwardContainer///////////////////////////////////////

template <class T >
class ForwardContainer {
public:


	struct Node {
		Node* next;			 //point in next Node
		T value; 			 //value
		Node() :next(NULL) {}  //defult cnstructor
		Node(T v) :value(v) {};//Node contructor
	};

	/////////////////////////////////////////////ForwardIterator////////////////////////////////////////
	class ForwardIterator {

	public:
		explicit ForwardIterator(Node* ptr) :current_(ptr) {} //explicit cast

		ForwardIterator() {} //defult constructor

		~ForwardIterator() {}//desctrutor

		T& operator *()const { return (current_->value); } //operator* which return referens type


														   //operator  ++ postfix 
		ForwardIterator operator++ () {
			if (current_->next == 0) {
				current_->next = new Node();
			}
			current_ = current_->next;

			return *this;
		}

		//operator  ++  prefix
		ForwardIterator operator++ (int) {
			ForwardIterator result = *this;
			if (current_->next == 0)
			{
				current_->next = new Node();
			}

			current_ = current_->next;
			return result;
		}

		bool operator == (ForwardIterator& t) { return this->current_ == t.current_; }  //operator == compare current_ points

		bool operator != (ForwardIterator& t) { return this->current_ != t.current_; }  //operator != some to !(==)



	private:
		friend class ForwardContainer<T>;   		//friend class

		Node* current_; // point Node struct

	};


	typedef  T value_type;								// |
	typedef  T& reference;								// |_ typedef
	typedef  T* pointer;								// |
	typedef  ForwardIterator iterator;					// |


	ForwardContainer() :begin_(new Node()) {} // defult canstructur

	ForwardIterator begin() { return ForwardIterator(begin_); }; //function begin returned first iterator


																 //function returned last iterator-1
	ForwardIterator end() {
		Node *r = begin_;
		while (r->next != 0) r = r->next;

		return ForwardIterator(r);
	}

	//size the List
	int size() {
		int result = 0;

		Node* r = begin_;
		while (r->next != 0) { r = r->next; result++; }


		return result;
	};

	bool empty() { return (size() == 0); };//empty or no true empty , false no empty; 


	//swap function paramter and this 
	void swap(ForwardContainer<T>&b) {
		ForwardContainer<T> temp = *this;
		*this = b;
		b = temp;
	}

	bool operator > (ForwardContainer &t) {
		auto i = this->begin();
		auto j = t.begin();

		int _size1 = this->size();
		int _size2 = t.size();
		int h = (_size1 > _size2) ? _size1 : _size2;
		for (int k = 0; k < h; k++) {
			if (*i > *j) return true;
			if (*i < *j) return false;
			i++; j++;
		}

		if (_size1 > _size2)return true;
		return false;

	}
	bool operator < (ForwardContainer &t) {
		auto i = this->begin();
		auto j = t.begin();

		int _size1 = this->size();
		int _size2 = t.size();
		int h = (_size1 > _size2) ? _size1 : _size2;
		for (int k = 0; k < h; k++) {
			if (*i < *j) return true;
			if (*i > *j) return false;
			i++; j++;
		}

		if (_size1 < _size2)return true;
		return false;
	}
	bool operator >= (ForwardContainer &t) {
		return !(*this < t);
	}bool operator <= (ForwardContainer &t) {
		return !(*this > t);
	}
private:

	Node* begin_;
	

};

//////////////////////////////////////////////////merge////////////////////////////////////////////////////////
template <class InputIterator, class OutputIterator>
void
merge(InputIterator first1, InputIterator last1, InputIterator first2, InputIterator last2, OutputIterator result)
{
	InputIterator it1 = first1;
	InputIterator it2 = first2;
	OutputIterator res = result;
	while (it1 != last1 && it2 != last2)
		*res++ = (*it1 <= *it2) ? *it1++ : *it2++;
	while (it1 != last1) *res++ = *it1++;
	while (it2 != last2) *res++ = *it2++;

}


//////////////////////////////////////////////main//////////////////////////////////////////////////////////

int main() {

	ForwardContainer<int> a, b;
	ForwardContainer<int> c;

	
	typedef ForwardContainer<int>::ForwardIterator my_iterator;

	my_iterator iter_a = a.begin();
	my_iterator iter_b = b.begin();
	my_iterator iter_c = c.begin();

	cout << "a:: ";
	for (int i = 0; i < 10; i += 2) {
		*iter_a++ = i;
		cout << " " << i;
	}
	cout << endl;

	iter_a = a.begin();

	cout << "b:: ";
	for (int i = 1; i < 11; i += 2) {
		*(iter_b++) = i;
		cout << " " << i;
	}
	cout << endl;

	iter_b = b.begin();

	my_iterator iter_a_ = a.end();
	my_iterator iter_b_ = b.end();

	merge(iter_a, iter_a_, iter_b, iter_b_, iter_c);

	iter_c = c.begin();

	cout << "c::  ";
	for (int i = 0; i<c.size(); i++)
		cout << *(iter_c++) << " ";
	cout << endl;

	

	cin.get();

	return 0;
}

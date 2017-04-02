#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T, int SIZE = 20>
class Array {

public:

	class RandomAccessIterator {

	public:
		explicit RandomAccessIterator(T* ptr) :current_(ptr)
		{}

		RandomAccessIterator() {}

		~RandomAccessIterator() {}

		T& operator *()const { return *current_; }

		RandomAccessIterator operator++ () { current_++; return *this; }

		RandomAccessIterator operator++ (int) { RandomAccessIterator result = *this; current_++; return result; }

		RandomAccessIterator operator-- () { current_--; return *this; }

		RandomAccessIterator operator-- (int) { RandomAccessIterator result = *this; current_--; return result; }

		RandomAccessIterator operator [](int index) { current_ = current_ + index; return *this; }

		RandomAccessIterator operator += (int index) { current_ = current_ + index; return *this; }

		RandomAccessIterator operator -= (int index) { current_ = current_ - index; return *this; }

		RandomAccessIterator operator +  (int index) { return  RandomAccessIterator(current_ + index); }

		int operator - (RandomAccessIterator t) { return this->current_ - t.current_; }

		RandomAccessIterator operator - (int t) { return RandomAccessIterator(current_ - t); }

		bool operator == (RandomAccessIterator& t) { return this == &t; }

		bool operator != (RandomAccessIterator& t) { return this != &t; }

		bool operator >= (RandomAccessIterator t1) { return (*this - t1) >= 0; }

		bool operator <= (RandomAccessIterator t1) { return (*this - t1) <= 0; }


	private:
		friend class Array<T>;

		T* current_;

	};

	Array() :arr(new T[SIZE]) { };
	~Array() {};

	RandomAccessIterator begin() { return RandomAccessIterator(arr); }

	RandomAccessIterator end() { return RandomAccessIterator(arr+SIZE); }

	RandomAccessIterator operator [] (int i) { return  RandomAccessIterator(&arr[i]); }

private:

	T* arr;

};

template <class RandomAccessIterator, class LessThanComparable>
RandomAccessIterator binarySearch(RandomAccessIterator first, RandomAccessIterator last, const LessThanComparable& elem)

{
	RandomAccessIterator left = first;
	RandomAccessIterator right = last - 1;
	RandomAccessIterator mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (elem == *mid) return mid;
		(elem<*mid) ? right = mid - 1 : left = mid + 1;
	}
	cout << "Not found" << endl;
	return last;
}

int main() {
	Array<int> array;

	Array<int>::RandomAccessIterator begin = array.begin();
	Array<int>::RandomAccessIterator p = array.begin();

	for (int i = 0; i < 20; i++) *p++ = i;
	
	Array<int>::RandomAccessIterator end = array.end();

	Array<int>::RandomAccessIterator result = binarySearch(begin, end, 3);
	cout <<"*result = "<< *result << endl;

	cin.get();
	return 0;
}

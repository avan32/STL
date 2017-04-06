#pragma once

#include <iostream>
#include <set>
#include <utility>
using namespace std;

//***** Class BinaryRelation *****

class BinaryRelation {

	//types
	class Compare {
	public:
		bool operator()(pair<int, int> p, pair<int, int> q) {
			return ((p.first < q.first) || (p.first == q.first && p.second < q.second));
		}
	};

	typedef set<pair<int, int>, Compare>			SetOfPairs;
	typedef SetOfPairs::iterator					Iterator;
	typedef SetOfPairs::const_iterator				CIterator;

public:
	BinaryRelation(int n = 0);//creates empty relation
	BinaryRelation(const BinaryRelation& other);
	BinaryRelation& operator=(const BinaryRelation& other);


	bool isReflexive()const;
	bool isSymmetric()const;
	bool isAntisymmetric()const;
	bool isTransitive()const;
	bool isEquivalence()const;
	bool isOrder()const;


	BinaryRelation operator+(const BinaryRelation& other)const; //adition
	BinaryRelation operator*(const BinaryRelation& other)const; //binary, multiplication
	BinaryRelation operator*()const;							//unary, iteration

	bool	operator==(const BinaryRelation& other)const;
	bool	operator!=(const BinaryRelation& other)const;

private:
	int			 n_;
	SetOfPairs*	 relation_; //it is assumed that relation_ is a set of pairs (i, j), where 1<=i,j<=n_


	friend istream& operator>>(std::istream& input, BinaryRelation& relation);
	friend ostream& operator<<(std::ostream& output, const BinaryRelation& relation);

};





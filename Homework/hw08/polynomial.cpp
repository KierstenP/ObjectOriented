/* Author: Kiersten Page
 * Homework 8
 */
#include "polynomial.h"
using namespace std;

struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

void listClear(Node*& headPtr) {
	if (headPtr == nullptr) return;
	Node* next = headPtr->next;

	while (next != nullptr) {
		delete headPtr;
		headPtr = next;
		next = next->next;
	}
	delete headPtr;
	headPtr = nullptr;
}

Node* listDuplicateR(Node* headPtr) {
	if (headPtr == nullptr) return nullptr;
	return new Node(headPtr->data, listDuplicateR(headPtr->next));
}

int listLength(const Node* headPtr) {
	const Node* p = headPtr;
	int count = 0;
	while (p != nullptr) {
		++count;
		p = p->next;
	}
	return count;
}

void listAddHead(Node*& headPtr, int data) {
	headPtr = new Node(data, headPtr);
}

void listAddAfter(Node* prior, int data) {
	prior->next = new Node(data, prior->next);
}

void reverse(Node*& headPtr) {
	Node *cursor = headPtr;
	Node *prev = nullptr, *next = nullptr;
	while (cursor != nullptr) {
		next = cursor->next;
		cursor->next = prev;
		prev = cursor;
		cursor = next;
	}
	headPtr = prev;
}

//big three implementation (copy, constructor, destructor)
Polynomial::Polynomial(const Polynomial& rhs) {
	poly = listDuplicateR(rhs.poly);
}
Polynomial::~Polynomial() { listClear(poly); }

Polynomial& Polynomial::operator=(Polynomial& rhs) {
	listClear(poly);
	poly = listDuplicateR(rhs.poly);
	return *this;
}

//output operator

ostream& operator<<(ostream& os, const Polynomial& rhs) {
	rhs.print(toPrint.head, os);
	return os;
}

//function to help print the polynomial  in the correct order
void Polynomial::print(const Polynomial::Node* node, ostream& os, size_t degree) const
{
	if(node)
	{
		recvPrintHelper(node->next, os, ++degree);
		if(degree<(polynomialDegree))
		{
			if(node->data > 0){
				os << " + " << node->data;
			}
			else if(node->data < 0) {
				os << " - " << (node->data*-1);
			}
			else
				return;
		}
		else
			os << node->data;
		if(degree>2)
			os << "x^" << degree-1;
		else if(degree>1)
			os << "x";
	}
}

Polynomial::Polynomial(vector<int> nums) {
	listAddHead(poly, 0);
	for (int i = 0; i < nums.size(); ++i) {
		listAddAfter(poly, nums[i]);
	}
}

Polynomial::Polynomial(const Polynomial& rhs) {
	poly = listDuplicateR(rhs.poly);
}
Polynomial::~Polynomial() { listClear(poly); }

Polynomial& Polynomial::operator=(Polynomial& rhs) {
	listClear(poly);
	poly = listDuplicateR(rhs.poly);
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	Node* cursor = poly;
	Node* rhs_cursor = rhs.poly;
	while (cursor && rhs_cursor) {
		cursor->data += rhs_cursor->data;
		cursor = cursor->next;
		rhs_cursor = rhs_cursor->next;
	}
	if (rhs_cursor) {
		cursor = poly;
		while (cursor->next) cursor = cursor->next;
		while (rhs_cursor) {
			listAddAfter(cursor, rhs_cursor->data);
			rhs_cursor = rhs_cursor->next;
			cursor = cursor->next;
		}
	}
	return *this;
}

bool Polynomial::operator==(Polynomial& rhs) const {
	Node* cursor = poly;
	Node* rhs_cursor = rhs.poly;
	while (cursor && rhs_cursor) {
		if (cursor->data != rhs_cursor->data) {
			return false;
		}
		cursor = cursor->next;
		rhs_cursor = rhs_cursor->next;
	}
	if (cursor || rhs_cursor) return false;
	return true;
}


int Polynomial::evaluate(int num) {
	Node* cursor = poly->next;
	int result = 0;
	int degree = 0;
	while (cursor) {
		if (degree > 0) {
			int value = 1;
			for (int i = 0; i < degree; ++i)
				value *= num;
			result += cursor->data * value;
		}
		else {
			result += cursor->data;
		}
		++degree;
		cursor = cursor->next;
	}
	return result;
}

bool operator!=(Polynomial& lhs, Polynomial& rhs) {
	return !(lhs == rhs);
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
	Polynomial newPoly = lhs;
	newPoly += rhs;
	return newPoly;
}
#pragma once

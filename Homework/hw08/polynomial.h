/* Author: Kiersten Page
 * Homework 8
 */
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include <iostream>

struct Node;

class Polynomial {
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
public:
	Polynomial(std::vector<int> nums = { 0 });
	Polynomial(const Polynomial& rhs);
	~Polynomial();
	Polynomial& operator=(Polynomial& rhs);
	Polynomial& operator+=(const Polynomial& rhs);
	bool operator==(Polynomial& rhs) const;
	int evaluate(int num);
	void print(const Polynomial::Node* node, ostream& os, size_t degree)
private:
	Node* poly;
};
bool operator!=(Polynomial& lhs, Polynomial& rhs);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

#endif


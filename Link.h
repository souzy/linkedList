#ifndef LINK_H
#define LINK_H
#include "List.h"

using namespace std;

class Link {
public:
	Link(int value, Link * next = nullptr)
	: value(value), next(next) {}

private:
	Link * next;
	int value;

	friend class List;
	friend class Iterator;
};
#endif

#include "List.h"

#include <cassert>
#include <iostream>

void emptyTest() {
	List l;
	assert(l.empty()==true);
	assert(l.size()==0);
	Iterator it = l.begin();
	Iterator end = l.end();
	assert(it == end);
	assert(it.operator==(end));
}

void pushBack1() {
	List l;
	l.push_back(6);
	assert(l.empty()==false);
	assert(l.size()==1);
	Iterator it = l.begin();
	assert(*it == 6);
	*it = 4;
	assert(*it ==4);
	++it;
	assert(it == l.end());
}

void pushBack3(){
	List l;
	l.push_back(2);
	assert(l.size()==1);
	l.push_back(3);
	assert(l.size()==2);
	l.push_back(4);
	assert(l.empty()==false);
	assert(l.size()==3);
	Iterator it = l.begin();
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(it == l.end());
}

void pushFront3(){
	List l;
	l.push_front(2);
	assert(l.size()==1);
	l.push_front(3);
	assert(l.size()==2);
	l.push_front(4);
	assert(l.empty()==false);
	assert(l.size()==3);
	Iterator it = l.begin();
	assert(*it == 4);
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 2);
	++it;
	assert(it == l.end());
}

void popBack1(){
	List l;
	l.push_back(2);
	assert(l.empty()==false);
	assert(l.size()==1);
	l.pop_back();
	assert(l.empty()==true);
	assert(l.size()==0);
	Iterator it = l.begin();
	Iterator end = l.end();
	assert(it == end);
	assert(it.operator==(end));
}

void popBack3(){
	List l;
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	assert(l.empty()==false);
	assert(l.size()==5);
	Iterator it = l.begin();
	assert(*it == 2);
	l.pop_back();
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(*it == 5);
	++it;
	assert(it == l.end());
	it = l.begin();
	assert(*it == 2);
	l.pop_back();
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(it == l.end());
	it = l.begin();
	assert(*it == 2);
	l.pop_back();
	++it;
	assert(*it == 3);
	++it;
	assert(it == l.end());
}

void popFront1(){
	List l;
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	assert(l.empty()==false);
	assert(l.size()==3);
	Iterator it = l.begin();
	assert(*it == 2);
	l.pop_front();
	it = l.begin();
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(it == l.end());
}

void popFront3(){
	List l;
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	assert(l.empty()==false);
	assert(l.size()==5);
	Iterator it = l.begin();
	assert(*it == 2);
	l.pop_front();
	it = l.begin();
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(*it == 5);
	++it;
	assert(*it == 6);
	++it;
	assert(it == l.end());
	it = l.begin();
	assert(*it == 3);
	l.pop_front();
	it = l.begin();
	assert(*it == 4);
	++it;
	assert(*it == 5);
	++it;
	assert(*it == 6);
	++it;
	assert(it == l.end());
	it = l.begin();
	assert(*it == 4);
	l.pop_front();
	it = l.begin();
	assert(*it == 5);
	++it;
	assert(*it == 6);
	++it;
	assert(it == l.end());
}

void insertTest(){
	List l;
	l.push_back(1);
	l.push_back(3);
	l.push_back(5);
	assert(l.empty()==false);
	assert(l.size()==3);
	Iterator it = l.begin();
	++it;
	assert(*it == 3);
	l.insert(it, 2);
	it = l.begin();
	assert(*it == 1);
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 5);
	l.insert(it, 4);
	it = l.begin();
	assert(*it == 1);
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(*it == 4);
	++it;
	assert(*it == 5);
	++it;
	assert(it == l.end());
}

void eraseTest(){
	List l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	assert(l.empty()==false);
	assert(l.size()==5);
	Iterator it = l.begin();
	l.erase(it);
	assert(l.empty()==false);
	
}

int main(){
	emptyTest();
	pushBack1();
	pushBack3();
	pushFront3();
	popBack1();
	popBack3();
	popFront1();
	popFront3();
	insertTest();
	eraseTest();
	
	std::cout << "your test passed" << std::endl;

}

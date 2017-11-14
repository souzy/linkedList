#include <iostream>
#include <cassert>

#include "List.h"

using namespace std;

List::List():head(nullptr) {}

bool List::empty() const{
	return head == nullptr;
}

int List::size () const {
	Link * link =  head;
	int countLink = 0;
    while(link != nullptr) {
        ++countLink;
       	link = link->next;
    	}
   	return countLink;
}	

void List::push_back(int x) {
	if (head == nullptr) {
		head = new Link(x);
	} else {
		Link * link = head;
		while (link->next != nullptr) {
			link = link->next;
		} 
		link->next = new Link(x);
	}
}

void List::push_front(int x) {
    Link * link = new Link(x);
    link->next = 0;
    if(head == 0)
    {
        head = link;
    }
    else
    {
        link->next = head;
        head = link;
    }
}

void List::pop_back (){
    assert(head !=nullptr);
    if (head->next == nullptr){
        head = nullptr;
        return;
    }
    Link * temp = head;
    while(temp->next->next !=nullptr) {
       	temp = temp ->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
void List::pop_front ()
{
        assert(head != nullptr);
    Link * link = head;
    if(head->next == nullptr)
    {
        head = nullptr;
        delete link;
    }
    else
    {
        head = link->next;
        delete link;
    }
}

Iterator List::begin(){
    return Iterator(head);
}

Iterator List::end(){
    return Iterator(nullptr);
}

void List::insert (Iterator it, int value){
	assert(it.link != nullptr);
	if (it.link == head){
	  head = new Link(value, head);
		return;
	}
	Link * prev = head;
	while (prev->next != it.link) {
		prev = prev->next;
	}
	prev->next = new Link(value, it.link);		
}

Link* List::find_previous (Link * link)
{
          assert(link != nullptr);
	  Link * n;
	  n = head;
	  while (n -> next != link && n -> next != nullptr)
	       n = n -> next;
	  return n;
}
void List::erase(Iterator it) {
        int countLink = size();
        assert(it.link != nullptr);
	Link * prev =  find_previous(it.link);
	
	Link * temp = it.link;
	++it;
	Link * temp2 = it.link -> next;
	prev -> next = temp -> next;
	delete it.link;
	
	/*
        for (int i=0; i < countLink; i++){
	    ++it;
	    temp = it.link;
        }
	--it;
	Link * temp2 = it.link;

	*/
}

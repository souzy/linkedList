#ifndef LIST_H
#define LIST_H
#include "Iterator.h"
#include "Link.h"
class Iterator;
class Link;
class List{
public:
    List();
    ~List() {}
    bool empty() const;
    int size () const;
    void push_back(int x);
    void push_front(int x);
    void pop_back ();
    void pop_front ();
    Iterator begin();
    Iterator end();
    void insert (Iterator it, int value); 
    void erase ( Iterator it);
    Link *find_previous(Link *list);
    
    
private:
    Link * head;
    friend class Iterator;
};
#endif

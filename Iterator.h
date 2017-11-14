#pragma once

#include "Link.h"
#include "List.h"

class Iterator {
public:
        Iterator(Link * link) : link(link) {}
	void operator++();
	bool operator==(const Iterator & rightHandSide);
        int & operator* ();

private:
    Link * link;
    
    friend class List;
};

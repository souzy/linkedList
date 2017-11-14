#include <iostream>
#include <cassert>

#include "Iterator.h"

using namespace std;

bool Iterator::operator==(const Iterator & rightHandSide)
 {
return link == rightHandSide.link;
}

int & Iterator::operator* () {
    assert(link != nullptr);
    return link->value;
}

void Iterator::operator++(){
    assert(link != nullptr);
    link = link->next;
}

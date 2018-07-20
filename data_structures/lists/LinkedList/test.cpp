#include <iostream>
#include "linkedlist.h"

using namespace dat;

int main(int argc, char* argv[]) {
    linkedlist<int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(1);
    l.push_back(5);

    for (linkedlist<int>::iterator i = l.begin(); i != l.end(); i = i->right) {
        std::cout << i->val << std::endl;
    }
}
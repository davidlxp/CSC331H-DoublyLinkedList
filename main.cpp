#include <iostream>
#include "DList.cpp"

int main() {
    DList<int> l;
    l.insertBack(2);
    l.insertBack(1);
    l.insertFront(4);
    cout << l.getLength() << endl;
    l.printList();

    DList<int> l2;
    l2 = l;
    l2.printList();

}


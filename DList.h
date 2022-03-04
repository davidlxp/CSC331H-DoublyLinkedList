/***************************************************************/
/* Programmer: Xinpeng Liu                                     */
/* Date: February 22, 2022                                     */
/* Purpose:  doubly linked list class                          */
/***************************************************************/

#ifndef DOUBLYLINKEDLIST_DLIST_H
#define DOUBLYLINKEDLIST_DLIST_H

#include <iostream>
#include "node.h"
#include "DListIterator.cpp"
using namespace std;

template <class T>
class DList {
private:
    node<T>* first;
    node<T>* last;
    int length;

    /**
     * @Brief destroy all the nodes in a doubly linkedList
     */
    void destroy();

    /**
     * @Brief make a copy of an list
     */
    void copy(const DList<T>& other);

public:
    DList();                                           // Constructor
    ~DList();                                          // Destructor
    DList(const DList<T>& other);                      // Copy Constructor
    DList<T>& operator=(const DList<T>& other);  // Overloading Operator "="

    /**
     * @Brief check whether the list is empty
     */
    bool isEmpty() const;

    /**
     * @Brief delete one item from the list
     * if an item has multiple appearances in the list
     * we only delete the first one
     */
    void deleteItem(T);

    /**
     * @Brief check whether an item is in the list
     */
    bool searchItem(T) const;

    /**
     * @Brief get how many items in a list
     */
    int getLength() const;

    /**
     * @Brief insert to the front of the double linkedList
     */
    void insertFront(T);

    /**
     * @Brief insert to the back of the double linkedList
     */
    void insertBack(T);

    /**
     * @Brief print a doubly linkedList from front to back
     */
    void printList() const;

    /**
     * @Brief return an Iterator points to the 1st node of the list
     */
    DListIterator<T> begin();

    /**
     * @Brief return an Iterator points to the last node of the list
     */
    DListIterator<T> end();
};


#endif //DOUBLYLINKEDLIST_DLIST_H

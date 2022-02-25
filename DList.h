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
public:
    DList();                                           // Constructor
    ~DList();                                          // Destructor
    DList(const DList<T>& other);                      // Copy Constructor
    const DList<T>& operator=(const DList<T>& other);  // Overloading Operator "="
    bool isEmpty();
    void deleteItem(T);
    bool searchItem(T);
    int getLength();
    void insertFront(T);                                // Insert to the front of the double linkedList
    void insertBack(T);                                 // Insert to the back of the double linkedList
    void printList();
    void destroy();                                     // Destroy the whole list
    void copy(const DList<T>& other);
    DListIterator<T> begin();                           // Return an Iterator points to the start of the list
    DListIterator<T> end();                             // Return an Iterator points to the end of the list
};


#endif //DOUBLYLINKEDLIST_DLIST_H

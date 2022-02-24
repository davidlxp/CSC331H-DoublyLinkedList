#ifndef DOUBLYLINKEDLIST_DLIST_H
#define DOUBLYLINKEDLIST_DLIST_H

#include <iostream>
using namespace std;

/***************************************************************/
/* Programmer: Xinpeng Liu                                     */
/* Date: February 22, 2022                                     */
/* Purpose:  doubly linked list class                          */
/***************************************************************/

template <class T>
struct node {
    T info;
    node<T>* next;
    node<T>* prev;
};

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
};


#endif //DOUBLYLINKEDLIST_DLIST_H

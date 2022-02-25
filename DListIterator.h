/***************************************************************/
/* Programmer: Xinpeng Liu                                     */
/* Date: February 22, 2022                                     */
/* Purpose:  An iterator class for doubly linked list         */
/***************************************************************/

#ifndef DOUBLYLINKEDLIST_DLISTITERATOR_H
#define DOUBLYLINKEDLIST_DLISTITERATOR_H

#include <iostream>
using namespace std;
#include "node.h"

template <class T>
class DListIterator {
private:
    node<T>* current;
public:
    DListIterator();

    /**
     * @Brief return type of the function is "reference".
     * so we return an object, instead of the pointer
     */
    DListIterator(node<T>* ptr);

    /**
     * @Brief check whether the node, which Iterator
     * points to, has a next node or not
     */
    bool hasNext();

    /**
     * @Brief check whether the node, which Iterator
     * points to, has a previous node or not
     */
    bool hasPrev();

    /**
     * @Brief let "current" ptr advances to the next node.
     * returning an Iterator by reference, so user can do
     * cascade "next()" like "x.next().next()"
     */
    DListIterator<T>& next();

    /**
     * @Brief let "current" ptr moves back to the previous node.
     */
    DListIterator<T>& prev();

    /**
     * @Brief get "info" from node which this iterator currently at
     */
    T operator*();

    /**
     * @Brief let "current" ptr advances to the next node.
     * Prefix version --> "++x"
     */
    DListIterator<T>& operator++();

    /**
     * @Brief let "current" ptr advances to the next node.
     * Postfix version --> "x++"
     */
    DListIterator<T>& operator++(int);

    /**
     * @Brief let "current" ptr go back to the previous node.
     * Prefix version --> "--x"
     */
    DListIterator<T> operator--();

    /**
     * @Brief let "current" ptr go back to the previous node.
     * Prefix version --> "x--"
     */
    DListIterator<T>& operator--(int);




    /**
     * @Brief check if two Iterator point to the same node
     */
    const bool operator==(const DListIterator<T>& other);
    const bool operator!=(const DListIterator<T>& other);

};


#endif //DOUBLYLINKEDLIST_DLISTITERATOR_H

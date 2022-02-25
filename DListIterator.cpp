/*********************************************************************/
/* Programmer: Xinpeng Liu                                           */
/* Date: February 22, 2022                                           */
/* Purpose:  Implementation of iterator class for doubly linked list */
/*********************************************************************/

#include "DListIterator.h"

template <class T>
DListIterator<T>::DListIterator(){
    current = nullptr;
}

template <class T>
DListIterator<T>::DListIterator(node<T>* ptr){
    current = ptr;
}

template <class T>
bool DListIterator<T>::hasNext() {
    if(current == nullptr)
        return false;
    else if (current->next == nullptr)
        return false;
    else
        return true;
}

template <class T>
bool DListIterator<T>::hasPrev() {
    if(current == nullptr)
        return false;
    else if(current->prev == nullptr)
        return false;
    else
        return true;
}

template <class T>
DListIterator<T>& DListIterator<T>::next(){
    if(hasNext()) {
        current = current->next;
    }
    else
        cout << "Cannot increment, list is empty or iterator has reached the end of the list\n" << endl;
    return *this;
}

template <class T>
DListIterator<T>& DListIterator<T>::prev(){
    if(hasPrev()) {
        current = current->prev;
    }
    else
        cout << "Cannot decrement, list is empty or iterator has reached the begin of the list\n" << endl;
    return *this;
}

template <class T>
T DListIterator<T>::operator*(){
    if(current != nullptr)
        return current->info;
    else
        return NULL;
}

template <class T>
DListIterator<T>& DListIterator<T>::operator++(){
    return next();
}

template <class T>
DListIterator<T>& DListIterator<T>::operator++(int){
    DListIterator<T> temp = *this;
    ++(*this);
    return temp;
}

template <class T>
DListIterator<T> DListIterator<T>::operator--(){
    return prev();
}

template <class T>
DListIterator<T>& DListIterator<T>::operator--(int){
    DListIterator<T> temp = *this;
    --(*this);
    return temp;
}

template <class T>
const bool DListIterator<T>::operator==(const DListIterator<T>& other) {
    return current == other.current;
}

template <class T>
const bool DListIterator<T>::operator!=(const DListIterator<T>& other){
    return !(*this == other);
}

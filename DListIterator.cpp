/*********************************************************************/
/* Programmer: Xinpeng Liu                                           */
/* Date: February 22, 2022                                           */
/* Purpose:  Implementation of iterator class for doubly linked list */
/*********************************************************************/

#include "DListIterator.h"

template <class T>
DListIterator<T>::DListIterator()
{
    current = nullptr;
}

template <class T>
DListIterator<T>::DListIterator(node<T>* ptr)
{
    current = ptr;
}

template <class T>
bool DListIterator<T>::hasNext()
{
    bool res = true;
    if(current == nullptr || current->next == nullptr)
        res = false;
    return res;
}

template <class T>
bool DListIterator<T>::hasPrev()
{
    bool res = true;
    if(current == nullptr || current->prev == nullptr)
        res = false;
    return res;
}

template <class T>
DListIterator<T>& DListIterator<T>::next()
{
    if(hasNext())
    {
        cout << "Moved to next!" << endl;
        current = current->next;
    }
    else
        cout << "Can NOT move to next, list is empty or iterator has reached the end of the list\n" << endl;
    return *this;
}

template <class T>
DListIterator<T>& DListIterator<T>::prev()
{
    if(hasPrev()) {
        cout << "Moved to previous!" << endl;
        current = current->prev;
    }
    else
        cout << "Can NOT move to previous, list is empty or iterator has reached the begin of the list\n" << endl;
    return *this;
}

template <class T>
void DListIterator<T>::printItem()
{
    if(current != nullptr)
        cout << "Item: "
            << current->info << endl;
    else
        cout << "Nothing to print, the list is empty.\n" << endl;
}

template <class T>
T DListIterator<T>::operator*()
{
    if(current != nullptr)
        return current->info;
}

template <class T>
DListIterator<T>& DListIterator<T>::operator++()
{
    return next();
}

template <class T>
DListIterator<T>& DListIterator<T>::operator++(int)
{
    DListIterator<T> temp = *this;
    ++(*this);
    return temp;
}

template <class T>
DListIterator<T> DListIterator<T>::operator--()
{
    return prev();
}

template <class T>
DListIterator<T>& DListIterator<T>::operator--(int)
{
    DListIterator<T> temp = *this;
    --(*this);
    return temp;
}

template <class T>
const bool DListIterator<T>::operator==(const DListIterator<T>& other)
{
    return current == other.current;
}

template <class T>
const bool DListIterator<T>::operator!=(const DListIterator<T>& other)
{
    return !(*this == other);
}

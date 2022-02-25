/***************************************************************/
/* Programmer: Xinpeng Liu                                     */
/* Date: February 22, 2022                                     */
/* Purpose:  implementation of doubly linked list class        */
/***************************************************************/

#include "DList.h"

template <class T>
DList<T>::DList()
{
    first = nullptr;
    last = nullptr;
    length = 0;
}

template <class T>
DList<T>::~DList() {
    destroy();
}

template <class T>
DList<T>::DList(const DList<T>& other){
    copy(other);
}

template <class T>
const DList<T>& DList<T>::operator=(const DList<T>& other){

    /**
     * @Brief passing by reference, means "other" is an object.
     * so we need to use "&other" to get its address
     */
    if(this != &other){                             // avoid self-copy
        destroy();
        copy(other);
    }

    /**
     * @Brief return type of the function is "reference".
     * so we return an object, instead of the pointer
     */
    return *this;
}

template<class T>
bool DList<T>::isEmpty() {
    return first == nullptr;
}

template <class T>
void DList<T>::destroy() {
    /**
     * @CasesToConsider
     * 1. empty list
     * 2. only 1 node
     * 3. normal walk and destroy
     * */

    if(first != nullptr){
        node<T>* p = nullptr;
        while(first->next != nullptr){              // when there at more than 1 nodes
            p = first;
            first = first->next;                    // ptr "first" moves to the next node
            p->next = nullptr;                      // remove the access from prev node to current node
            delete p;                               // free the memory of prev node
            first->prev = nullptr;                  // remove the access from current node to the memory of prev node
        }
        delete last;                                // free the memory of the only node left
        last = nullptr;                             // set "last" ptr to null
        first = nullptr;                            // set "first" ptr to null
        p = nullptr;                                // set "p" ptr to null
        length = 0;
    }
}

template <class T>
void DList<T>::printList() {
    if(first == nullptr)
        cout << "\nNothing to print, the list is empty.\n" << endl;
    else{
        node<T>* p = first;
        while(p != nullptr){
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}

template <class T>
bool DList<T>::searchItem(T item) {
    if(first == nullptr)
        cout << "\nList is empty.\n" << endl;
    else{
        node<T>* p = first;
        while(p != nullptr){                        // unsorted list -> thus, no "p->info <= item" needed
            if(p->info == item)
                return true;
            p = p->next;
        }
        return false;
    }
}

template <class T>
int DList<T>::getLength() {
    return length;
}

template <class T>
void DList<T>::copy(const DList<T>& other){
    /**
     * @CasesToConsider
     * 1. "other" is empty
     * 2. "other" has nodes
     * */

    length = other.length;                          // copy the length

    if(other.first == nullptr){                     // if the "other" list is empty
        first = nullptr;
    }
    else{
        first = new node<T>;
        first->prev = nullptr;
        first->next = nullptr;
        first->info = other.first->info;

        node<T> *p = other.first->next;
        node<T> *q = first;
        while (p != nullptr) {
            q->next = new node<T>;                  // create the next node

            q->next->info = p->info;                // copy "info" to the next node
            q->next->prev = q;                      // build access from "next node" to "current node"
            q->next->next = nullptr;                // set "next" ptr of the "next node" to be null

            q = q->next;                            // move the ptr "q" to the next node
            p = p->next;                            // move the ptr "p" to the next node
        }
        last = q;                                   // set the "last" ptr
        q = nullptr;                                // set "q" ptr to null
        p = nullptr;                                // set "p" ptr to null
    }
}

template <class T>
void DList<T>::insertFront(T item) {
    /**
     * @CasesToConsider
     * 1. list is empty
     * 2. 1 item in the list
     * 3. multiple items in the list
     * */

    node<T>* p = first;

    first = new node<T>;
    first->prev = nullptr;
    first->next = p;
    first->info = item;

    if(p == nullptr)                                // when list was originally empty
        last = first;
    else                                            // when list originally has at least 1 node
        p->prev = first;

    p = nullptr;
    length++;
}

template <class T>
void DList<T>::insertBack(T item) {
    node<T>* p = last;

    last = new node<T>;
    last->prev = p;
    last->next = nullptr;
    last->info = item;

    if(p == nullptr)                                // when list was originally empty
        first = last;
    else                                            // when list originally has at least 1 node
        p->next = last;

    p = nullptr;
    length++;
}

template <class T>
void DList<T>::deleteItem(T item) {
    /**
     * @CasesToConsider
     * 1. list is empty
     * 2. deleting the only node in the list
     * 3. delete the first node
     * 4. delete the last node
     * 5. delete middle
     * 6. didn't find the item
     * */

    if(first == nullptr)                            // 1. list is empty
        cout << "The list is empty.\n" << endl;
    else
    {
        node<T>* p = nullptr;                       // "p" ptr is for walking
        node<T>* q = nullptr;                       // "q" ptr takes care of deleting

        if(first->next == nullptr){                 // when there's only 1 node in the list
            if(first->info != item)
                cout << "Item not found.\n" << endl;
            else {                                  // 2. deleting the only node
                delete first;
                length--;

                first = nullptr;
                last = nullptr;
            }
        }
        else {                                      // when list contains multiple nodes
            if(first->info == item){                // 3. deleting the 1st node
                p = first;
                first = first->next;
                first->prev = nullptr;
                p->next = nullptr;
                delete p;
                length--;

                p = nullptr;
            }
            else if(last->info == item){            // 4. deleting the last node
                p = last;
                last = last->prev;
                last->next = nullptr;
                p->prev = nullptr;
                delete p;
                length--;

                p = nullptr;
            }
            else {                                  // 5. walk to find the node to delete
                p = first->next;
                q = first;
                while(p != last && p->info != item){
                    q = p;
                    p = p->next;
                }
                if(p->info == item){
                    q->next = p->next;
                    p->next->prev = q;

                    p->next = nullptr;
                    p->prev = nullptr;
                    delete p;
                    length--;

                    p = nullptr;
                    q = nullptr;
                }
                else
                    cout << "Item not found.\n" << endl;
            }
        }
    }
}

template <class T>
DListIterator<T> DList<T>::begin() {
    DListIterator<T> iterator(first);
    return iterator;
}

template <class T>
DListIterator<T> DList<T>::end() {
    DListIterator<T> iterator(last);
    return iterator;
}
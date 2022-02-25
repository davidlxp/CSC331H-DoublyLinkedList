/***************************************************************/
/* Programmer: Xinpeng Liu                                     */
/* Date: February 22, 2022                                     */
/* Purpose: node struct for LinkedList                         */
/***************************************************************/

#ifndef DOUBLYLINKEDLIST_NODE_H
#define DOUBLYLINKEDLIST_NODE_H


template <class T>
struct node {
    T info;
    node<T>* next;
    node<T>* prev;
};


#endif //DOUBLYLINKEDLIST_NODE_H

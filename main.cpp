/**
 * Programmer: Xinpeng Liu
 * Date: 2022-02-22
 * Purpose: Test DoublyLinkedList class using a menu driven program
 * Input: User choice of operations
 * Output: Menu of choices and results of operations
 * Warning: In the test below, we initialized a doubly LinkedList of
 * integers, so it only allow operations on integers. For example, you
 * can only insert integer to the list.
 *
 */

#include <iostream>
#include "DList.cpp"

// runProgram runs the menu-driven program to allow user test
// the doubly LinkedList and its iterator
void runProgram();

// printMenu displays a menus of choices and returns the user's selection
int printMenu ();

// insertListFront inserts an item of user's choice into the front of list
void insertListFront ( DList<int> &l );

// insertListBack inserts an item of user's choice into the back of list
void insertListBack ( DList<int> &l );

// deleteListItem accepts user input and deletes the requested item from the list
void deleteListItem ( DList<int> &l );

// searchItem accepts user input and searches the list for the item
void searchListItem ( DList<int> l );

// iterateMenu displays a menus of choices which are the action an iterator can take.
// The function returns the user's selection
int iterateMenu();

// runIterator allows user to use an iterator to traverse an LinkedList
// Input: reference of an iterator which points to a node of list
void runIterator(DListIterator<int>& iterator);

int main()
{
    runProgram();
    return 0;
}

void runProgram()
{

    DList<int> l;
    int choice;

    cout<<"\nOperations allowed on the unsorted list of integers are below."
        <<"\nPlease enter the number of your choice and press return.\n\n";

    choice = printMenu();

    while ( choice != 9 )
    {
        switch ( choice )
        {

            case 1 :
            {
                insertListFront(l);
                cout << "\n" << "Current list:" << endl;
                l.printList();
                break;
            }

            case 2 :
            {
                insertListBack(l);
                cout << "\n" << "Current list:" << endl;
                l.printList();
                break;
            }

            case 3 :
            {
                deleteListItem(l);
                cout << "\n" << "Current list:" << endl;
                l.printList();
                break;
            }

            case 4 :
            {
                cout << "\n" << "Print the list:" << endl;
                l.printList();
                break;
            }

            case 5 :
                searchListItem ( l );
                break;

            case 6 :
                cout<<"\nThe list contains "
                    << l.getLength() << " items\n\n";
                break;

            case 7:
            {
                DListIterator<int> iteratorF = l.begin();
                runIterator(iteratorF);
                break;
            }

            case 8:
            {
                DListIterator<int> iteratorB = l.end();
                runIterator(iteratorB);
                break;
            }

            default :cout<<"\nNumber is not correct. Please look at "
                         <<"choices and reenter\n\n";
                break;
        }
        choice = printMenu();
    }

    /* Demonstrating the destroying and copying function */
    DList<int> l2;
    l2.insertFront(4);
    l2.insertBack(5);
    l2 = l;

    cout<<"\nPrinting a new list with the same values as the old list \n";
    l2.printList();

    cout<<"\nProgram terminated\n\n";
}

int printMenu ()
{
    int c;

    cout<<"\n1: Add an item to the front of list.";
    cout<<"\n2: Add an item to the back of list.";
    cout<<"\n3: Delete an item from the list.";
    cout<<"\n4: Print the list.";
    cout<<"\n5: Search the list for a given item";
    cout<<"\n6: Return the number of items in the list";
    cout<<"\n7: Start a front iterator";
    cout<<"\n8: Start a back iterator";
    cout<<"\n9: Quit.\n\n";
    cin>>c;

    return c;
}

void insertListFront ( DList<int> &l )
{
    int num;

    cout<<"\nEnter the number to insert : ";
    cin >> num;
    l.insertFront(num);
    cout << "\nThe number has been inserted\n\n";
}

void insertListBack ( DList<int> &l )
{
    int num;

    cout<<"\nEnter the number to insert : ";
    cin>>num;
    l.insertBack(num);
    cout << "\nThe number has been inserted\n\n";
}

void deleteListItem ( DList<int> &l )
{
    int num;

    cout<<"\nEnter the number to delete : ";
    cin>>num;

    if ( l.searchItem (num))
    {
        l.deleteItem (num);
        cout<<"\nThe number has been deleted\n\n";
    }
    else  cout<<"\nThe number is NOT in the list\n\n";


}

void searchListItem ( DList<int> l )
{
    int num;

    cout<<"\nEnter the number to search for : ";
    cin>>num;

    if ( l.searchItem (num))
        cout<<"\nThe number is in the list\n\n";
    else  cout<<"\nThe number is NOT in the list\n\n";
}

int iterateMenu(){
    int c;

    cout<<"\n1: Go to next item.";
    cout<<"\n2: Back to previous item.";
    cout<<"\n3: Print the current item.";
    cout<<"\n4: Quit.\n\n";
    cin>>c;

    return c;
}

void runIterator(DListIterator<int>& iterator){

    // print the initial value of node which iterator on
    if(!iterator.isNull())
        iterator.printItem();

    // get choice from user
    int choice;
    choice = iterateMenu();

    while ( choice != 4 )
    {
        switch( choice )
        {
            case 1:
            {
                if(iterator.hasNext())
                {
                    iterator.next();
                    iterator.printItem();
                }
                else
                    cout << "Can NOT move to next, list is empty or iterator has reached the end of the list\n" << endl;
                break;
            }
            case 2:
            {
                if(iterator.hasPrev())
                {
                    iterator.prev();
                    iterator.printItem();
                }
                else
                    cout << "Can NOT move to previous, list is empty or iterator has reached the begin of the list\n" << endl;
                break;
            }
            case 3:
                if(!iterator.isNull())
                    iterator.printItem();
                else
                    cout << "Nothing to print, the iterator is NULL, because the list is empty.\n" << endl;
                break;
        }
        choice = iterateMenu();
    }
}


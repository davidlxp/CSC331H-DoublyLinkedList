#include <iostream>
#include "DList.cpp"

void runProgram();
int printMenu ();
void insertListFront ( DList<int> &l );
void insertListBack ( DList<int> &l );
void deleteListItem ( DList<int> &l );
void searchListItem ( DList<int> l );

void runIterator(DListIterator<int>& iterator);

int main() {
    runProgram();

//    DList<int> l;
//    l.insertFront(5);
//    l.insertFront(6);
//    l.insertFront(8);
//    l.printList();
//    cout << endl;
//
//    DListIterator<int> iterator = l.begin();
//    (iterator++).next();
//    iterator.printItem();



    return 0;
}

void runProgram(){

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
                insertListFront( l );
                break;

            case 2 :
                insertListBack( l );
                break;

            case 3 :
                deleteListItem ( l );
                break;

            case 4 :
                l.printList();
                break;

            case 5 :
                searchListItem ( l );
                break;

            case 6 :
                cout<<"\nThe list contains "
                    << l.getLength() << " items\n\n";
                break;

            case 7: {
                DListIterator<int> iteratorF = l.begin();
                runIterator(iteratorF);
                break;
            }

            case 8: {
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
    cin>>num;

    if(num) {
        l.insertFront(num);
        cout << "\nThe number has been inserted\n\n";
    }
    else
        cout << "\nFailed! Please provide a valid Integer to insert\n\n";
}

void insertListBack ( DList<int> &l )
{
    int num;

    cout<<"\nEnter the number to insert : ";
    cin>>num;

    if(num) {
        l.insertBack(num);
        cout << "\nThe number has been inserted\n\n";
    }
    else
        cout << "\nFailed! Please provide a valid Integer to insert\n\n";
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
    int choice;

    choice = iterateMenu();
    while ( choice != 4 )
    {
        switch( choice )
        {
            case 1:
                iterator.next();
                break;
            case 2:
                iterator.prev();
                break;
            case 3:
                iterator.printItem();
                break;
        }
        choice = iterateMenu();
    }
}


#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :        DoublyLL
//  Description :       It is used to implement a generalized doubly
//                      linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    node
//  Description :       It represents a node of doubly linear linked list
//                      which can store any data type
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
struct node
{
    T data;
    node<T> *next;
    node<T> *prev;
};

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :        DoublyLL
//  Description :       It is used to perform various operations on
//                      generalized doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLL
{
    private:
        node<T>* first;
        int iCount;

    public:
        DoublyLL();

        void Display();

        int Count();

        void InsertFirst(T);

        void InsertLast(T);

        void InsertAtPos(T, int iPos);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int iPos);
};

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyLL
//  Description :       It is used to initialize the first pointer and
//                      initialize the count of nodes to zero
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside Constructor\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Description :       It is used to display all elements of the
//                      doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::Display()
{
    node<T>* temp = NULL;

    temp = this->first;

    printf("\nNULL <=> ");

    while(temp != NULL)
    {
        printf("| %d | <=> ",temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Description :       It is used to return the number of nodes
//                      present in the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Description :       It is used to insert a new node at the
//                      first position of the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    node<T> *newn = NULL;

    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Description :       It is used to insert a new node at the
//                      last position of the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    node<T> *newn = NULL;
    node<T>* temp = NULL;

    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Description :       It is used to insert a new node at the
//                      specified position of the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos)
{
    node<T>* temp = NULL;
    int i = 0;
    node<T>* newn = NULL;

    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((iPos < 0) || (iPos > iCount + 1))
    {
        cout<<"invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        this->InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        this->InsertLast(iNo);
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Description :       It is used to delete the first node from the
//                      doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        first = NULL;
    }
    else
    {
        node<T> *temp = NULL;

        temp = this->first;
        this->first = temp->next;
        this->first->prev = NULL;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Description :       It is used to delete the last node from the
//                      doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::DeleteLast()
{
    node<T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete this->first;
        first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Description :       It is used to delete a node from the
//                      specified position of the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    node<T>* temp = NULL;
    int i = 0;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        this->DeleteFirst();
    }
    else if(iPos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     main
//  Description :       It is used to demonstrate the operations of
//                      generalized doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    DoublyLL<int> sobj;

    int iRet = 0;

    while(1)
    {
        int iChoice = 0;
        int iValue = 0;
        int iPosition = 0;

        cout<<"-----------------------------------\n";
        cout<<"Enter your choice : \n";
        cout<<"-----------------------------------\n";
        cout<<"1 : Insert node at first position\n";
        cout<<"2 : Insert node at last position\n";
        cout<<"3 : Insert node at given position\n";
        cout<<"4 : Delete node at first position\n";
        cout<<"5 : Delete node at last position\n";
        cout<<"6 : Delete node at given position\n";
        cout<<"7 : Display the elements\n";
        cout<<"8 : Count the number of elements\n";
        cout<<"9 : Terminate the application\n";
        cout<<"-----------------------------------\n";

        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the value : \n";
                cin>>iValue;

                sobj.InsertFirst(iValue);
                break;

            case 2:
                cout<<"Enter the value : \n";
                cin>>iValue;

                sobj.InsertLast(iValue);
                break;

            case 3:
                cout<<"Enter the value : \n";
                cin>>iValue;

                cout<<"Enter the position : \n";
                cin>>iPosition;

                sobj.InsertAtPos(iValue, iPosition);
                break;

            case 4:
                sobj.DeleteFirst();
                break;

            case 5:
                sobj.DeleteLast();
                break;

            case 6:
                cout<<"Enter the position : \n";
                cin>>iPosition;

                sobj.DeleteAtPos(iPosition);
                break;

            case 7:
                cout<<"Elements of the Doubly Linked List are : \n";
                sobj.Display();
                break;

            case 8:
                iRet = sobj.Count();

                cout<<"Number of elements are : "<<iRet<<"\n";
                break;

            case 9:
                cout<<"Thank you for using Generalized Data Structure Library\n";
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }

    return 0;
}
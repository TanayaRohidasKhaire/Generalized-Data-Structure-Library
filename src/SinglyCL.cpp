#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :        SinglyCL
//  Description :       It is used to implement a generalized singly
//                      circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    node
//  Description :       It represents a node of singly circular linked list
//                      which can store any data type
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
struct node
{
    T data;
    struct node<T> *next;
};

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :        SinglyCL
//  Description :       It is used to perform various operations on
//                      generalized singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    private:
        struct node<T> *first;
        struct node<T> *last;
        int iCount;

    public:
        SinglyCL();

        void Display();

        int Count();

        void InsertFirst(T iNo);

        void InsertLast(T iNo);

        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int iPos);

        void DeleteAll();

        ~SinglyCL();
};

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyCL
//  Description :       It is used to initialize the first pointer,
//                      last pointer and count of nodes to zero
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Description :       It is used to display all elements of the
//                      singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::Display()
{
    struct node<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }

    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    while(temp != this->first);

    cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Description :       It is used to return the number of nodes
//                      present in the singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Description :       It is used to insert a new node at the
//                      first position of the singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }

    this->last->next = this->first;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Description :       It is used to insert a new node at the
//                      last position of the singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->last->next = this->first;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Description :       It is used to insert a new node at the
//                      specified position of the singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertAtPos(T iNo, int iPos)
{
    int i = 0;
    struct node<T> *temp = NULL;
    struct node<T> *newn = NULL;

    if((iPos < 1) || (iPos > this->iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        this->InsertFirst(iNo);
    }
    else if(iPos == this->iCount + 1)
    {
        this->InsertLast(iNo);
    }
    else
    {
        newn = new node<T>;

        newn->data = iNo;
        newn->next = NULL;

        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Description :       It is used to delete the first node from the
//                      singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    struct node<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;

        this->last->next = this->first;

        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Description :       It is used to delete the last node from the
//                      singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct node<T> *temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }

        delete this->last;

        this->last = temp;

        this->last->next = this->first;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Description :       It is used to delete a node from the
//                      specified position of the singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct node<T> *temp = NULL;
    struct node<T> *target = NULL;

    if((iPos < 1) || (iPos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        this->DeleteFirst();
    }
    else if(iPos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;

        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAll
//  Description :       It is used to delete all nodes from the
//                      singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAll()
{
    while(this->iCount != 0)
    {
        this->DeleteFirst();
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     ~SinglyCL
//  Description :       It is used to release all dynamically allocated
//                      memory before the object is destroyed
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::~SinglyCL()
{
    this->DeleteAll();
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     main
//  Description :       It is used to demonstrate the operations of
//                      generalized singly circular linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyCL<int> sobj;

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;
    int iPosition = 0;

    while(iChoice != 10)
    {
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
        cout<<"9 : Delete all nodes\n";
        cout<<"10 : Terminate the application\n";
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
                cout<<"Elements of the Singly Circular Linked List are : \n";
                sobj.Display();
                break;

            case 8:
                iRet = sobj.Count();

                cout<<"Number of elements are : "<<iRet<<"\n";
                break;

            case 9:
                sobj.DeleteAll();
                break;

            case 10:
                cout<<"Thank you for using Generalized Data Structure Library\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }
    }

    return 0;
}
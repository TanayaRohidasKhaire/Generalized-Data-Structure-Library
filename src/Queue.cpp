#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :        Queue
//  Description :       It is used to implement a generalized queue
//                      using linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    node
//  Description :       It represents a node of queue which can store
//                      any data type
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
//  Class Name :        Queue
//  Description :       It is used to perform various operations on
//                      generalized queue
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
    private:
        struct node<T> *first;
        struct node<T> *last;
        int iCount;

    public:
        Queue();

        void Enqueue(T iNo);

        T Dequeue();

        T Peep();

        void Display();

        int Count();

        void DeleteAll();

        ~Queue();
};

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Queue
//  Description :       It is used to initialize the first pointer,
//                      last pointer and count of nodes to zero
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T>::Queue()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Enqueue
//  Description :       It is used to insert a new element at the
//                      rear end of the queue
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Enqueue(T iNo)
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

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Dequeue
//  Description :       It is used to remove and return the element
//                      from the front end of the queue
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T>::Dequeue()
{
    T iValue;
    struct node<T> *temp = NULL;

    if(this->first == NULL)
    {
        cout<<"Queue is empty\n";
        return T();
    }

    iValue = this->first->data;

    temp = this->first;

    this->first = this->first->next;

    delete temp;

    this->iCount--;

    if(this->first == NULL)
    {
        this->last = NULL;
    }

    return iValue;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Peep
//  Description :       It is used to return the front element of the
//                      queue without deleting it
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T>::Peep()
{
    if(this->first == NULL)
    {
        cout<<"Queue is empty\n";
        return T();
    }

    return this->first->data;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Description :       It is used to display all elements of the queue
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Display()
{
    struct node<T> *temp = NULL;

    temp = this->first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Description :       It is used to return the number of elements
//                      present in the queue
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAll
//  Description :       It is used to delete all elements from the queue
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::DeleteAll()
{
    struct node<T> *temp = NULL;

    while(this->first != NULL)
    {
        temp = this->first;

        this->first = this->first->next;

        delete temp;

        this->iCount--;
    }

    this->last = NULL;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     ~Queue
//  Description :       It is used to release all dynamically allocated
//                      memory before the object is destroyed
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T>::~Queue()
{
    this->DeleteAll();
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     main
//  Description :       It is used to demonstrate the operations of
//                      generalized queue
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    Queue<int> qobj;

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    while(iChoice != 7)
    {
        cout<<"-----------------------------------\n";
        cout<<"Enter your choice : \n";
        cout<<"-----------------------------------\n";
        cout<<"1 : Enqueue the element\n";
        cout<<"2 : Dequeue the element\n";
        cout<<"3 : Peep the front element\n";
        cout<<"4 : Display the elements\n";
        cout<<"5 : Count the number of elements\n";
        cout<<"6 : Delete all elements\n";
        cout<<"7 : Terminate the application\n";
        cout<<"-----------------------------------\n";

        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the value : \n";
                cin>>iValue;

                qobj.Enqueue(iValue);
                break;

            case 2:
                iRet = qobj.Dequeue();

                cout<<"Dequeued element is : "<<iRet<<"\n";
                break;

            case 3:
                iRet = qobj.Peep();

                cout<<"Front element is : "<<iRet<<"\n";
                break;

            case 4:
                cout<<"Elements of the Queue are : \n";
                qobj.Display();
                break;

            case 5:
                iRet = qobj.Count();

                cout<<"Number of elements are : "<<iRet<<"\n";
                break;

            case 6:
                qobj.DeleteAll();
                break;

            case 7:
                cout<<"Thank you for using Generalized Data Structure Library\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }
    }

    return 0;
}
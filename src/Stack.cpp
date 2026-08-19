#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name :        Stack
//  Description :       It is used to implement a generalized stack
//                      using linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    node
//  Description :       It represents a node of stack which can store
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
//  Class Name :        Stack
//  Description :       It is used to perform various operations on
//                      generalized stack
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
    private:
        struct node<T> *first;
        int iCount;

    public:
        Stack();

        void Push(T iNo);

        T Pop();

        T Peep();

        void Display();

        int Count();

        void DeleteAll();

        ~Stack();
};

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Stack
//  Description :       It is used to initialize the first pointer and
//                      initialize the count of nodes to zero
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
Stack<T>::Stack()
{
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Push
//  Description :       It is used to insert a new element at the top
//                      of the stack
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Push(T iNo)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

    newn->data = iNo;
    newn->next = NULL;

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Pop
//  Description :       It is used to remove and return the top element
//                      from the stack
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T>::Pop()
{
    T iValue;
    struct node<T> *temp = NULL;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return T();
    }
    else
    {
        iValue = this->first->data;

        temp = this->first;

        this->first = this->first->next;

        delete temp;

        this->iCount--;

        return iValue;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Peep
//  Description :       It is used to return the top element of the
//                      stack without deleting it
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T>::Peep()
{
    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return T();
    }
    else
    {
        return this->first->data;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Description :       It is used to display all elements of the stack
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Display()
{
    struct node<T> *temp = NULL;

    temp = this->first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Description :       It is used to return the number of elements
//                      present in the stack
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAll
//  Description :       It is used to delete all elements from the stack
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::DeleteAll()
{
    struct node<T> *temp = NULL;

    while(this->first != NULL)
    {
        temp = this->first;

        this->first = this->first->next;

        delete temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     ~Stack
//  Description :       It is used to release all dynamically allocated
//                      memory before the object is destroyed
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

template <class T>
Stack<T>::~Stack()
{
    this->DeleteAll();
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     main
//  Description :       It is used to demonstrate the operations of
//                      generalized stack
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack<int> sobj;

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    while(iChoice != 7)
    {
        cout<<"-----------------------------------\n";
        cout<<"Enter your choice : \n";
        cout<<"-----------------------------------\n";
        cout<<"1 : Push the element\n";
        cout<<"2 : Pop the element\n";
        cout<<"3 : Peep the top element\n";
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

                sobj.Push(iValue);
                break;

            case 2:
                iRet = sobj.Pop();

                cout<<"Popped element is : "<<iRet<<"\n";
                break;

            case 3:
                iRet = sobj.Peep();

                cout<<"Top element is : "<<iRet<<"\n";
                break;

            case 4:
                cout<<"Elements of the Stack are : \n";
                sobj.Display();
                break;

            case 5:
                iRet = sobj.Count();

                cout<<"Number of elements are : "<<iRet<<"\n";
                break;

            case 6:
                sobj.DeleteAll();
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
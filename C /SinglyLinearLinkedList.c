```c
#include <stdio.h>
#include <stdlib.h>


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    node
//  Description :       It holds the information of
//                      each node of the linked list
//
///////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Description :       It is used to display all nodes
//                      of the linked list
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }

    printf("NULL\n");
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Description :       It is used to count the number
//                      of nodes present in the linked list
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Description :       It is used to insert a new node
//                      at the first position
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first)          // LL is empty
    {
        *first = newn;
    }
    else                        // LL contains atleast one node
    {
        newn->next = *first;
        *first = newn;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Description :       It is used to insert a new node
//                      at the last position
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)          // LL is empty
    {
        *first = newn;
    }
    else                        // LL contains atleast one node
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Description :       It is used to insert a new node
//                      at a specified position
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, int iNo, int iPos)
{
    int iCount = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    int i = 0;

    iCount = Count(*first);

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid position");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first, iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Description :       It is used to delete the first
//                      node from the linked list
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)                  // LL is empty
    {
        return;
    }
    else if((*first)->next == NULL)     // LL contains one node
    {
        free(*first);
        *first = NULL;
    }
    else                                // LL contains more than 1 node
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Description :       It is used to delete the last
//                      node from the linked list
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)                  // LL is empty
    {
        return;
    }
    else if((*first)->next == NULL)     // LL contains one node
    {
        free(*first);
        *first = NULL;
    }
    else                                // LL contains more than 1 node
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Description :       It is used to delete a node
//                      from a specified position
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, int iPos)
{
    int iCount = 0;
    int i = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry Point Function of the Singly Linear Linked List
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    int iRet = 0;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    InsertLast(&head, 111);
    InsertLast(&head, 121);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    DeleteLast(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    InsertAtPos(&head, 105, 4);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    DeleteAtPos(&head, 4);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);

    return 0;
}
```

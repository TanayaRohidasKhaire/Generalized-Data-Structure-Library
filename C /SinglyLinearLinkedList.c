#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    void *data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

typedef void (*DISPLAY)(void *);


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Description :       It is used to display all nodes
//                      of the linked list
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first, DISPLAY fp)
{
    while(first != NULL)
    {
        printf("| ");

        fp(first->data);

        printf(" | -> ");

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

void InsertFirst(PPNODE first, void *iNo, int size)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = malloc(size);

    memcpy(newn->data, iNo, size);

    newn->next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
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

void InsertLast(PPNODE first, void *iNo, int size)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = malloc(size);

    memcpy(newn->data, iNo, size);

    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
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

void InsertAtPos(PPNODE first, void *iNo, int iPos, int size)
{
    int iCount = 0;
    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first, iNo, size);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first, iNo, size);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = malloc(size);

        memcpy(newn->data, iNo, size);

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

    if(*first == NULL)
    {
        return;
    }

    temp = *first;

    *first = (*first)->next;

    free(temp->data);
    free(temp);
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

    if(*first == NULL)
    {
        return;
    }

    if((*first)->next == NULL)
    {
        free((*first)->data);
        free(*first);

        *first = NULL;

        return;
    }

    temp = *first;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next->data);
    free(temp->next);

    temp->next = NULL;
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

        free(target->data);
        free(target);
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DisplayInt
//  Description :       It is used to display the integer
//                      data stored in the node
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

void DisplayInt(void *data)
{
    printf("%d", *(int *)data);
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     main
//  Description :       It is used to perform various
//                      operations on the linked list
//  Author :            Tanaya Rohidas Khaire
//
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;
    int iPosition = 0;

    while(iChoice != 9)
    {
        printf("------------------------------------\n");
        printf("--------Enter your choice :---------\n");
        printf("------------------------------------\n");

        printf("1 : Insert node at first position\n");
        printf("2 : Insert node at last position\n");
        printf("3 : Insert node at given position\n");
        printf("4 : Delete node at first position\n");
        printf("5 : Delete node at last position\n");
        printf("6 : Delete node at given position\n");
        printf("7 : Display the elements\n");
        printf("8 : Count the number of elements\n");
        printf("9 : Terminate the application\n");

        printf("------------------------------------\n");

        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:

                printf("Enter the value :\n");
                scanf("%d", &iValue);

                InsertFirst(&head, &iValue, sizeof(int));

                break;


            case 2:

                printf("Enter the value :\n");
                scanf("%d", &iValue);

                InsertLast(&head, &iValue, sizeof(int));

                break;


            case 3:

                printf("Enter the value :\n");
                scanf("%d", &iValue);

                printf("Enter the position :\n");
                scanf("%d", &iPosition);

                InsertAtPos(&head, &iValue, iPosition, sizeof(int));

                break;


            case 4:

                DeleteFirst(&head);

                break;


            case 5:

                DeleteLast(&head);

                break;


            case 6:

                printf("Enter the position :\n");
                scanf("%d", &iPosition);

                DeleteAtPos(&head, iPosition);

                break;


            case 7:

                printf("Elements of the linked list are :\n");

                Display(head, DisplayInt);

                break;


            case 8:

                iRet = Count(head);

                printf("Number of elements are : %d\n", iRet);

                break;


            case 9:

                printf("Thank you for using Generic Data Structure Library\n");

                break;


            default:

                printf("Invalid choice\n");
        }
    }

    return 0;
}

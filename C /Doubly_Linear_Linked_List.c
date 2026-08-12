#include<stdio.h>
#include<stdlib.h>
#include<string.h>

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    node
//  Description :       It represents a node of a doubly linear linked list
//                      which contains generic data, next pointer and
//                      previous pointer
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct node
{
    void *data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Description :       It is used to count the number of nodes
//                      present in the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Description :       It is used to display all the nodes
//                      present in the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first, int iChoice)
{
    printf("\nNULL <=> ");

    while(first != NULL)
    {
        if(iChoice == 1)
        {
            printf("| %d | <=> ", *((int *)first->data));
        }
        else if(iChoice == 2)
        {
            printf("| %f | <=> ", *((float *)first->data));
        }
        else if(iChoice == 3)
        {
            printf("| %c | <=> ", *((char *)first->data));
        }
        else if(iChoice == 4)
        {
            printf("| %s | <=> ", (char *)first->data);
        }

        first = first->next;
    }

    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     CreateNode
//  Description :       It is used to create a new node and store
//                      generic data inside the node
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

PNODE CreateNode(int iChoice)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        printf("Unable to allocate memory\n");
        return NULL;
    }

    newn->next = NULL;
    newn->prev = NULL;

    if(iChoice == 1)
    {
        newn->data = malloc(sizeof(int));

        printf("Enter integer : ");
        scanf("%d", (int *)newn->data);
    }
    else if(iChoice == 2)
    {
        newn->data = malloc(sizeof(float));

        printf("Enter float : ");
        scanf("%f", (float *)newn->data);
    }
    else if(iChoice == 3)
    {
        newn->data = malloc(sizeof(char));

        printf("Enter character : ");
        scanf(" %c", (char *)newn->data);
    }
    else if(iChoice == 4)
    {
        newn->data = malloc(100 * sizeof(char));

        printf("Enter string : ");
        scanf(" %[^\n]", (char *)newn->data);
    }

    return newn;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Description :       It is used to insert a new node
//                      at the beginning of the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int iChoice)
{
    PNODE newn = NULL;

    newn = CreateNode(iChoice);

    if(newn == NULL)
    {
        return;
    }

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Description :       It is used to insert a new node
//                      at the end of the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first, int iChoice)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = CreateNode(iChoice);

    if(newn == NULL)
    {
        return;
    }

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
        newn->prev = temp;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Description :       It is used to insert a new node
//                      at a specified position
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE first, int iChoice, int iPos)
{
    int i = 0;
    int iCount = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    iCount = Count(*first);

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first, iChoice);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first, iChoice);
    }
    else
    {
        temp = *first;

        newn = CreateNode(iChoice);

        if(newn == NULL)
        {
            return;
        }

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Description :       It is used to delete the first node
//                      from the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free((*first)->data);
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;

        (*first)->prev = NULL;

        free(temp->data);
        free(temp);
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Description :       It is used to delete the last node
//                      from the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free((*first)->data);
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;

        free(temp->data);
        free(temp);
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Description :       It is used to delete a node
//                      from a specified position
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE first, int iPos)
{
    int i = 0;
    int iCount = 0;
    PNODE temp = NULL;
    PNODE del = NULL;

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

        del = temp->next;

        temp->next = del->next;
        del->next->prev = temp;

        free(del->data);
        free(del);
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAll
//  Description :       It is used to delete all nodes
//                      from the doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

void DeleteAll(PPNODE first)
{
    PNODE temp = NULL;

    while(*first != NULL)
    {
        temp = *first;

        *first = (*first)->next;

        free(temp->data);
        free(temp);
    }
}

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     main
//  Description :       It is the entry point of the program and provides
//                      a menu driven interface to perform operations
//                      on the generic doubly linear linked list
//  Author :            Tanaya Rohidas Khaire
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    int iChoice = 0;
    int iOperation = 0;
    int iPos = 0;
    int iRet = 0;

    printf("========================================\n");
    printf(" Generic Doubly Linear Linked List\n");
    printf("========================================\n");

    printf("\nSelect Data Type\n");
    printf("1 : Integer\n");
    printf("2 : Float\n");
    printf("3 : Character\n");
    printf("4 : String\n");

    printf("Enter choice : ");
    scanf("%d", &iChoice);

    if((iChoice < 1) || (iChoice > 4))
    {
        printf("Invalid data type choice\n");
        return 0;
    }

    while(1)
    {
        printf("\n========================================\n");
        printf(" Generic Doubly Linear Linked List\n");
        printf("========================================\n");

        printf("1 : Insert First\n");
        printf("2 : Insert Last\n");
        printf("3 : Insert At Position\n");
        printf("4 : Delete First\n");
        printf("5 : Delete Last\n");
        printf("6 : Delete At Position\n");
        printf("7 : Display\n");
        printf("8 : Count\n");
        printf("9 : Delete All\n");
        printf("0 : Exit\n");

        printf("Enter your choice : ");
        scanf("%d", &iOperation);

        switch(iOperation)
        {
            case 1:
                InsertFirst(&head, iChoice);
                break;

            case 2:
                InsertLast(&head, iChoice);
                break;

            case 3:
                printf("Enter position : ");
                scanf("%d", &iPos);

                InsertAtPos(&head, iChoice, iPos);
                break;

            case 4:
                DeleteFirst(&head);
                break;

            case 5:
                DeleteLast(&head);
                break;

            case 6:
                printf("Enter position : ");
                scanf("%d", &iPos);

                DeleteAtPos(&head, iPos);
                break;

            case 7:
                Display(head, iChoice);
                break;

            case 8:
                iRet = Count(head);

                printf("Number of elements are : %d\n", iRet);
                break;

            case 9:
                DeleteAll(&head);
                printf("All nodes deleted successfully\n");
                break;

            case 0:
                DeleteAll(&head);
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

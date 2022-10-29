/* Program to demonstrate the operations on a cicular singly linked list with header node */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node * NODE;

//Function to create one circular linked node
NODE create()
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nMemory Error\n");
        return NULL;
    }
    newnode->link = newnode;
    return newnode;
}

//Function to create a circular linked list of the given length
NODE form(NODE head, int n)
{
    NODE x,temp, prev;
    int i;
    printf("\nPlease enter %d list elements\n", n);
    prev = head;
    for(i=1; i<=n; i++)
    {
       temp = create();
       scanf("%d", &temp->data);
       prev->link = temp;
       prev = temp;
       head->data++; 
    }
    prev->link = head;
    return head;
}

//Function to display the elements of a circular singly linked list
void display(NODE head)
{
    NODE temp;
    temp = head->link;
    if(head->link == head)
    {
        printf("\nList Empty\n");
        return;
    }
    printf("\nThe elements of the list are:\n");
    do
    {
        printf("%d\t", temp->data);
        temp = temp->link;       
    } 
    while (temp != head);
    return;   
}

//Function to insert an element to the beginning of the circular linked list
NODE insert_front(NODE head, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    temp->link = head->link;
    head->link = temp;
    head->data++;
    display(head);
    return head;
}

//Function to insert an element to the rear of the circular linked list
NODE insert_rear(NODE head, int item)
{
    NODE new, temp;
    new = create();
    new->data = item;
    temp = head->link;
    while(temp->link != head)
    {
        temp = temp->link;
    }
    temp->link = new;
    new->link = head;
    head->data++;
    display(head);
    return head;
}

//Function to delete an element from the beginning of the circular linked list
NODE delete_front(NODE head)
{
    if(head->link == head)
    {
        printf("\nList empty\n");
        return head;
    }
    NODE temp;
    temp = head->link;
    head->link = temp->link;
    printf("\nThe node with %d is deleted\n", temp->data);
    free(temp);
    head->data--;
    display(head);
    return head;
}

//Function to delete an element from the rear of the circular linked list
NODE delete_rear(NODE head)
{
    if(head->link == head)
    {
        printf("\nList Empty\n");
        return head;
    }
    NODE prev, cur;
    cur = head->link;
    while(cur->link != head)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = head;
    free(cur);
    display(head);
    head->data--;
    return head;
}

//Function to insert an element in the given position
NODE insert_pos(NODE head, int pos, int item)
{
    if(pos<1 || pos>head->data+1)
    {
        printf("\nInvalid Position\n");
        return head;
    }
    int i;
    NODE temp, prev, cur;
    temp = create();
    temp->data = item;
    cur = head->link;
    prev = head;
    for(i=1; i<pos; i++)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = temp;
    temp->link = cur;
    display(head);
    head->data++;
    return head;
}

//Function to delete an element in the given position
NODE delete_pos(NODE head, int pos)
{
    int i;
    NODE prev, cur;
    if(pos<1 || pos>head->data)
    {
        printf("\nInvalid position\n");
        return NULL;
    }
    if(head->link == head)
    {
        printf("\nList Empty\n");
        return head;
    }
    cur = head->link;
    prev = head;
    for(i=1; i<pos; i++)
    {
        prev = cur;
        cur = cur->link; 
    }
    prev->link = cur->link;
    free(cur);
    head->data--;
    display(head);
    return head;
}

//Function to reverse a given list
NODE reverse(NODE head)
{
    if(head->link == head)
    {
        printf("\nList Empty\n");
        return head;
    }
    NODE temp, cur, prev, ptr;
    cur = head->link;
    prev = NULL;
    while(cur != head)
    {
        temp = cur;
        cur = cur->link;
        temp->link = prev;
        if(temp->link == NULL)
            ptr = temp;
        prev = temp;
    }
    head->link = prev;
    ptr->link = head;
    display(head);
    return head;
}

//Function to search the list for the given key
int search(NODE head, int key)
{
    NODE temp;
    int pos =1;
    if(head->link == head)
    {
        printf("\nList Empty\n");
        return -1;
    }
    temp = head->link;
    while (temp->data != key && temp != head)
    {
        temp = temp->link;
        pos++;
    }
    if(temp == head)
        return 0;
    else
        return pos;
}

//Function to update the given list
NODE update(NODE head, int key, int item)
{
    NODE temp;
    int pos, i;
    pos = search(head, key);
    if(pos == -1)
        return head;
    if(pos == 0)
    {
        printf("\nThe element to be updated does not exist\n");
        return head;
    }
    temp = head->link;
    for(i=1; i<pos; i++)
    {
        temp = temp->link;
    }
    temp->data = item;
    display(head);
    return head;
}

//Function to delete the node by it's key
NODE delete_key(NODE head, int key)
{
    int pos;
    pos = search(head, key);
    if(pos == -1)
        return head;
    if(pos == 0)
    {
        printf("\nThe element to deleted does not exist\n");
        return head;
    }
    else
    {
        head = delete_pos(head, pos);
        return head;
    }
}

//Function to copy the list
NODE copy(NODE first, NODE second)
{
    NODE temp, cur, prev;
    if(first->link == first)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    cur = first->link;
    temp = create();
    temp->data = cur->data;
    second->link = temp;
    second->data++;
    cur = cur->link;
    prev = second->link;
    while(cur != first)
    {
        temp = create();
        temp->data = cur->data;
        prev->link = temp;
        cur = cur->link;
        prev = prev->link;
        second->data++;
    }
    prev->link = second;
    printf("\nAfter copying");
    display(second);
    return second;
}

//Function to sort the given list
NODE sort(NODE head)
{
    NODE temp;
    if(head->link == head)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    temp = head->link;
    int i, j, tempdata;
    NODE cur, next;
    for(i=1; i<head->data; i++)
    {
        cur = temp;
        next = temp->link;
        for(j=1; j<head->data; j++)
        {
            if(cur->data > next->data)
            {
                tempdata = cur->data;
                cur->data = next->data;
                next->data = tempdata;
            }
            cur = cur->link;
            next = next->link;
        }
    }
    return head;
}

//Function to insert a element in order to sorted list
NODE order(NODE head, int item)
{
    head = sort(head);
    NODE temp, cur, prev;
    temp = create();
    temp->data = item;
    cur = head->link;
    if(temp->data < cur->data)
    {
        temp->link = cur;
        head->link = temp;
        head->data++;
        display(head);
        return head;
    }
    while(temp->data>cur->data && cur != head)
    {
        prev = cur;
        cur = cur->link;
    }
    if(cur == head)
    {
        temp->link = head;
        prev->link = temp;
        head->data++;
        display(head);
        return head;
    }
    else
    {
        temp->link = cur;
        prev->link = temp;
        head->data++;
        display(head);
        return head;
    }
}

void main()
{
    int n, choice, item, key, pos;
    NODE head, head1;
    head = create();
    head->data = 0;
    head1 = create();
    head1->data = 0;
    for(;;)
    {
        printf("\n1)Create and reading a list\n2)Displaying a list\n3)Inserting a node in the first\n4)Insert a node in the rear\n");
        printf("5)Delete a node from front\n6)Delete a node from the rear\n7)Inserting a node to given position\n8)Deleting a node in the given position\n");
        printf("9)Reversing the list\n10)Searching the list for the key\n11)Update the list\n12)Delete the node by it's element\n13)Copying the list\n");
        printf("14)To sort the list\n15)To add a node in order to sorted list\n16)Exit\n");
        printf("Please enter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nPlease enter the length of the list\n");
                    scanf("%d", &n);
                    head = form(head, n);
                    break;

            case 2: display(head);
                    break;

            case 3: printf("\nPlease enter the element to be inserted\n");
                    scanf("%d", &item);
                    head = insert_front(head, item);
                    break;

            case 4: printf("\nPlease enter the element to be inserted\n");
                    scanf("%d", &item);
                    head = insert_rear(head, item);
                    break;

            case 5: head = delete_front(head);
                    break;

            case 6: head = delete_rear(head);
                    break;

            case 7: printf("\nPlease enter the element to be inserted\n");
                    scanf("%d", &item);
                    printf("\nPlease enter the position to be inserted\n");
                    scanf("%d", &pos);
                    head = insert_pos(head, pos, item);
                    break;

            case 8: printf("\nPlease enter the position to be delete\n");
                    scanf("%d", &pos);
                    head = delete_pos(head, pos);
                    break;

            case 9: head = reverse(head);
                   break;

            case 10: printf("\nPlease enter the key to be searched\n");
                    scanf("%d", &key);
                    pos = search(head, key);
                    if(pos == -1)
                        break;
                    if(pos == 0)
                    {
                        printf("\nSearch Unsuccessful\n");
                        break;
                    } 
                    else
                    {
                        printf("\nSearch successful and key found in location %d\n", pos);
                        break;
                    }

            case 11: printf("\nPlease enter the value to be updated\n");
                    scanf("%d", &key);
                    printf("\nPlease enter the updated value\n");
                    scanf("%d", &item);
                    head = update(head, key, item);
                    break;

            case 12: printf("\nPlease enter the key to be deleted\n");
                    scanf("%d", &key);
                    head = delete_key(head, key);
                    break;

            case 13: head1 = copy(head, head1);
                    break;

            case 14: head = sort(head);
                    display(head);
                    break;

            case 15: printf("\nPlease enter the element to be inserted in order to the sorted list\n");
                    scanf("%d", &item);
                    head = order(head, item);
                    break;

            default: exit(0);
        }
    }
}
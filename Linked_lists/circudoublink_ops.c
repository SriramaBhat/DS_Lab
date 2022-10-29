/* Program to demonstrate the operations on a circular doubly linked list with header node*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

typedef struct node * NODE;

//Function to create a single node
NODE create()
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nMemory Error\n");
        exit(0);
    }
    newnode->left = newnode->right = newnode;
    return newnode;
}

//Function to create a list of the required length
NODE form(NODE head, int n)
{
    int i;
    NODE prev, temp;
    printf("\nPlease enter the %d list elements\n", n);
    prev = head;
    for(i=1; i<=n; i++)
    {
        temp = create();
        scanf("%d", &temp->data);
        prev->right = temp;
        temp->left = prev;
        prev = temp;
        temp = NULL;
        head->data++;
    }
    prev->right = head;
    head->left = prev;
    return head;
}

//Function to display the elements of the list
void display(NODE head)
{
    NODE temp;
    if(head->right == head)
    {
        printf("\nThe list is empty\n");
        return;
    }
    temp = head->right;
    printf("\nThe elements of the list are:\n");
    while(temp != head)
    {
        printf("%d\t", temp->data);
        temp = temp->right;
    }
    return;
}

//Function to insert an element to the front of the list
NODE insert_front(NODE head, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    head->data++;
    temp->right = head->right;
    head->right->left = temp;
    temp->left = head;
    head->right = temp;
    display(head);
    return head;
}

//Function to insert an element to the rear of the list
NODE insert_rear(NODE head, int item)
{
    NODE temp, new;
    new = create();
    new->data = item;
    head->data++;
    temp = head->left;
    temp->right = new;
    new->left = temp;
    new->right = head;
    head->left = new;
    display(head);
    return head;
}

//Function to delete a node from the front
NODE delete_front(NODE head)
{
    NODE temp;
    if(head->right == head)
    {
        printf("\nList Empty\n");
        return head;
    }
    head->data--;
    temp = head->right;
    head->right = temp->right;
    temp->right->left = head;
    free(temp);
    display(head);
    return head;
}

//Function to delete the node at the rear
NODE delete_rear(NODE head)
{
    NODE temp;
    if(head->right == head)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    head->data--;
    temp = head->left;
    temp->left->right = head;
    head->left = temp->left;
    free(temp);
    display(head);
    return head;
}

//Function to insert a node into the given position
NODE insert_pos(NODE head, int pos, int item)
{
    int i;
    NODE new, temp;
    new = create();
    new->data = item;
    temp = head->right;
    if(pos<1 || pos>head->data+1)
    {
        printf("\nInvalid position\n");
        return head;
    }
    for(i=1; i<pos; i++)
    {
        temp = temp->right;
    }
    temp->left->right = new;
    new->left = temp->left;
    temp->left = new;
    new->right = temp;
    head->data++;
    display(head);
    return head;
}

//Function to delete a node at the given position
NODE delete_pos(NODE head, int pos)
{
    int i;
    NODE temp;
    temp = head->right;
    if(pos<1 || pos>head->data)
    {
        printf("\nInvalid position\n");
        return head;
    }
    for(i=1; i<pos; i++)
    {
        temp = temp->right;
    }
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    free(temp);
    head->data--;
    display(head);
    return head;
}

//Function to reverse the given string
NODE reverse(NODE head)
{
    NODE temp, prev;
    if(head->right == head)
    {
        printf("\nList Empty\n");
        return head;
    }
    temp = head;
    prev = head->left;
    do
    {
        temp->left = temp->right;
        temp->right = prev;
        prev = temp;
        temp = temp->left;
    }while(temp != head);
    display(head);
    return head;
}

//Function to search the list for the given key
int search(NODE head, int key)
{
    NODE temp;
    int pos=1;
    if (head->right == head)
    {
       printf("\nList Empty\n");
       return -1;
    }
    temp = head->right;
    while(temp != head && temp->data != key)
    {
        temp = temp->right;
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
    int i, pos;
    NODE temp;
    pos = search(head, key);
    if(pos == -1)
    {
        return NULL;
    }
    if(pos == 0)
    {
        printf("\nThe element to be updated does not exist\n");
        return head;
    }
    temp = head->right;
    for(i=1; i<pos; i++)
    {
        temp = temp->right;
    }
    temp->data = item;
    display(head);
    return head;
}

//Function to delete an element by it's value
NODE delete_key(NODE head, int key)
{
    int pos;
    pos = search(head, key);
    if(pos == -1)
        return NULL;
    if(pos == 0)
    {
        printf("\nThe element to be deleted does not exist\n");
        return head;
    }
    head = delete_pos(head, pos);
    return head;
}

//Function to copy the given list
NODE copy(NODE head, NODE head1)
{
    NODE temp, prev, cur;
    if(head->right == head)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    temp = head->right;
    prev = head1;
    while(temp != head)
    {
        cur = create();
        cur->data = temp->data;
        prev->right = cur;
        cur->left = prev;
        prev = cur;
        cur = cur->right;
        temp = temp->right;
        head1->data++;
    }
    prev->right = head1;
    head1->left = prev;
    printf("\nAfter Copying\n");
    display(head1);
    return head1;
}

//Function to sort the given list
NODE sort(NODE head)
{
    if(head->right == head)
    {
        printf("\nList Empty\n");
        return head;
    }
    int i, j, tempdata;
    NODE cur, next;
    for(i=1; i<head->data; i++)
    {
        cur = head->right;
        next = cur->right;
        for(j=1; j<head->data; j++)
        {
            if(cur->data > next->data)
            {
                tempdata = cur->data;
                cur->data = next->data;
                next->data = tempdata;
            }
            cur = cur->right;
            next = next->right;
        }
    }
    return head;
}

//Function to form a ordered list
NODE order(NODE head, int item)
{
    NODE temp, new;
    head = sort(head);
    if(head->right == head)
    {
        return head;
    }
    temp = head->right;
    new = create();
    new->data = item;
    if(item < temp->data)
    {
        temp->left = new;
        new->right = temp;
        new->left = head;
        head->right = new;
        return head;
    }
    while(new->data > temp->data && temp->right != head)
    {
        temp = temp->right;
    }
    if(temp->right == head && temp->data < new->data)
    {
        temp->right = new;
        new->left = temp;
        new->right = head;
        head->left = new;
        return head;
    }
    temp->left->right = new;
    new->left = temp->left;
    new->right = temp;
    temp->left = new;
    return head;
    
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
        printf("\n1)Create and read\n2)Display\n3)Insert front\n4)Insert rear\n");
        printf("5)Delete front\n6)Delete rear\n7)Insert position\n8)Delete position\n");
        printf("9)Reverse\n10)Search for key\n11)Update\n12)Delete by value\n13)Copy\n");
        printf("14)Sort\n15)Ordered list\n16)Exit\n");
        printf("Please enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: printf("\nPlease enter the length of the list to be created\n");
                scanf("%d", &n);
                head = form(head, n);
                break;

        case 2: display(head);
                break;

        case 3: printf("\nEnter the element to be inserted\n");
                scanf("%d", &item);
                head = insert_front(head, item);
                break;
        
        case 4: printf("\nEnter the element to be inserted\n");
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

         case 8: printf("\nPlease enter the position to be deleted\n");
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
                    printf("\nThe search is successful and the key is found in %d location\n", pos);
                    break;
                }

        case 11: printf("\nPlease enter the element to be updated\n");
                scanf("%d", &key);
                printf("\nPlease enter the updated value\n");
                scanf("%d", &item);
                head = update(head, key, item);
                break;

        case 12: printf("\nPlease enter the element to be deleted\n");
                scanf("%d", &key);
                head = delete_key(head, key);
                break;

        case 13: head1 = copy(head, head1);
                break;

        case 14: head = sort(head);
                display(head);
                break;

        case 15: printf("\nPlease enter the element to be inserted in order to a sorted list\n");
                scanf("%d", &item);
                head = order(head, item);
                display(head);
                break;

        default: exit(0);
            break;
        }
    }
}

/* Program to demonstrate the operations on a doubly linked list */

#include<stdio.h>
#include<stdlib.h>

int count=0;

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
    newnode->left = newnode->right = NULL;
    return newnode;
}

//Function to create a list of the required length
NODE form(NODE first, int n)
{
    int i;
    NODE prev, temp;
    printf("\nPlease enter the %d list elements\n", n);
    first = create();
    count = 1;
    scanf("%d", &first->data);
    prev = first;
    for(i=1; i<n; i++)
    {
        temp = create();
        scanf("%d", &temp->data);
        prev->right = temp;
        temp->left = prev;
        prev = temp;
        count++;
    }
    return first;
}

//Function to display the elements of the list
void display(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    temp = first;
    printf("\nThe elements of the list are:\n");
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->right;
    }
    return;
}

//Function to insert an element to the front of the list
NODE insert_front(NODE first, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    count++;
    if(first == NULL)
    {
        display(temp);
        return temp;
    }
    temp->right = first;
    first->left = temp;
    display(temp);
    return temp;
}

//Function to insert an element to the rear of the list
NODE insert_rear(NODE first, int item)
{
    NODE temp, new;
    new = create();
    new->data = item;
    count++;
    if(first == NULL)
    {
        display(new);
        return new;
    }
    temp = first;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    temp->right = new;
    new->left = temp;
    display(first);
    return first;
}

//Function to delete a node from the front
NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    count--;
    if(first->right == NULL)
    {
        printf("\nNode with %d is deleted\n", first->data);
        free(first);
        display(NULL);
        return NULL;
    }
    temp = first;
    first = first->right;
    first->left = NULL;
    free(temp);
    display(first);
    return first;
}

//Function to delete the node at the rear
NODE delete_rear(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    count--;
    if(first->right == NULL)
    {
        printf("\nNode with %d is deleted\n", first->data);
        free(first);
        display(NULL);
        return NULL;
    }
    temp = first;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    temp->left->right = NULL;
    free(temp);
    display(first);
    return first;
}

//Function to insert a node into the given position
NODE insert_pos(NODE first, int pos, int item)
{
    int i;
    NODE new, temp;
    new = create();
    new->data = item;
    temp = first;
    if(pos<1 || pos>count+1)
    {
        printf("\nInvalid position\n");
        return first;
    }
    if(first == NULL)
    {
        display(new);
        return new;
    }
    if(pos == 1)
    {
        first = insert_front(first, item);
        return first;
    }
    if(pos == count+1)
    {
        first = insert_rear(first, item);
        return first;
    }
    for(i=1; i<pos; i++)
    {
        temp = temp->right;
    }
    temp->left->right = new;
    new->left = temp->left;
    temp->left = new;
    new->right = temp;
    count++;
    display(first);
    return first;
}

//Function to delete a node at the given position
NODE delete_pos(NODE first, int pos)
{
    int i;
    NODE temp;
    temp = first;
    if(pos<1 || pos>count)
    {
        printf("\nInvalid position\n");
        return first;
    }
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    if(pos == 1)
    {
        first = delete_front(first);
        return first;
    }
    if(pos == count)
    {
        first = delete_rear(first);
        return first;
    }
    for(i=1; i<pos; i++)
    {
        temp = temp->right;
    }
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    free(temp);
    count--;
    display(first);
    return first;
}

//Function to reverse the given string
NODE reverse(NODE first)
{
    NODE temp, prev;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    temp = first;
    prev = NULL;
    while(temp != NULL)
    {
        temp->left = temp->right;
        temp->right = prev;
        prev = temp;
        temp = temp->left;
    }
    display(prev);
    return prev;
}

//Function to search the list for the given key
int search(NODE first, int key)
{
    NODE temp;
    int pos=1;
    if (first == NULL)
    {
       printf("\nList Empty\n");
       return -1;
    }
    temp = first;
    while(temp != NULL && temp->data != key)
    {
        temp = temp->right;
        pos++;
    }
    if(temp == NULL)
        return 0;
    else
        return pos;
    
}

//Function to update the given list
NODE update(NODE first, int key, int item)
{
    int i, pos;
    NODE temp;
    pos = search(first, key);
    if(pos == -1)
    {
        return NULL;
    }
    if(pos == 0)
    {
        printf("\nThe element to be updated does not exist\n");
        return first;
    }
    temp = first;
    for(i=1; i<pos; i++)
    {
        temp = temp->right;
    }
    temp->data = item;
    display(first);
    return first;
}

//Function to delete an element by it's value
NODE delete_key(NODE first, int key)
{
    int pos;
    pos = search(first, key);
    if(pos == -1)
        return NULL;
    if(pos == 0)
    {
        printf("\nThe element to be deleted does not exist\n");
        return first;
    }
    first = delete_pos(first, pos);
    return first;
}

//Function to copy the given list
NODE copy(NODE first, NODE second)
{
    NODE temp, prev, cur;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    temp = first;
    cur = create();
    cur->data = temp->data;
    second = cur;
    prev = second;
    temp = temp->right;
    prev->right = cur;
    cur->left = prev;
    while(temp != NULL)
    {
        cur = create();
        cur->data = temp->data;
        prev->right = cur;
        cur->left = prev;
        prev = cur;
        cur = cur->right;
        temp = temp->right;
    }
    display(second);
    return second;
}

//Function to sort the given list
NODE sort(NODE first)
{
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    int i, j, tempdata;
    NODE cur, next;
    for(i=1; i<count; i++)
    {
        cur = first;
        next = first->right;
        for(j=1; j<count; j++)
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
    return first;
}

//Function to form a ordered list
NODE order(NODE first, int item)
{
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    NODE temp, new;
    first = sort(first);
    temp = first;
    new = create();
    new->data = item;
    if(item < first->data)
    {
        first->left = new;
        new->right = first;
        return new;
    }
    while(new->data > temp->data && temp->right != NULL)
    {
        temp = temp->right;
    }
    if(temp->right == NULL && temp->data < new->data)
    {
        temp->right = new;
        new->left = temp;
        return first;
    }
    temp->left->right = new;
    new->left = temp->left;
    new->right = temp;
    temp->left = new;
    return first;
    
}

void main()
{
    int n, choice, item, key, pos;
    NODE first, second;
    first = NULL;
    for(;;)
    {
        printf("\n1)Create and read\n2)Display\n3)Insert front\n4)Insert rear\n");
        printf("5)Delete front\n6)Delete rear\n7)Insert position\n8)Delete position\n");
        printf("9)Reverse\n10)Searching for key\n11)Update\n12)Delete value\n13)Copy\n");
        printf("14)Sort\n15)Ordered list\n16)Exit\n");
        printf("Please enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: printf("\nPlease enter the length of the list to be created\n");
                scanf("%d", &n);
                first = form(first, n);
                break;

        case 2: display(first);
                break;

        case 3: printf("\nEnter the element to be inserted\n");
                scanf("%d", &item);
                first = insert_front(first, item);
                break;
        
        case 4: printf("\nEnter the element to be inserted\n");
                scanf("%d", &item);
                first = insert_rear(first, item);
                break;
        
        case 5: first = delete_front(first);
                break;

        case 6: first = delete_rear(first);
                break;

        case 7: printf("\nPlease enter the element to be inserted\n");
                scanf("%d", &item);
                printf("\nPlease enter the position to be inserted\n");
                scanf("%d", &pos);
                first = insert_pos(first, pos, item);
                break;

        case 8: printf("\nPlease enter the position to be deleted\n");
                scanf("%d", &pos);
                first = delete_pos(first, pos);
                break;

        case 9: first = reverse(first);
                break;

        case 10: printf("\nPlease enter the key to be searched\n");
                scanf("%d", &key);
                pos = search(first, key);
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
                first = update(first, key, item);
                break;

        case 12: printf("\nPlease enter the element to be deleted\n");
                scanf("%d", &key);
                first = delete_key(first, key);
                break;

        case 13: second = copy(first, second);
                break;

        case 14: first = sort(first);
                display(first);
                break;

        case 15: printf("\nPlease enter the element to be inserted in order to a sorted list\n");
                scanf("%d", &item);
                first = order(first, item);
                display(first);
                break;

        default: exit(0);
            break;
        }
    }
}

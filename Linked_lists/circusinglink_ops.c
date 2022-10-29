/* Program to demonstrate the operations on a cicular singly linked list */

#include<stdio.h>
#include<stdlib.h>

int count=0; //Keeps count of the total number of nodes

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
NODE form(NODE x, int n)
{
    NODE temp, prev;
    int i;
    printf("\nPlease enter %d list elements\n", n);
    x = create();
    count++;
    scanf("%d", &x->data);
    temp = x;
    prev = temp;
    x = NULL;
    for(i=1; i<n; i++)
    {
        x = create();
        scanf("%d", &x->data);
        prev->link = x;
        prev = x;
        x = NULL;
        count++;
    }
    prev->link = temp;
    return prev;
}

//Function to display the elements of a circular singly linked list
void display(NODE last)
{
    NODE temp;
    temp = last->link;
    if(last == NULL)
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
    while (temp != last->link);
    return;   
}

//Function to insert an element to the beginning of the circular linked list
NODE insert_front(NODE last, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    if(last == NULL)
    {
        display(temp);
        count = 1;
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    count++;
    display(last);
    return last;
}

//Function to insert an element to the rear of the circular linked list
NODE insert_rear(NODE last, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    if(last == NULL)
    {
        display(temp);
        count = 1;
        return temp;
    }
    temp->link = last->link;
    last->link = temp;
    count++;
    display(temp);
    return temp;
}

//Function to delete an element from the beginning of the circular linked list
NODE delete_front(NODE last)
{
    if(last == NULL)
    {
        printf("\nList Empty");
        count = 0;
        return NULL;
    }
    if(last->link == last)
    {
        printf("\nThe node with %d is deleted\n", last->data);
        free(last);
        count = 0;
        return NULL;
    }
    NODE temp;
    temp = last->link;
    last->link = temp->link;
    printf("\nThe node with %d is deleted\n", temp->data);
    free(temp);
    count--;
    display(last);
    return last;
}

//Function to delete an element from the rear of the circular linked list
NODE delete_rear(NODE last)
{
    if(last == NULL)
    {
        printf("\nList Empty\n");
        count = 0;
        return NULL;
    }
    if(last->link == last)
    {
        printf("\nThe node with %d is deleted\n", last->data);
        count = 0;
        free(last);
        return NULL;
    }
    NODE temp;
    temp = last->link;
    while(temp->link != last)
    {
        temp = temp->link;
    }
    temp->link = last->link;
    printf("\nThe node with %d is deleted\n", last->data);
    free(last);
    count--;
    display(temp);
    return temp;
}

//Function to insert an element in the given position
NODE insert_pos(NODE last, int pos, int item)
{
    int i;
    NODE temp, prev, cur;
    temp = create();
    temp->data = item;
    cur = last->link;
    prev = NULL;
    if(pos<1 || pos>count+1)
    {
        printf("\nInvalid Position\n");
        return last;
    }
    if(last == NULL)
    {
        display(temp);
        count = 1;
        return temp;
    }
    if(pos == 1 || pos == count+1)
    {
        temp->link = last->link;
        last->link = temp;
        count++;
        if(pos == 1)
        {
            display(last);
            return last;
        }
        else
        {
            display(temp);
            return temp;
        }
    }
    for(i=1; i<pos; i++)
    {
        prev = cur;
        cur = cur->link;
    }
    temp->link = cur;
    prev->link = temp;
    count++;
    display(last);
    return last;
}

//Function to delete an element in the given position
NODE delete_pos(NODE last, int pos)
{
    int i;
    NODE prev, cur;
    if(pos<1 || pos>count)
    {
        printf("\nInvalid position\n");
        return NULL;
    }
    if(last == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    if(last->link == last)
    {
        printf("\nThe node with %d is deleted\n", last->data);
        return NULL;
    }
    cur = last->link;
    if(pos == 1)
    {
        last->link = cur->link;
        free(cur);
        printf("\nThe node with %d is deleted\n", cur->data);
        count--;
        display(last);
        return last;
    }
    if(pos == count)
    {
        while(cur->link != last)
        {
            cur = cur->link;
        }
        cur->link = last->link;
        free(last);
        count--;
        display(cur);
        return cur;
    }
    for(i=1; i<pos; i++)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = cur->link;
    free(cur);
    count--;
    display(last);
    return last;   
}

//Function to reverse a given list
NODE reverse(NODE last)
{
    if(last == NULL)
    {
        printf("\nList Empty\n");
        return last;
    }
    NODE temp, cur, ptr;
    cur = NULL;
    ptr = last;
    last = last->link;
    ptr->link = NULL;
    while(last != NULL)
    {
        temp = last;
        last = last->link;
        temp->link = cur;
        if(temp->link == NULL)
        {
            ptr = temp;
        }
        cur = temp;
    }
    ptr->link = cur;
    display(ptr);
    return ptr;
}

//Function to search the list for the given key
int search(NODE last, int key)
{
    NODE temp;
    int pos =1;
    if(last == NULL)
    {
        printf("\nList Empty\n");
        return -1;
    }
    temp = last->link;  if(temp->data == key) return 1;
    do
    {
        temp = temp->link;
        pos++;
    } while (temp->data != key && temp != last->link);
    if(temp == last->link)
        return 0;
    else
        return pos;
}

//Function to update the given list
NODE update(NODE last, int key, int item)
{
    NODE temp;
    int pos, i;
    pos = search(last, key);
    if(pos == -1)
        return last;
    if(pos == 0)
    {
        printf("\nThe element to be updated does not exist\n");
        return last;
    }
    temp = last->link;
    for(i=1; i<pos; i++)
    {
        temp = temp->link;
    }
    temp->data = item;
    display(last);
    return last;
}

//Function to delete the node by it's key
NODE delete_key(NODE last, int key)
{
    int pos;
    pos = search(last, key);
    if(pos == -1)
        return last;
    if(pos == 0)
    {
        printf("\nThe element to deleted does not exist\n");
        return last;
    }
    else
    {
        last = delete_pos(last, pos);
        return last;
    }
}

//Function to copy the list
NODE copy(NODE last)
{
    NODE temp, cur, prev, end;
    if(last == NULL)
    {
        printf("\nList Empty\n");
        return last;
    }
    temp = last->link;
    end = create();
    end->data = temp->data;
    cur = end;
    prev = cur;
    temp = temp->link;
    while (temp != last->link)
    {
        end = create();
        end->data = temp->data;
        prev->link = end;
        prev = end;
        end = NULL;
        temp = temp->link;
    }
    prev->link = cur;
    printf("\nAfter copying");   
    display(prev);
    return prev;
}

//Function to sort the given list
NODE sort(NODE last)
{
    NODE temp;
    if(last == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    temp = last->link;
    int i, j, tempdata;
    NODE cur, next;
    for(i=1; i<count; i++)
    {
        cur = temp;
        next = temp->link;
        for(j=1; j<count; j++)
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
    return last;
}

//Function to insert a element in order to sorted list
NODE order(NODE last, int item)
{
    last = sort(last);
    NODE temp, cur, prev;
    temp = create();
    temp->data = item;
    cur = last->link;
    if(temp->data < cur->data)
    {
        temp->link = cur;
        last->link = temp;
        display(last);
        return last;
    }
    do
    {
        prev = cur;
        cur = cur->link;
    }while(temp->data>cur->data && cur != last->link);
    if(cur == last->link)
    {
        temp->link = last->link;
        last->link = temp;
        display(temp);
        return temp;
    }
    else
    {
        temp->link = cur;
        prev->link = temp;
        display(last);
        return last;
    }
} 

/* //Function to delete all the nodes following a negetive node  For a question in pyq
NODE negfoldelete(NODE last)
{
    if(last == NULL)
    {
        return NULL;
    }
    if(last->link == last)
    {
        return last;
    }
    NODE cur, next;
    cur = last->link;
    next = cur->link;
    do
    {
        if(cur->data < 0)
        {
            cur->link = next->link;
            free(next);
        }
        cur = cur->link;
        next = cur->link;
    }while(cur != last->link);
    return last;
}

*/

void main()
{
    int n, choice, item, key, pos;
    NODE last, end;
    last = NULL;
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
                    last = form(last, n);
                    break;

            case 2: display(last);
                    break;

            case 3: printf("\nPlease enter the element to be inserted\n");
                    scanf("%d", &item);
                    last = insert_front(last, item);
                    break;

            case 4: printf("\nPlease enter the element to be inserted\n");
                    scanf("%d", &item);
                    last = insert_rear(last, item);
                    break;

            case 5: last = delete_front(last);
                    break;

            case 6: last = delete_rear(last);
                    break;

            case 7: printf("\nPlease enter the element to be inserted\n");
                    scanf("%d", &item);
                    printf("\nPlease enter the position to be inserted\n");
                    scanf("%d", &pos);
                    last = insert_pos(last, pos, item);
                    break;

            case 8: printf("\nPlease enter the position to be delete\n");
                    scanf("%d", &pos);
                    last = delete_pos(last, pos);
                    break;

            case 9: last = reverse(last);
                   break;

            case 10: printf("\nPlease enter the key to be searched\n");
                    scanf("%d", &key);
                    pos = search(last, key);
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
                    last = update(last, key, item);
                    break;

            case 12: printf("\nPlease enter the key to be deleted\n");
                    scanf("%d", &key);
                    last = delete_key(last, key);
                    break;

            case 13: end = copy(last);
                    break;

            case 14: last = sort(last);
                    display(last);
                    break;

            case 15: printf("\nPlease enter the element to be inserted in order to the sorted list\n");
                    scanf("%d", &item);
                    last = order(last, item);
                    break;

        /*    case 16: last = negfoldelete(last);  *for the question in pyq
                    display(last);
                    break;
        */

            default: exit(0);
        }
    }
}
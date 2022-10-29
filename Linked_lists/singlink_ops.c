/* Program to demonstrate operations on singly linked list */
#include<stdio.h>
#include<stdlib.h>

int count=1;  //Keeps count of the number of nodes, i.e., the length of the singly linked list
struct node  // Declaring the structure for the creation of the nodes 
{
    int info;
    struct node *link;
};

typedef struct node* NODE;

NODE create();
NODE read(NODE, int);
NODE form(NODE, int);  //NODE form(int);
NODE display(NODE);
NODE insert_front(NODE, int);
NODE insert_rear(NODE, int);
NODE delete_front(NODE);
NODE delete_rear(NODE);
NODE insert_pos(NODE, int, int);
NODE delete_pos(NODE, int);
NODE delete_key(NODE, int);
NODE reverse(NODE);
NODE copy(NODE, NODE);
NODE sort(NODE);
NODE order(NODE, int);
NODE update(NODE, int, int);
int search(NODE, int);

int main()
{
    int choice, key, item, n, pos;
    NODE first, second;
    first = NULL;
    second = NULL;
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
            case 1: printf("\nPlease enter the length of the linked list to be created\n");
                    scanf("%d", &n);
                    //printf("\nPlease enter the %d elements of the list\n", n);
                    first = form(first, n); //first = form(n);
                    break;
            
            case 2: first = display(first);
                    break;

            case 3: printf("\nPlease enter the value to be inserted\n");
                    scanf("%d", &item);
                    first = insert_front(first, item);
                    break;

            case 4: printf("\nPlease enter the value to be inserted\n");
                    scanf("%d", &item);
                    first = insert_rear(first, item);
                    break;

            case 5: first = delete_front(first);
                    break;

            case 6: first = delete_rear(first);
                    break;            

            case 7: printf("\nPlease enter the item to be inserted\n");
                    scanf("%d", &item);
                    printf("\nPlease enter the position to be inserted\n");
                    scanf("%d", &pos);
                    first = insert_pos(first, pos, item);
                    break;

            case 8: printf("\nPlease enter the position of the node to be deleted\n");
                    scanf("%d", &pos);
                    first = delete_pos(first, pos);
                    break;

            case 9: first = reverse(first);
                    break;
         
            case 10: printf("\nPlease enter the key\n");
                     scanf("%d", &key);
                     pos = search(first, key);
                     if(pos == 0)
                     {
                         printf("\nSearch Unsuccessful\n");
                     }
                     else
                     {
                         printf("\nSearch Successful and key is found in %d location\n", pos);
                     }
                     break;

            case 11: printf("\nPlease enter the element to be updated\n");
                     scanf("%d", &key);
                     printf("\nEnter the updated value\n");
                     scanf("%d", &item);
                     first = update(first, key, item);
                     break;

            case 12: printf("\nEnter the value to be deleted\n");
                     scanf("%d", &key);
                     first = delete_key(first, key);
                     break;

            case 13: second = copy(first, second);
                     break;

            case 14: first = sort(first);
                     first = display(first);
                     break;

            case 15: printf("\nPlease enter the element to be inserted\n");
                     scanf("%d", &item);
                     first = order(first, item);
                     break;
 
            default: exit(0);
        }
    }
    return 0;
}

//Function for the creation of a single node
NODE create()
{
    NODE first;
    first = (NODE)malloc(sizeof(struct node));
    if(first == NULL)
    {
        printf("\nMemory error\n");
        exit(0);
    }
    else
    {
        first->link = NULL;
        return first;
    }
}

//Function for the creation of the linked list with n number of nodes
//Solving by iteration
NODE form(NODE first, int n)
{
    int i;
    NODE prev, temp;
    printf("\nPlease enter the %d elements of the list\n", n);
    first = create();
    scanf("%d", &first->info);
    prev = first;
    for(i=1; i<n; i++)
    {
        temp = create();
        prev->link = temp;
        prev = temp;
        scanf("%d", &temp->info);
        temp  = temp->link;
        count++;
    }
    return first;
} 

//Solving by recursion
/* NODE form(int n)
{
    if(n == 0)
    {
        return NULL;
    }
    NODE first, prev;
    first = create();
    scanf("%d", &first->info);
    prev = first;
    prev->link = form(n-1);
    return first;
} */

//Function to display the elements of the singly linked list
NODE display(NODE first)
{
    NODE temp;
    temp = first;
    if(first == NULL)
    {
        printf("\nList empty\n");
        return first;
    }
    printf("\nThe elements of the list are\n");
    while(temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->link;
    }
    return first;
}

//Function to insert an element to the front of the list
NODE insert_front(NODE first, int item)
{
    NODE temp;
    temp = create();
    temp->info = item;
    if(first == NULL)
    {
        temp = display(temp);
        count = 1;
        return temp;
    }
    else
    {
        temp->link = first;
        temp = display(temp);
        count++;
        return temp;
    }
}

//Function to insert an element to the rear of the list
NODE insert_rear(NODE first, int item)
{
    NODE temp, ptr;
    temp = create();
    temp->info = item;
    if(first == NULL)
    {
        temp = display(temp);
        count = 1;
    }
    ptr = first;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    first = display(first);
    count++;
    return first;
}

//Function to delete the first element of the linked list
NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nList empty\n");
        return NULL;
    }
    temp = first;
    first = first->link;
    printf("\nThe node with %d is deleted\n", temp->info);
    if(first == NULL)
    {
        printf("\nList empty\n");
    }
    first = display(first);
    free(temp);
    count--;
    return first;
}

//Function to delete only the last node of the linked list
NODE delete_rear(NODE first)
{
    NODE temp1, temp2;
    if(first == NULL)
    {
        printf("\nList empty\n");
        return NULL;
    }
    /* if(first->link == NULL)
    {
        printf("\nNode containing %d is deleted\n", first->info);
        free(first);
        count = 0;
        return NULL;
    } */
    temp1 = first;
    temp2 = NULL;
    while(temp1->link != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->link;
    }
    temp2->link = NULL;
    printf("\nThe node with %d is deleted\n", temp1->info);
    first = display(first);
    free(temp1);
    count--;
    return first;
}

//Function to insert an element at the desired position
NODE insert_pos(NODE first, int pos, int item)
{
    NODE new, prev, cur;
    int i;
    new = create();
    new->info = item;
    if(pos<1 || pos>count+1)
    {
        printf("\nInvallid position\n");
        return first;
    }
    if(pos == 1)
    {
        new->link = first;
        count++;
        return first;
    }
    prev = NULL;
    cur = first;
    i = 1;
    while(i<pos)
    {
        prev = cur;
        cur = cur->link;
        i++;
    }
    new->link = cur;
    prev->link = new;
    count++;
    first = display(first);
    return first;
}

//Function to delete an element from the desired position
NODE delete_pos(NODE first, int pos)
{
    NODE prev, cur;
    int i=1;
    if(pos<1 || pos>count)
    {
        printf("\nInvalid position\n");
        return first;
    }
    if(pos==1)
    {
        first = delete_front(first);
        return first;
    }
    cur = first;
    prev = NULL;
    while(i<pos)
    {
        prev = cur;
        cur = cur->link;
        i++;
    }
    prev->link = cur->link;
    printf("\nThe node with %d is deleted\n", cur->info);
    free(cur);
    count--;
    first = display(first);
    return first;
}

//Function to reverse the given linked list
NODE reverse(NODE first)
{
    NODE temp, cur;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    cur = NULL;
    while(first != NULL)
    {
        temp = first;
        first = first->link;
        temp->link = cur;
        cur = temp;
    }
    cur = display(cur);
    return cur;
}

//Function to search the list for the given key 
int search(NODE first, int key)
{
    NODE temp;
    int pos = 1;
    temp = first;
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return -1;
    }
    while(temp->info != key && temp != NULL)
    {
        temp = temp->link;
        pos++;
    }
    if(temp == NULL)
       return 0;
    else
       return pos;
}

//Function to update the given linked list
NODE update(NODE first, int key, int item)
{
    NODE temp;
    int pos, i;
    temp = first;
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
    for(i=1; i<pos; i++)
        temp = temp->link;
    temp->info = item;
    first = display(first);
    return first;
}

//Function to delete an element based on it's value
NODE delete_key(NODE first, int key)
{
    int pos;
    pos = search(first, key);
    if(pos == -1)
    {
        return NULL;
    }
    if(pos == 0)
    {
        printf("\nThe element ot be deleted is not present\n");
        return first;
    }
    first = delete_pos(first, pos);
    return first;
}

//Function to copy one list to the other
NODE copy(NODE first, NODE second)
{
    NODE temp, cur, prev;
    if(first==NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    cur = first;
    temp = create();
    temp->info = cur->info;
    second = temp;
    cur = cur->link;
    prev = second;
    while(cur != NULL)
    {
        temp = create();
        temp->info = cur->info;
        prev->link = temp;
        cur = cur->link;
        prev = prev->link;
    }
    printf("\nThe copied list is\n");
    second = display(second);
    return second;
}

//Function to sort the given list in ascending order
NODE sort(NODE first)
{
    if(first == NULL)
    {
        printf("\nList Empty\n");
        return NULL;
    }
    int i, j, tempdata, flag=0;
    NODE cur, next;
    for(i=1; i<count; i++)
    {
        cur = first;
        next = first->link;
        for(j=1; j<count; j++)
        {
            if(cur->info > next->info)
            {
                 tempdata = cur->info;
                 cur->info = next->info;
                 next->info = tempdata;
                 flag = 1;
             }
             cur = cur->link;
             next = next->link;
         }
         if(flag==0)
             return first;
    }
    return first;
}

//Function to insert an element in order to a sorted list
NODE order(NODE first, int item)
{
     first = sort(first);
     NODE new, prev, cur;
     new = create();
     new->info = item;
     if(first==NULL)
     {
         new = display(new);
         return new;
     }
     if(item < first->info)
     {
         new->link = first;
         new = display(new);
         return new;
     }
     prev = NULL;
     cur = first;
     while(item > cur->info && cur->link!= NULL)
     {
          prev = cur;
          cur = cur->link;
     }
  if(cur->link == NULL && item > cur->info)
     {
          cur->link = new;
     }
     else 
     {
           prev->link = new;
           new->link = cur;
     }
     count++;
     first = display(first);
     return first;
}

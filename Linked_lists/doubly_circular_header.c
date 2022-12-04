/**************************

                            doubly  circular header 
           delte rear after inserting in order 
           delete key in when key is in middle 

***************************/



# include<stdio.h>
#include<stdlib.h>

     int count=0;
     int count1=0;
     
   struct node{
     
                struct node*left;
                int info;
                struct node*right;
     
     
     
     };
     
     
             typedef struct node*NODE;
           
       NODE create()
       { 
              NODE newnode;
           
               newnode=(NODE)malloc(sizeof(struct node));
           
              if(newnode==NULL)
           {
               printf("\nmemoru error\n");
               exit(0);
           }
           
               newnode->left=newnode->right=newnode;
                return newnode;
           
       }
         
         
         
       void display(NODE head)
       {
           NODE temp;
           
           if(head->right==head)
           {
               printf("\nlist empty\n");
               return;
           }
               temp=head->right;
             printf(" \nthe elements are\n");
             
             while(temp!=head)
             {
                 printf("%d\t",temp->info);
                 temp=temp->right;
             }
                 return ;
                
       }
       
       
       
       NODE insert_rear(NODE head,int item)
       {
           
           NODE temp,new;
           
           new=create();
           new->info=item;
           count++;
           temp=head->left;
           temp->right=new;
           new->left=temp;
           new->right=head;
           head->left=new;
           display(head);
           return head;
           
           
       }
      
      
        
         
           NODE insert_front(NODE head,int item)
         {
             NODE temp,new;
             new=create();
             new->info=item;
             count++;
             temp=head->right;
             head->right=new;
             new->left=head;
             new->right=temp;
             temp->left=new;
            // temp->left=new;
             display(head);
             return(head);
             
             
         }
         
         
         
         
         
         
         
         
         
         
         
         NODE delete_front(NODE head)
         {
             NODE temp;
             
             if(head->right==head)
             {
                 printf("\nlist empty");
                 return NULL;
             }
             count--;
             temp=head->right;
             head->right=temp->right;
             
             
             temp->right->left=head;
             free(temp);
             display(head);
             return head;
             
         }
         
         
         NODE delete_rear(NODE head)
         {
             NODE temp;
             
             
             
             if(head->right==head)
             {
                 printf("\nlist empty");
                 return NULL;
             }
             count--;
             
               
               temp=head->left;
               temp->left->right=head;
               head->left=temp->left;
               free(temp);                
               return head;
         }
         
             
          NODE insert_pos(NODE head,int pos,int item)
          {
              NODE temp=head->right;
              NODE new;
              new=create();
              new->info=item;
              if(pos<1||pos>count+1)
              {
                  printf("invalid\n");
                  return head;
              }
              
              if(pos==1)
              {
                  head=insert_front(head,item);
                  return head;
                  
              }
              if(pos==count+1)
              {
                  head=insert_rear(head,item);
                  return head;
              }
              
              
              for(int i =1;i<pos;i++)
              {
                  temp=temp->right;
              }
              
              
              temp->left->right=new;
              new->left=temp->left;
              temp->left=new;
              new->right=temp;
              count++;
              display(head);
              return(head);
              
          }
         
             NODE delete_pos(NODE head,int pos)
             {
                 
                 NODE temp=head->right;
              
              if(pos<1 || pos>count+1)
              {
                  printf("invalid pos\n");
                    return head;
              }
              
              
                   for(int i =1;i<pos;i++)
                  {
                      temp=temp->right;
                      
                   }
                      temp->left->right=temp->right;
                      temp->right->left=temp->left;
                      free(temp);
                      display(head);
                      return head;
                      
              
                 
                 
             }
             
             
             
             NODE reverse(NODE head)
             {
                  NODE temp,prev;
                  
             if(head->right==head)
             {
                 printf("\nlist empty");
                 return NULL;
             }
             
                 temp=head;
                 prev=head->left;
                 do{
                     temp->left=temp->right;
                     temp->right=prev;
                     prev=temp;
                     temp=temp->left;
                     
                 }while(temp!=head);
                     display(head);
                     return(head);
                     
             }
      
            NODE copy(NODE head,NODE head1)
            {
                
                 NODE temp, prev, cur;
             if(head->right == head)
                    {
                          printf("\nList Empty\n");
                             return NULL;
                     }
                          
                          
                          temp=head->right;
                          prev=head1;
                    while(temp!=head)
                    {
                        cur=create();
                        cur->info=temp->info;
                        prev->right=cur;
                        cur->left=prev;
                        prev=cur;
                        cur=cur->right;
                        temp=temp->right;
                        count1++;
                    }
                    prev->right=head1;
                    head1->left=prev;
                    
                     display(head1);
                     return head1;
                        
                
            }
                  /*(NODE head,int item )
                    {
                        
                        NODE temp,new;
                        
                        
                        if(head->right == head)
                    {
                          printf("\nList Empty\n");
                             return NULL;
                     }
                         
                         temp=head->right; 
                         new=create();
                         new->info=item;
                         
                         
                         if(new->info<temp->info)
                         {
                            
                               head->right=new;
                               new->left=head;
                               new->right=temp;
                               temp->left=new;
                         }
                         
                         while(  new->info>temp->info && temp->right!=head )
                         {
                             
                               temp=temp->right;
                               
                             
                         }
                               if(temp->right==head && temp->info<new->info)
                               {
                                   temp->right=new;
                                   new->left=temp;
                                   new->right=head;
                                   return head;
                                   
                                   }
                         
                                     temp->left->right=new;
                                     new->left=temp->left;
                                     new->right=temp;
                                     temp->left=new;
                                     display(head);
                                     return head;
                         
                         
                           
                        
                    } */
                    
                    
                    NODE order(NODE head,int item )
                    {
                        
                        NODE temp,new;                      
                         temp=head->right; 
                         new=create();
                         new->info=item;
                         
                         
                         if(new->info<temp->info || head->right == head)
                         {
                            
                               head->right=new;
                               new->left=head;
                               new->right=temp;
                               temp->left=new;
                         }
                         
                         while(  new->info>temp->info && temp->right!=head )
                         {
                             
                               temp=temp->right;
                               
                             
                         }
                               if(temp->right==head && temp->info<new->info)
                               {
                                   temp->right=new;
                                   new->left=temp;
                                   new->right=head;   
                                   head->left = new;
                                   return head;
                                   
                                   }
                         
                                     temp->left->right=new;
                                     new->left=temp->left;
                                     new->right=temp;
                                     temp->left=new;
                                     return head;    
                    }
                    
                    
                    
                    
    
                   NODE del_key(NODE head,int key)
                     {
                         NODE temp;
                         
                        if(head->right == head)
                    {
                          printf("\nList Empty\n");
                             return NULL;
                     }
                         temp=head->right;
                         if(temp->info==key)
                         {
                             head->right=temp->right;
                             
                             free(temp);
                             return head;
                         }
                         
                         while(temp->info!=key && temp->right!=head)
                         {
                             
                             
                             temp=temp->right;
                             
                             
                             
                             
                         }
                         
                         if(temp->right==head && temp->info!=key)
                         {
                                printf(" key does not exist\n");
                                
                         }
                         
                         if(temp->right==head->left && temp->info==key)
                         {
                             
                           
                             temp->left->right=head;
                               head->right=temp->left;
                             
                             free(temp);
                             return head;
                         }
                         
                         temp->left->right=temp->right;
                         temp->right->left=temp->left;
                         free(temp);
                         display(head);
                         return head;
                         
                     } 
                     
                     
                     
                     
                
                     
           
                                
                                int  search(NODE head,int key)
                              {
                                         NODE temp;
                                        int pos=1;
                                           if(head->right==head)
                                     {
                                              printf(" list emtpy\n");
                                            return -1;
                                     }
                                                 temp = head->right;
                                                while(temp->info != key && temp != head)
                                          {
                                              temp = temp->right;
                                             pos++;
                                           }
                                               if(temp->right == head)
                                          {
                                                return 0;
                                          }
                                                 else
                                                return pos;
                                               }
                                
                                
                            
                                           
                                NODE update(NODE head,int key,int item)
                                {
                                     NODE temp;
                                     temp = head->right;
                                      while(temp->info != key && temp!=head)
                                      {
                                          temp = temp->right;
         
                                      }
                                             if(temp == head && temp->info!=key)
                                              {
                                                   printf("ele dont exist");
                                                   return head;   
                                               }
                                                     temp->info = item;
                                                      display(head);
                                                      return head;
                                    }  

           
      void main()
      {
          int item, choice,pos,key;
          NODE head,head1;
          head = create();
          head1=create();
          for(;;)
          {
          
          printf("\n1)insert_rear\n2)display\n3)insert_front\n4)delete_front\n5)delete_rear\n6)insert_pos\n7)delete_pos\n8)reverse\n9)copy\n10)order\n11)del_key\n12)search\n13)update\n");
          printf(" \nenter your choice\n");
          scanf("%d",&choice);
          
          switch(choice)  
          {
              case 1:
                      printf("\nenter the item to insert\n");
                      scanf("%d",&item);
                      head=insert_rear(head,item);
                      break;
              case 2:
                       display(head);
                       break;
             case 3 :
                     printf("\nenter the item to insert\n");
                      scanf("%d",&item);
                      head=insert_front(head,item);
                      break;
               case 4 :
                        head=delete_front(head);
                        break;
                case 5 :
                        
                        head=delete_rear(head);
                        display(head);
                        break;
                 case 6 :    
                           
                      printf("\nenter the item to insert\n");
                      scanf("%d",&item);
                      
                      printf("\nenter the pos  to insert\n");
                      scanf("%d",&pos);
                     head=insert_pos(head, pos, item);
                       break;
                   case 7 :
                       printf(" enter the pos to delete\n");
                        scanf("%d",&pos);
                        head=delete_pos(head,pos);
                        break;
                 case 8 :
                         head=reverse(head);
                         break;
                         
                         
                case 9 :
                            head1=copy(head,head1);
                              break;
                              
                              
                case 10 :
                             printf("enter the element  to insert in order\n");
                             scanf("%d",&item);
                             head=order(head,item);
                             display(head);
                             break;
                             
                 case 11:
                             printf(" enter the element to delete\n");
                             scanf("%d",&key);
                             head=del_key(head,key);
                             
                             break;
                             
                             
                case 12 :
                              printf("enter the ele to be search\n");
                     scanf("%d",&key);
                     pos = search(head,key);
                    
                     if(pos == -1)
                       
                          break;
                       
                       if(pos == 0)
                         {
                             printf("search is unsucessfull\n");
                             break;
                         }
                         else
                         {
                           printf("search is sucessfull and in pos %d\n",pos);
                            break;
                         }
                         
               case 13 :
                     printf("enter the key\n ");
                     scanf("%d",&key);
                     printf("enter the val to update\n");
                      scanf("%d",&item);
                      head = update(head,key,item);
                     
                       break;
                         
                       
        default : exit(0);
            break;
                     
         }
           
        }
      }

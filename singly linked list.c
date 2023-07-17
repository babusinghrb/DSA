#include<stdio.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head;
struct node* insert_at_beg(struct node *);
struct node* insert_at_end(struct node *);
struct node* delete_at_beg(struct node *);
struct node* delete_at_end(struct node *);
void display(struct node *);
void search_node(struct node *head, int);
int count_nodes(struct node *);
struct node * insert_at_pos(struct node*, int);
struct node *temp,*temp1,*newnode;
main()
{
int ch,c,pos,d;
head=NULL;
   while(1)
   {
     printf("1--insert at beginning\n");
     printf("2--insert at end\n");
     printf("3--delete from beginning\n");
     printf("4--delete from end\n");
     printf("5--display linked list\n");
     printf("6--count of nodes\n");
     printf("7--insert a node at a position\n");
     printf("8--search for a node\n");
     printf("9--bubble sort\n");
     printf("10--exit\n");

     printf("enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:newnode=(struct node*)malloc(sizeof(struct node));
             printf("enter data\n");
             scanf("%d",&newnode->data);
             head=insert_at_beg(newnode);
             break;
    case 2: newnode=(struct node*)malloc(sizeof(struct node));
             printf("enter data\n");
             scanf("%d",&newnode->data);
             head=insert_at_end(newnode);
             break;
    case 3: if(head==NULL)
             printf("linked list is empty---cant delete\n");
             else
             {
                head=delete_at_beg(head);
             }
             break;
    case 4: if(head==NULL)
             printf("linked list is empty---cant delete\n");
             else
             {
                head=delete_at_end(head);
             }
             break;
    case 5: display(head);break;
    case 6: c=count_nodes(head);
                   printf("no of nodes=%d\n",c);
                   break;
    case 7: printf("enter position\n");
                   scanf("%d",&pos);
                    if(pos<1 ||pos>count_nodes(head)+1)
                        printf("invalid pos\n");
                    else
                    {
                        newnode=(struct node*)malloc(sizeof(struct node));
                       printf("enter data\n");
                       scanf("%d",&newnode->data);
                        head=insert_at_pos(newnode,pos);
                    }
                    break;
    case 8: if(head==NULL)
            {
                printf("linked list is empty\n");
            }
            else
            {
                printf("enter the data\n");
                scanf("%d",&d);
                search_node(head,d);
            }break;
    case 9: bubbleSort(head);
    case 10: exit(0);break;

    default: printf("Invalid choice\n");
     }
   }
}

void bubbleSort(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);

    temp=head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void swap(struct node* a, struct node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


struct node* insert_at_beg(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     newnode->next=head;
     head=newnode;
     return(head);
   }
}


struct node* insert_at_end(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;

     }
     temp->next=newnode;
        newnode->next=NULL;
        return(head);

   }
}

void display(struct node *head)
{
   if(head==NULL)
   {
     printf("the linkded list is empty\n");
   }
   else
   {
      temp=head;
      while(temp!=NULL)
      {
         printf("%d->",temp->data);
         temp=temp->next;
      }
      printf("\n");
   }
}

struct node* delete_at_beg(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("node deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           head=head->next;
           printf("node deleted=%d\n",temp->data);
           free(temp);
           return(head);

       }
    }

}
struct node* delete_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("node deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           //temp1=head->next;
           while(temp->next!=NULL)
           {
               temp1=temp;
               temp=temp->next;
           }
           printf("node deleted=%d\n",temp->data);
           free(temp);
           temp1->next=NULL;
           return(head);

       }
    }

}

int count_nodes(struct node *head)
{
    int count=0;
    if(head==NULL)
       return(count);
    else
    {

        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return(count);
    }
}

struct node * insert_at_pos(struct node *newnode,int pos)
{
    int p;
    if(pos==1)
        head=insert_at_beg(newnode);
    else
    {
        p=1;
        temp=head;
        while(p!=pos)
        {
            temp1=temp;
            temp=temp->next;
            p++;
        }
        temp1->next=newnode;
        newnode->next=temp;
    }
    return(head);
}
void search_node(struct node *head, int d)
{
    int found=0;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==d)
        {
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==0)
        printf("node not found\n");
    else
    printf("node found\n");
}

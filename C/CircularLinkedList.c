#include<stdio.h>
#include<stdlib.h>

struct node {
struct node * next;
int data;
};

void createnode(struct node ** tail)
{
int data;
struct node *newnode=(struct node *)malloc(sizeof(struct node));
if((*tail)==NULL)
{
printf("enter the data");
scanf("%d",&newnode->data);
(*tail)=newnode;
(*tail)->next=newnode;


}
else
printf("already created");

}

void enteratfront(struct node **tail)
{
int data;
if((*tail)==NULL)
printf("empty");
else
{

struct node *newnode=(struct node *)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&newnode->data);

newnode->next=(*tail)->next;
(*tail)->next=newnode;

}
}

void enteratend(struct node **tail)
{
int data;
if((*tail)==NULL)
printf("empty");

else
{

struct node *newnode=(struct node *)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&newnode->data);
newnode->next=(*tail)->next;
(*tail)->next=newnode;

(*tail)=newnode;

}
}

void enteratpos(struct node **tail,int pos)
{
int data;
int l=length(tail);

if((*tail)==NULL)
printf("empty");
else
{

struct node *newnode=(struct node *)malloc(sizeof(struct node));
int i=1;
printf("enter the data");
scanf("%d",&newnode->data);
printf("enter the pos");
scanf("%d",&pos);
if(pos==1)
enteratfront(tail);
else if(pos==(l+1))
enteratend(tail);
else
{
struct node * temp=(*tail)->next;

while( i < pos-1)
{
temp=temp->next;
i++;
}
newnode->next=temp->next;
temp->next=newnode;

}

}
}

void dltfront(struct node **tail)
{
struct node * temp=(*tail)->next;
if((*tail)==NULL)
printf("empty");
else if(temp->next==temp)
{
(*tail)=NULL;
free(temp);
}
else
{

(*tail)->next=temp->next;
free(temp);

}
}


void dltend(struct node **tail)
{
struct node * temp=(*tail)->next;
struct node * seclastnode=(*tail)->next;
if((*tail)==NULL)
printf("empty");
else if(temp->next==temp)
{
(*tail)=NULL;
free(temp);
}
else
{


while(temp->next!=(*tail)->next)
{
seclastnode=temp;
temp=temp->next;
}



seclastnode->next=(*tail)->next;
(*tail)=seclastnode;
free(temp);


}
}



void dltpos(struct node **tail,int pos)
{

printf("enter the pos");
scanf("%d",&pos);
int i=1;
int l=length(tail);
if((*tail)==NULL)
printf("empty");
else if(pos==1)
dltfront(tail);
else if (pos==l)
{
dltend(tail);

}
else
{
struct node * todlt=(*tail)->next;
struct node *prevnode=(*tail)->next;




while (todlt != NULL && i < pos) {
prevnode = todlt;
todlt = todlt->next;
i++;
    }
prevnode->next = todlt->next;

    free(todlt);
}





}

int length (struct node * tail)
{
int c=0;
if(tail==NULL)
printf("empty\n");
else
{
struct node * temp=tail->next;

do
{ c++;

temp=temp->next;

}while(temp!=tail->next);
}
return c;
}



void display(struct node * tail)
{

if(tail==NULL)
printf("empty\n");
else
{
struct node * temp=tail->next;

do
{
printf("%d->",temp->data);
temp=temp->next;

}while(temp!=tail->next);
}

}



int main()
{
struct node * tail=(struct node *)malloc(sizeof(struct node));
tail=NULL;

int data,choice,pos;



    while(1)
    {   
        printf("case 1:createnode");
         printf("case 2:insertatfront");
         printf("case 3:insertatend");
         printf("case 4:insertatpos");
         printf("case 5:dltfromfront");
         printf("case 6:dltfromend");
         printf("case 7:dltfrompos");
         printf("case 8:exit");
         printf("enter the choice:");
         scanf("%d",&choice);
        switch (choice)


        {


        case 1:

             createnode(&tail);
             break;

        case 2:
            {
               
             enteratfront(&tail);
               display(tail);
               break;

            }


        case 3:
            {
               
               enteratend(&tail);
                display(tail);
                break;
            }
       case 4:
            {
             
             enteratpos(&tail,pos);
               display(tail);
              break;
            }

        case 5:
            {

                dltfront(&tail);
                 display(tail);
                break;
            }
        case 6:
            {

                dltend(&tail);
                display(tail);
                break;
            }

        case 7:
            {
               
                dltpos(&tail,pos);
                 display(tail);
                break;
            }
           
        case 8:
            {
               exit(0);
               break;
            }
           
           
        }
    }
}
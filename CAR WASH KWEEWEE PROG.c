#include <stdio.h>
#include <stdlib.h>

struct node
{
    int lic; //Last 4 digits of license plate
    int wax;
    int time;
    struct node*next;
};

struct node* insert(struct node*Front, int ID, int wax_check, int mins)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->lic= ID;
    newnode->wax=wax_check;
    newnode->time=mins;
    struct node*ptr=Front;
    if(Front==NULL)
    {
        Front=newnode;
        Front->next=NULL;
    }
    else
    {
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
      ptr->next=newnode;
      newnode->next=NULL;
    }
    return Front;
}

struct node* deletion(struct node*ptr, struct node*Front)
{
    Front= ptr->next;
    free(ptr);
    return Front;
}

void display(struct node*ptr)
{

    while(ptr->next!=NULL)
    {
        printf("%d\n",ptr->lic);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->lic);
}


void start_time(struct node* ptr)
{
    int start_time=0;
    while(ptr->next!=NULL)
    {
        start_time= start_time + ptr->time;
        ptr=ptr->next;
    }
    printf("The start time for %d is %d\n",ptr->lic,start_time);
}

void end_time(struct node * ptr)
{
    int end_time=0;
    while(ptr->next!=NULL)
    {
        end_time= end_time + ptr->time;
        ptr=ptr->next;
    }
    end_time= end_time + ptr->time;
    printf("The end time for %d is %d\n",ptr->lic,end_time);
}

void cars_ahead(struct node * ptr)
{
    int count=0;
    while(ptr->next!=NULL)
    {
        count = count + 1;
        ptr = ptr->next;
    }
    printf("Number of cars ahead of %d is %d\n",ptr->lic,count);
}

void start_id(struct node* Front,int ID)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=Front;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=Front;
    int flag=0;
    int start_time=0;
    do
    {
        if(temp->lic==ID)
        {
            
            while(ptr->lic!=temp->lic)
            {
                if(ptr->wax==1)
                {
                    start_time= start_time + ptr->time;
                    ptr=ptr->next;
                }
                else if(ptr->wax==0)
                {
                    start_time=start_time+10;
                    ptr=ptr->next;
                }
            }
            printf("The start time for %d is %d\n",ptr->lic,start_time);
            flag=1;
        }
        else
        {
            temp=temp->next;
        }
    }while(flag!=1);
}

void end_id(struct node* Front,struct node* ptr, int ID)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=Front;
    int flag=0;
    int end_time=0;
    do
    {
        if(temp->lic==ID)
        {
            while(ptr->lic!=temp->lic)
            {
                end_time= end_time + ptr->time;
                ptr=ptr->next;
            }
            end_time= end_time + ptr->time;
            printf("The end time for %d is %d\n",ptr->lic,end_time);
            flag=1;
        }
        else
        {
            temp=temp->next;
        }
    }while(flag!=1);
}

int main()
{
    int ID, wax_check, mins;
    int choice;
    struct node*Front=(struct node* )malloc(sizeof(struct node));
    Front=NULL;

    Front=insert(Front, 1234, 1, 14);
    Front=insert(Front, 5678, 0, 10);
    Front=insert(Front, 911, 1, 14);
    Front=insert(Front, 6789,0 , 10);
    Front=insert(Front, 666, 1, 14);
    display(Front);
    start_time(Front);
    end_time(Front);
    cars_ahead(Front);
    start_id(Front,6789);
    end_id(Front,Front,6789);
}

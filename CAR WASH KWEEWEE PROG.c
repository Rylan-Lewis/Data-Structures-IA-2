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
    printf("The start time for %d is %d",ptr->lic,start_time);
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
    printf("The end time for %d is %d",ptr->lic,end_time);
}

void cars_ahead(struct node * ptr)
{
    int count=0;
    while(ptr->next!=NULL)
    {
        count = count + 1;
        ptr = ptr->next;
    }
    printf("Number of cars ahead of %d is %d",ptr->lic,count);
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
    Front=insert(Front, 6789, 1, 10);
    Front=insert(Front, 666, 1, 14);
    display(Front);
    start_time(Front);
    end_time(Front);
    cars_ahead(Front);
}

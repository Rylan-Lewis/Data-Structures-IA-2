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

int main()
{
    int ID, wax_check, mins;
    int choice;
    struct node*Front=(struct node* )malloc(sizeof(struct node));
    Front=NULL;

    Front=insert(Front, 1234, 1, 69);
    Front=insert(Front, 5678, 0, 67);
    Front=insert(Front, 911, 1, 42);
    display(Front);
    Front=deletion(Front, Front);
    display(Front);
}

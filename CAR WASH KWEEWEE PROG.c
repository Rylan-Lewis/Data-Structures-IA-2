#include <stdio.h>
#include <stdlib.h>

struct node
{
    int lic; //Last 4 digits of license plate
    int wax;
    int time;
    int rate;
    struct node* next;
};

struct node* enqueue(struct node*Front, int ID, int wax_check, int mins)
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
    
    if(newnode->wax==0)
    {
        printf("\nLicense Plate number %d added to queue for CAR WASH!!\n\n",ID);
    }
    else
    {
        printf("\nLicense Plate number %d added to queue for CAR WASH AND WAX!!\n\n",ID);
    }
    return Front;
}

struct node* dequeue(struct node*Front)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=Front;
    printf("The Car with license number %d is removed from queue.",ptr->lic);
    Front= ptr->next;
    free(ptr);
    return Front;
}

void display(struct node*ptr)
{
    printf("\n\n-----------------------------------------------------------------\n\n");
    if(ptr!=NULL)
    {
        while(ptr->next!=NULL)
        {
            if(ptr->wax==0)
            {
                printf("%d - WASH ONLY - 10 minutes\n",ptr->lic);
            }
            else
            {
                printf("%d - WASH AND WAX - 14 minutes\n",ptr->lic);
            }
            ptr=ptr->next;
        }
        if(ptr->wax==0)
        {
            printf("%d - WASH ONLY - 10 minutes\n",ptr->lic);
        }
        else
        {
            printf("%d - WASH AND WAX - 14 minutes\n",ptr->lic);
        }
    }
    else
    {
        printf("There are no customers in queue.");
    }
    printf("\n-----------------------------------------------------------------\n\n");
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

void cars_ahead(struct node * Front,int ID)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=Front;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=Front;
    int count=0;
    int flag=0;
    do
    {
        if(temp->lic==ID)
        {
            
            while(ptr->lic!=temp->lic)
            {
                count = count + 1;
                ptr = ptr->next;
            }
            printf("There are %d cars ahead of License Plate Number %d\n",count,temp->lic);
            flag=1;
        }
        else
        {
            temp=temp->next;
        }
    }while(flag!=1);
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
                if(temp->wax==1)
                {
                    start_time= start_time + ptr->time;
                    ptr=ptr->next;
                }
                else if(temp->wax==0)
                {
                    start_time=start_time+10;
                    ptr=ptr->next;
                }
            }
            printf("\n\nThe start time for %d is %d\n",ptr->lic,start_time);
            flag=1;
        }
        else
        {
            temp=temp->next;
        }
    }while(flag!=1);
}

void end_id(struct node* Front,int ID)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=Front;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=Front;
    int flag=0;
    int end_time=0;
    do
    {
        if(temp->lic==ID)
        {
            while(ptr->lic!=temp->lic)
            {
                if(temp->wax==1)
                {
                    end_time= end_time + ptr->time;
                    ptr=ptr->next;
                }
                else if(temp->wax==0)
                {
                    end_time=end_time+10;
                    ptr=ptr->next;
                }
            }
            end_time= end_time + ptr->time;
            printf("\n\nThe end time for %d is %d\n",ptr->lic,end_time);
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
    int choice,choice2;
    struct node*Front=(struct node* )malloc(sizeof(struct node));
    Front=NULL;
    int flag=0;
    printf("\n ------------------- WELCOME TO MYR CAR WASH STATION ------------------- \n");
    
    do
    {
        printf("\n1) ADD A CUSTOMER TO QUEUE\n2) REMOVE A CUSTOMER FROM QUEUE\n3) CHECK START TIME FOR A CUSTOMER\n4) CHECK END TIME FOR A CUSTOMER\n5) PRINT TICKET FOR CUSTOMER\n6) DISPLAY THE QUEUE\n7) CHECK NUMBER OF CARS AHEAD\n");
        
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        printf("\n\n----------------------------------------------------------------\n");
        switch(choice)
        {
            case 1:
                printf("Enter license plate number of your car(only last four digits): ");
                scanf("%d",&ID);
                
                printf("\n\n1) Wash Only-----> 10 minutes\n2) Wash and Wax -----> 14 minutes\n\n");
                int flag2=0;
                while(flag2==0)
                {
                    printf("Enter your choice: ");
                    scanf("%d",&choice2);
                    if(choice2==1)
                    {
                        Front = enqueue(Front,ID,0,10);
                        flag2=1;
                    }
                    else if(choice2==2)
                    {
                        Front = enqueue(Front,ID,1,14);
                        flag2=1;
                    }
                    else
                    {
                        printf("\n\nThere are only two options!\n\n");
                    }
                }
                break;
            
            case 2:
                Front = dequeue(Front);
                break;
                
            case 3:
                printf("\n\nEnter license plate number (last 4 digits): ");
                scanf("%d",&ID);
                start_id(Front,ID);
                break;

            case 4:
                printf("\n\nEnter license plate number (last 4 digits): ");
                scanf("%d",&ID);
                end_id(Front,ID);
                break;
                
            case 5:
                
                break;
            
            case 6:
                display(Front);
                break;
            
            case 7:
                printf("Enter License Plate number: ");
                scanf("%d",&ID);
                cars_ahead(Front,ID);
                break;
                
            default:
                printf("This option doesn't exist!!!");
                break;
        }
    }while(flag==0);
}

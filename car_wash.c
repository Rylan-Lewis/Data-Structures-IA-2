#include <stdio.h>
#include <stdlib.h>

struct node
{
    int lic; 
    int wax;
    int time;
    int rate;
    struct node* next;
};


//Add Customer to queue
struct node* enqueue(struct node*Front, int ID, int wax_check, int mins, int cost)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->lic= ID;
    newnode->wax=wax_check;
    newnode->time=mins;
    newnode -> rate = cost;

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
    
    printf("\n\n-----------------------------------------------------------------\n\n");
    if(newnode->wax==0)
    {
        printf("\nLicense Plate number %d added to queue for CAR WASH!!\n\n",ID);
    }
    else
    {
        printf("\nLicense Plate number %d added to queue for CAR WASH AND WAX!!\n\n",ID);
    }
    printf("\n\n-----------------------------------------------------------------\n\n");
    return Front;
}

//Remove customer from queue
struct node* dequeue(struct node*Front)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=Front;

    printf("\n\n-----------------------------------------------------------------\n\n");
    if(ptr!=NULL)
    {
        printf("The Car with license number %d is removed from queue.",ptr->lic);
        Front= ptr->next;
        free(ptr);
    }
    else
    {
        printf("There are no customers in this queue!!!");
    }
    printf("\n\n-----------------------------------------------------------------\n\n");
    return Front;
}

//Display queue
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
        printf("There are no customers in queue.\n");
    }
    printf("\n-----------------------------------------------------------------\n\n");
}


//Displays number of cars ahead
void cars_ahead(struct node * Front)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=Front;
    int count=0;
    int flag=0;

    printf("\n\n-----------------------------------------------------------------\n\n");
    if(Front==NULL)
    {
        printf("There are no cars in queue");
    }
    else
    {
        while(ptr!=NULL)
        {
            count = count +1;
            ptr = ptr -> next;
        }
        printf("There are %d cars in queue",count);
    }
    printf("\n\n-----------------------------------------------------------------\n\n");
}

//Displays start time for a customer
void start_id(struct node* Front,int ID)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=Front;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=Front;
    int flag=0;
    int start_time=0;

    printf("\n\n-----------------------------------------------------------------\n\n");
    do
    {
        if(temp->lic==ID)
        {
            while(ptr->lic!=temp->lic)
            {
                start_time = start_time + ptr ->time;
                ptr=ptr->next;
            }
            printf("\n\nThe start time for %d is %d\n",ptr->lic,start_time);
            flag=1;
        }
        else
        {
            temp=temp->next;
        }
    }while(flag!=1);

    if(temp==NULL)
    {
        printf("This ID number is not present in the queue");
    }
    printf("\n\n-----------------------------------------------------------------\n\n");

}

//Displays end time for a customer
void end_id(struct node* Front,int ID)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=Front;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=Front;
    int flag=0;
    int end_time=0;

    printf("\n\n-----------------------------------------------------------------\n\n");
    do
    {
        if(temp->lic==ID)
        {
            while(ptr->lic!=temp->lic)
            {
                end_time=end_time + ptr->time;
                ptr=ptr->next;
            }
            end_time= end_time + ptr->time;

            printf("\n\nThe end time for %d is %d minutes\n",ptr->lic,end_time);
            flag=1;
        }
        else
        {
            temp=temp->next;
        }
    }while(flag!=1);

    if(temp==NULL)
    {
        printf("This ID number doesnt exist in the queue");
    }
    printf("\n\n-----------------------------------------------------------------\n\n");
}

void print(struct node*Front,int ID)
{
    struct node*ptr=Front;
    int start_time=0, end_time=0;
    while(ptr->lic!=ID)
    {
       ptr = ptr->next;
       start_time= start_time+ptr ->time;
       end_time= end_time+ptr->time;
    }
    end_time=end_time+ptr->time;

    printf("\n\n-----------------------------------------------------------------\n\n");
    printf("| The License Number is: %d\n", ptr->lic);
    printf("| Your Washing Will Start in: %d minutes\n", start_time); 
    printf("| Your Washing Will End in: %d minutes\n", end_time);
    printf("| Your bill: %d Rupees\n", ptr->rate);
    printf("\n-----------------------------------------------------------------\n\n");
}


int main()
{
    int wax_check, mins,cost;
    int ID;
    int choice,choice2;
    struct node*Front=(struct node* )malloc(sizeof(struct node));
    Front=NULL;
    int flag=0;
    
    printf("\n ------------------- WELCOME TO MYR CAR WASH STATION ------------------- \n");
    do
    {
        printf("\n1) ADD A CUSTOMER TO QUEUE\n2) REMOVE A CUSTOMER FROM QUEUE\n3) CHECK START TIME FOR A CUSTOMER\n4) CHECK END TIME FOR A CUSTOMER\n5) PRINT TICKET FOR LAST CUSTOMER\n6) DISPLAY THE QUEUE\n7) CHECK NUMBER OF CARS AHEAD\n");
        
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
    
        switch(choice)
        {
            case 1:
                printf("\n\n-----------------------------------------------------------------\n\n");
                printf("Enter license plate number of your car: ");
                scanf("%d",&ID);
                
                printf("\n\n1) Wash Only -----> 10 minutes ---------> 300 Rupees\n2) Wash and Wax -----> 14 minutes ---------> 500 Rupees\n\n");
                int flag2=0;
                while(flag2==0)
                {
                    printf("Enter your choice: ");
                    scanf("%d",&choice2);
                    if(choice2==1)
                    {
                        Front = enqueue(Front,ID,0,10,300);
                        flag2=1;
                    }
                    else if(choice2==2)
                    {
                        Front = enqueue(Front,ID,1,14,500);
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
                printf("\n\nEnter license plate number: ");
                scanf("%d",&ID);
                start_id(Front,ID);
                break;

            case 4:
                printf("\n\nEnter license plate number: ");
                scanf("%d",&ID);
                end_id(Front,ID);
                break;
                
            case 5:
                printf("\n\nEnter license plate number: ");
                scanf("%d",&ID);
                print(Front,ID);
                break;
            
            case 6:
                display(Front);
                break;
            
            case 7:
                cars_ahead(Front);
                break;
                
            default:
                printf("This option doesn't exist!!!");
                break;
        }
    }while(flag==0);
}
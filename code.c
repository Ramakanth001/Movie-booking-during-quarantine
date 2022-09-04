/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void start();
int call();
int userlogin(int);
void CreateSeats();
void BrowseByTheatre();
void BrowseByMovie();
void BookSeats();
void fb();
void DisplaySeats(int,int[],int);
int cancelseat();
typedef struct snack{
    int x;
    struct snack*link;
}snacks;
snacks*front=NULL;
snacks*rear=NULL;
typedef struct node {
    struct node *prev;
    int seatnum;
    int status;
    struct node *next;
}seats;
seats *head1,*head2,*head3,*head4;
struct user{
    char username[10];
    char password[10];
}*pUser;
int covid,theatre,movie,slot,netprice=0,desired=0,buysnack,rebook,cancel;

int main()
{
    int i; char movie [50];char theatre [50],login;
    printf("-----------------------------------------------------------\n");
    printf("WELCOME TO MOVIE BOOKING SITE!!!\n");
    login=call();
    printf("%d",login);
    if(login==1)
    {
      printf("Is COVID-19 still prevalent??\nIf yes press 1 If no press 0\n");
      scanf("%d",&covid);
      start();
    }
    else
    {
      printf("user validation failure");
      exit(0);
    }
    printf("THANKYOU!!!\nVISIT AGAIN\n");
}
int call()
{
   int choice,sum;
   printf("1. Login Through An Existing Account\n2. Create New account\n3.exit\n");
   scanf("%d",& choice);
   sum=userlogin(choice);
   if(sum==2)
   return 1;
   printf("1. Login Through An Existing Account\n2. Create New account\n3.exit\n");
   scanf("%d",& choice);
   sum=userlogin(choice);
   if(sum==2)
   return 1;
   else 
   return 0;
}
int userlogin(int choice){
    FILE *fp;
    char uName[10], pwd[10];int x=0,pd=0,un=0;char c;
    pUser=(struct user *)malloc(sizeof(struct user));
    
    switch(choice)
    {
        case 1:
            if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit (1);
                }
            }
            printf("Username: ");
            scanf("%s",uName);
            printf("Password: ");
            scanf("%s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1) 
            {
                if( strcmp ( pUser->username, uName) == 0) 
                {
                    printf("User ID is valid\n");
                    un=1;//confirmation
                }
                else
                {
                  printf ("Username is invalid\n");
                  exit(0);
                }
               if( strcmp ( pUser->password, pwd) == 0)
                {
                        printf ("Match password\n");
                        pd=1;
                }
                else
                {
                  printf ("password is invalid\n");
                  exit(0);
                }
            }
            break;
        case 2:
             if ( ( fp=fopen("user.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
                }
                printf("Choose A Username: ");
                scanf("%9s",pUser->username);
                printf("Choose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp);
                printf("Account created successfully!!!\n");
               break;
        case 3:
            x=3;
            exit(0);
        default:
            printf("invalid choice\n");
    }
    free(pUser);//free allocated memory
    fclose(fp);
    return pd+un;
}
void start()
{
    int browse,user,login;
    printf("How would you like to browse:\n1)As per theatre\n2)As per movie\n");
    scanf("%d",&browse);
    if(browse==1)
    BrowseByTheatre();
    else
    BrowseByMovie();
    }
void BrowseByTheatre()
{
    printf("list of theatres available:\n1)Cinepolis\n2)Inox\n\nCHOOSE ONE AMONG THESE\n");
    scanf("%d",&theatre);
    printf("list of movies available:\n1)ironman\n2)tenet\n3)baahubali\n4)joker\n5)bridge\n6)batman\n\nCHOOSE ONE AMONG THESE\n");
    scanf("%d",&movie);
    printf("SHOW TIMMINGS:\n1)11:00\n2)06:00\nCHOOSE ONE AMONG THESE\n");
    scanf("%d",&slot);
    if(rebook==1)
    {
       BookSeats();
    }
    else
    {
      CreateSeats();
      BookSeats();
    }
   
}
void BrowseByMovie()
{
    printf("list of movies available:\n1)ironman\n2)tenet\n3)baahubali\n4)joker\n5)bridge\n6)batman\n\nCHOOSE ONE AMONG THESE\n");
    scanf("%d",&movie);
    printf("list of theatres available:\n1)Cinepolis\n2)Inox\n\nCHOOSE ONE AMONG THESE\n");
    scanf("%d",&theatre);
    printf("SHOW TIMMINGS:\n1)11:00AM\n\n2)06:00PM\nCHOOSE ONE AMONG THESE\n");
    scanf("%d",&slot);
    if(rebook==1)
    {
       BookSeats();
    }
    else
    {
      CreateSeats();
      BookSeats();   
    }
   
}
void CreateSeats()
{
    int i;
    seats *q1=head1;
    for(i=1;i<=204;i++)
    {
        seats *t=(seats*)malloc(sizeof(seats));
        if(q1==NULL)
        {
            t->seatnum=1;
            t->status=0;
            t->prev=head1;
            head1=t;
            q1=t;
        }
        else
        {
            t->seatnum=i;
            if(covid==1)
            {
                if(t->seatnum%2==0)
                t->status=1; 
                else 
                t->status=0;
            }
            else
            {
                t->status=0;   
            }
            t->prev=q1;
            q1->next=t;
            q1=t;
        }
    }q1->next=NULL;
    seats *q2=head2;
      for(i=1;i<=204;i++)
    {
        seats *t=(seats*)malloc(sizeof(seats));
        if(q2==NULL)
        {
            t->seatnum=1;
            t->status=0;
            t->prev=head2;
            head2=t;
            q2=t;
        }
        else
        {
            t->seatnum=i;
            if(covid==1)
            {
                if(t->seatnum%2==0)
                t->status=1; 
                else 
                t->status=0;
            }
            else
            {
                t->status=0;   
            }
            t->prev=q2;
            q2->next=t;
            q2=t;
        }
    }q2->next=NULL;
    seats *q3=head3;
      for(i=1;i<=204;i++)
    {
        seats *t=(seats*)malloc(sizeof(seats));
        if(q3==NULL)
        {
            t->seatnum=1;
            t->status=0;
            t->prev=head3;
            head3=t;
            q3=t;
        }
        else
        {
            t->seatnum=i;
            if(covid==1)
            {
                if(t->seatnum%2==0)
                t->status=1; 
                else 
                t->status=0;
            }
            else
            {
                t->status=0;   
            }
            t->prev=q3;
            q3->next=t;
            q3=t;
        }
    }q3->next=NULL;
    seats *q4=head4;
      for(i=1;i<=204;i++)
    {
        seats *t=(seats*)malloc(sizeof(seats));
        if(q4==NULL)
        {
            t->seatnum=1;
            t->status=0;
            t->prev=head4;
            head4=t;
            q4=t;
        }
        else
        {
            t->seatnum=i;
            if(covid==1)
            {
                if(t->seatnum%2==0)
                t->status=1; 
                else 
                t->status=0;
            }
            else
            {
                t->status=0;   
            }
            t->prev=q4;
            q4->next=t;
            q4=t;
        }
    }q4->next=NULL;
}
void BookSeats()
{
   int TotSeats,i,j;
    printf("ENTER NUMBER OF SEATS:\n");
    scanf("%d",&TotSeats);
    int SelectedSeats[TotSeats];
    printf("\nCHOOSE YOUR SEATS AMONG THE FOLLOWING CLASSES\n\n<>Silver==>\nprice:60\nSeat numbers:1-60\nseats in a row:12\nRows:5\n\n<>Gold==>\nprice:120\nSeat numbers:61-180\nseats in a row:12\nRows:10\n\n<>Diamond==>\nprice :200\nSeat numbers:181-204\nseats in a row:12\nRows:2\n");
    printf("\nCORNER SEATS:\n");
    for(i=1,j=12;j<205;i+=12,j+=12)
    {
        printf("%d %d\n",i,j);
    }
   
    printf("available seats are:\n---------------------------SCREEN------------------------\n");
    if(theatre==1&&slot==1)
    {
      seats *q1=head1;
      while(q1)
     {
        if(q1->status==0)
        printf("%d\t",q1->seatnum);
        else if((q1->status==1))
        printf("*\t");
        if(q1->seatnum%12==0)
        printf("\n\n");
        q1=q1->next;
     }
   printf("\nSelect the seats:\n");
   for(i=0;i<TotSeats;i++)
   {
     scanf("%d",&SelectedSeats[i]);
   }
    
   seats *t=head1;
   for (i = 0; i < TotSeats; i++)
	{
	  while (t->seatnum != SelectedSeats[i])
	    {
	      t = t->next;
	    }

	  if (t->status == 1)
	    {
	      printf("you have chosen quarantined seates or already reserved seats please try again!!!");
	      exit (0);
	    }
	  else if (t->status == 0)
	    {
	      t->status = 1;
	    }
	 }
}

    else if(theatre==1&&slot==2)
    {
       seats *q2=head2;
       while(q2)
    {
        if(q2->status==0)
        printf("%d\t",q2->seatnum);
        else 
        printf("*\t");
        if(q2->seatnum%12==0)
        printf("\n\n");
        q2=q2->next;
    }
     printf("\nSelect the seats:\n");
    for(i=1;i<=TotSeats;i++)
    scanf("%d",&SelectedSeats[i]); 
    seats *t=head2;
     for (i = 0; i < TotSeats; i++)
	{
	  while (t->seatnum != SelectedSeats[i])
	    {
	      t = t->next;
	    }

	  if (t->status == 1)
	    {
	      printf("you have chosen quarantined seates or already reserved seats please try again!!!");
	      exit (0);
	    }
	  else if (t->status == 0)
	    {
	      t->status = 1;
	    }
	}
}
   else if(theatre==2&&slot==1)
   {
   seats *q3=head3;
   while(q3)
   {
        if(q3->status==0)
        printf("%d\t",q3->seatnum);
        else 
        printf("*\t");
        if(q3->seatnum%12==0)
        printf("\n\n");
        q3=q3->next;
   }
   printf("\nSelect the seats:\n");
   for(i=1;i<=TotSeats;i++)
   scanf("%d",&SelectedSeats[i]); 
   seats *t=head3;
    for (i = 0; i < TotSeats; i++)
	{
	  while (t->seatnum != SelectedSeats[i])
	    {
	      t = t->next;
	    }

	  if (t->status == 1)
	    {
	      printf("you have chosen quarantined seates or already reserved seats please try again!!!");
	      exit (0);
	    }
	  else if (t->status == 0)
	    {
	      t->status = 1;
	    }
	 }
}
    else if(theatre==2&&slot==2)
    {
       seats *q4=head4;
       while(q4)
    {
        if(q4->status==0)
        printf("%d\t",q4->seatnum);
        else 
        printf("*\t");
        if(q4->seatnum%12==0)
        printf("\n\n");
        q4=q4->next;
    }
     printf("\nSelect the seats:\n");
    for(i=1;i<=TotSeats;i++)
    scanf("%d",&SelectedSeats[i]); 
    seats *t=head4;
     for (i = 0; i < TotSeats; i++)
	{
	  while (t->seatnum != SelectedSeats[i])
	    {
	      t = t->next;
	    }

	  if (t->status == 1)
	    {
	      printf("you have chosen quarantined seates or already reserved seats please try again!!!");
	      exit (0);
	    }
	  else if (t->status == 0)
	    {
	      t->status = 1;
	    }
	 }
}
   netprice=0;
     for(i=0;i<TotSeats;i++)
    {
        if(SelectedSeats[i]<61)
        netprice+=60;
        else if(SelectedSeats[i]<181)
        netprice+=120;
        else if(SelectedSeats[i]<205)
        netprice+=200;
    }

    printf("would you like to buy snacks? \nif yes press 1 else 0\n");
    scanf("%d",&buysnack);
    if(buysnack==1)
    fb();
    DisplaySeats(TotSeats,SelectedSeats,netprice);
}
void fb()
{
   int desired,snackagain;
   snacks *s=(snacks *)malloc(sizeof(snacks));
do{
    printf("choose your snacks:\n1.coke and popcorn=>price:250\n2.coke and nachos=>price:300\n3.popcorn and nachos=>price:350\n");
    scanf("%d",&desired);
    if(desired==1)
    netprice+=250;
    else if(desired==2)
    netprice+=300;
    else
    netprice+=350;
    s->x=desired;
    s->link=NULL;
    if(front==NULL&&rear==NULL)
    {
      front=s;
      rear=s;
    }
    else
    {
      rear->link=s;
      rear=s;
    }
    int snackagain;
    printf("would you like to buy more snacks?\nif yes press 1 if no press 0\n");
    scanf("%d",&snackagain); 
    if(snackagain==0)
    break;
   }while(snackagain>0);
}
void DisplaySeats(int seats,int SelectedSeats[],int price)
{
    #define LEN 150
    char buf[LEN];
    int i;
    time_t curtime;
    struct tm *loc_time;
    curtime = time (NULL);
    loc_time = localtime (&curtime);
    snacks *d=(snacks *)malloc(sizeof(snacks));
    printf("--------------------------------------------------------------------\n");
    printf("CONGRATULATIONS YOUR SEATS ARE BOOKED!!!!\nDETAILS:\nMovie :");
    (movie==1)?(printf("ironman")):
    (movie==2)?(printf("tenet")):
    (movie==3)?(printf("baahubali")):
    (movie==4)?(printf("joker")):
    (movie==5)?(printf("bridge")):printf("batman");
    printf("\ntheatre :");
    (theatre==1)?(printf("Cinepolis")):printf("Inox");
    printf("\nNo. of seats :%d\n",seats);
    printf("slot :");
    (slot==1)?(printf("11:00AM\nSelectedseats:")):printf("6:00PM\nSelectedseats:");
    for(i=0;i<seats;i++)
    printf("%d ",SelectedSeats[i]);
    if(buysnack==1)
    {
      printf("\nsnacks:");
      d=front;
      if ((d == NULL) && (rear == NULL))
    {
        printf("NO snacks selected\n");
        return;
    }
      while(d!=rear)
      {
         (d->x==1)?(printf("coke and popcorn")):
         (d->x==2)?(printf("coke and nachos")):printf("popcorn and nachos");
         d=d->link;
      }
      if(d==rear)
      {
       (d->x==1)?(printf("coke and popcorn")):
         (d->x==2)?(printf("coke and nachos")):printf("popcorn and nachos");
      }
   }
    printf("\nprice :%d\n",netprice);
    printf("Time of booking :%s\n", asctime (loc_time));
    printf("Would you like to book again?(1==Y)\n");
    scanf("%d",&rebook);
    if(rebook==1)
    start();
    printf("Would you like to cancel any tickets?(1==Y)\n");
    scanf("%d",&cancel);
    if(cancel==1)
    cancelseat();
}
int cancelseat()
{
   int CanSeats,i,SubtractedPrice,NewPrice;
   seats *c=(seats*)malloc(sizeof(seats));
   printf("how many seats would you like to cancel?\n");
   scanf("%d",&CanSeats);
   int cseats[CanSeats];
   printf("enter seats to cancel\n");
   for(i=0;i<CanSeats;i++)
   {
      scanf("%d",&cseats[i]);
   }
   if(theatre==1&&slot==1)
   c=head1;
   else if(theatre==1&&slot==2)
   c=head2;
   else if(theatre==2&&slot==1)
   c=head3;
   else if(theatre==2&&slot==2)
   c=head4;
   for(i=0;i<CanSeats;i++)
   {
      while(c->seatnum!=cseats[i])
      {
         c=c->next;
      }
      if(c->seatnum==cseats[i])
      {
         if(c->status==0)
         printf("seat %d isn't booked\n",c->seatnum);
         else
         c->status=0;
         printf("seat %d is cancelled successfully\n",c->seatnum);
      }
   }
   printf("Seat cancellation successfull\n");
   for(i=0;i<CanSeats;i++)
   {
        if(cseats[i]<61)
        SubtractedPrice+=60;
        else if(cseats[i]<181)
        SubtractedPrice+=120;
        else if(cseats[i]<205)
        SubtractedPrice+=200;
   }
   NewPrice=netprice-SubtractedPrice;
   printf("New price is %d",NewPrice);
}
   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
/*   **** AHMAD BAKRI 1201509 ****   */


// to make a passenger (node) and add data to it
typedef struct passenger{

    int travelerId;
    int datePass;
    char travellingtime[20];
    char fromDestP[20];
    char toDestP[20];
    struct passenger*Next;

} passenger;
// to make a Bus (node) and add data to it
typedef struct Bus{

    int busNum;
    int dateBus;
    char depTime[20];
    char fromDestB[20];
    char toDestB[20];
    int tikPrice;
    int capacity;
    struct Bus*NextBus;
    struct passenger*NextPassenger;

} Bus;

// *Define the prototype of all functions* //
int checkEmptyOfBuses(struct Bus*);
int checkEmptyOfPassengers(struct passenger*);
int LastBus (struct Bus*,struct Bus*);
int lastPass (struct passenger*,struct passenger*);
void PrintListBus(struct Bus*);
void PrintListPassengers(struct passenger*);
void loadBus(struct Bus*);
void loadPassengers(struct passenger*);
void addPassengersToBus(struct Bus*,struct passenger*);
void printTheUnmatchedLinkedList(struct Bus* headB,struct passenger*head);
void printAllBusesAfterAddedPassengers(struct Bus*,struct passenger*);
void PrintAspecificBusInformation(struct Bus* headB,struct passenger*headP);
void addPassengerToPassengersLinkedList(struct passenger* head,int id,int date,char *time,char*from,char*to);
void printAllPassengersAfterAddedPassengers(struct Bus*,struct passenger*);
void Delete (int, struct passenger *);
void DeleteBus(int,struct Bus*);
struct Bus* checkPreviousBus(int,struct Bus *);
struct passenger* checkPreviousPas(int,struct passenger *);
//-----------------------------------------//

int main()
{
    struct Bus*head=(struct Bus*)malloc(sizeof(struct Bus)); //The head of linked list (Bus linked list)
    loadBus(head);/* This function to read all information about Buses and make linked List of buses from the data that has been read from file(Bus file)*/

    struct passenger*headP=(struct passenger*)malloc(sizeof(struct passenger));//The head of linked list (passenger linked list)
    loadPassengers(headP);/* This function to read all information about passengers and make linked List of passengers from the data that has been read from file(passengers file)*/

    // menu of the application:
    int U;
    printf("Enter the number you want from 1 to 9\n");
    scanf("%d",&U);

    for (;U!=9;)
    {
        if (U==1)
        {
            loadBus(head);
            printf("Enter the number you want from 1 to 9\n");
            scanf("%d",&U);
        }
        else if (U==2)
        {
            loadPassengers(headP);
            printf("Enter the number you want from 1 to 9\n");
            scanf("%d",&U);
        }
        else if (U==3)
        {
            printAllBusesAfterAddedPassengers(head,headP);
            printf("Enter the number you want from 1 to 9\n");
            scanf("%d",&U);
        }
        else if (U==4)
        {
            PrintAspecificBusInformation(head,headP);
            printf("Enter the number you want from 1 to 9\n");
            scanf("%d",&U);
        }
        else if (U==5)
        {
            printTheUnmatchedLinkedList(head,headP);
            printf("Enter the number you want from 1 to 9\n");
            scanf("%d",&U);
        }
        else if (U==6)
        {
            int id,date;
            char time[10];
            char from[10];
            char to[10];
            printf("Enter the data you want to add at passenger\n");
            scanf("%d",&id);
            scanf("%d",&date);
            scanf("%s",&time);
            scanf("%s",&from);
            scanf("%s",&to);
            addPassengerToPassengersLinkedList(headP,id,date,time,from,to);
            PrintListPassengers(headP);
            printf("Enter the number you want from 1 to 9\n");
            scanf("%d",&U);
        }
         else if (U==7)
        {
            int id;
            scanf("%d",&id);
            Delete(id,headP);
            PrintListPassengers(headP);
            printf("Enter the number you want from 1 to 9\n");
            scanf("%d",&U);
        }
        else if (U==8)
        {
            int id;
            scanf("%d",&id);
            DeleteBus(id,head);
            PrintListBus(head);
            printf("Enter the number you want from 1 to 9\n");
            scanf("%d",&U);
        }
    }
    return 0;
}
//This function to check if the head of the linked list of buses point to NULL or Not
int checkEmptyOfBuses(struct Bus* headerOfBuses)
{
    return headerOfBuses->NextBus==NULL;
}
//This function to check if the head of the linked list of passengers point to NULL or Not
int checkEmptyOfPassengers(struct passenger* headerOfPassengers)
{
    return headerOfPassengers->Next==NULL;
}
//This function check if the node of linked list of buses is at last or Not
int LastBus (struct Bus* position,struct Bus* head)
{
    return position->NextBus==NULL;
}
//This function check if the node of linked list of passengers is at last or Not
int lastPass (struct passenger* position,struct passenger* head)
{
    return position->Next==NULL;
}
//This function print all information of buses after the file of buses is read
void PrintListBus(struct Bus* headerOfBuses)
{
    struct Bus* position =headerOfBuses; //create a node(bus) so i can change the position this node instead of the header

    if (checkEmptyOfBuses(headerOfBuses))// to check if the linked list is empty or not
        printf("the linked list is empty:(try again\n");
    else
        do
        {
            position=position->NextBus;
            printf("%d\t",position->busNum);
              printf("%d\t",position->dateBus);
                printf("%s\t",position->depTime);
                  printf("%s\t",position->fromDestB);
                    printf("%s\t",position->toDestB);
                      printf("%d\t",position->tikPrice);
                         printf("%d",position->capacity);
                                  printf("\n");
        }
        while (!LastBus(position,headerOfBuses));// to check if the position is the last node or not
    printf("\n");
}
//This function print all information of passengers after the file of passengers is read
void PrintListPassengers(struct passenger* headerOfPassengers)
{
    struct passenger* position =headerOfPassengers;//create a node(passenger) so i can change the position this node instead of the header

    if (checkEmptyOfPassengers(headerOfPassengers))// to check if the linked list is empty or not
        printf("the linked list is empty:(try again\n");
    else
        do
        {
            position=position->Next;
            printf("%d\t",position->travelerId);
              printf("%d\t",position->datePass);
                printf("%s\t",position->travellingtime);
                  printf("%s\t",position->fromDestP);
                    printf("%s\t",position->toDestP);
                           printf("\n");
        }
        while (!lastPass(position,headerOfPassengers));// to check if the position is the last node or not
    printf("\n");
}
/* This function to read all information about Buses and make linked List of buses from the data that has been read from file(Bus file)*/
void loadBus(struct Bus*headerOfBuses)
{
    Bus*R=headerOfBuses;

    char *W;int M;char storingString[SIZE];char arrayOfString[SIZE];int integersArray;

    FILE *Bus;
    Bus=fopen("busses.txt","r");// to open the file and read the information

    if (Bus==NULL){
        printf("the linked list is empty:(try again\n");
    }

    for(;fgets(storingString,SIZE,Bus);)//  reading the lines in file and exit if the information is ended
    {
        struct Bus*arrow =(struct Bus*)malloc(sizeof(struct Bus));// take place to the buses in memory (bus after bus)
        arrow->NextBus=NULL;
        R->NextBus=arrow;

        W= strtok(storingString,"#");// split the string in the # and take the word or int or char before#
        M = atoi(W);//convert string to int
        integersArray= M;
        R->NextBus->busNum=integersArray;
        printf("%d\t",integersArray);

        W= strtok(NULL,"#");
        M = atoi(W);//convert string to int
        integersArray= M;
        R->NextBus->dateBus=integersArray;
        printf("%d\t",integersArray);

        W=strtok(NULL,"#");
        strcpy(R->NextBus->depTime,W);
        printf("%s\t",R->NextBus->depTime);

        W=strtok(NULL,"#");
        strcpy(R->NextBus->fromDestB,W);
        printf("%s\t",R->NextBus->fromDestB);

        W=strtok(NULL,"#");
        strcpy(R->NextBus->toDestB,W);
        printf("%s\t",R->NextBus->toDestB);

        W= strtok(NULL,"#");
        M = atoi(W);
        integersArray= M;
        R->NextBus->tikPrice=integersArray;
        printf("%d\t",integersArray);

        W= strtok(NULL,"\n");
        M = atoi(W);
        integersArray= M;
        R->NextBus->capacity=integersArray;
        printf("%d\n",integersArray);

        R=R->NextBus;
        printf("\n");
    }
}
/* This function to read all information about passengers and make linked List of passengers from the data that has been read from file(passengers file)*/
void loadPassengers(struct passenger*headerOfPassengers)
{
    passenger*A=headerOfPassengers;

    char *B;int M ;char storingStringP[SIZE];char arrayOfStringP[SIZE];int integersArrayP;

    FILE *Passengers;
    Passengers=fopen("passengers.txt","r");// to open the file and read the information

    if (Passengers==NULL)
    {
        printf("the linked list is empty:(try again\n");
    }

    for(;fgets(storingStringP,SIZE,Passengers);)//  reading the lines in file and exit if the information is ended
    {
        struct passenger*arrowP =(struct passenger*)malloc(sizeof(struct passenger));
        arrowP->Next=NULL;
        A->Next=arrowP;

        B= strtok(storingStringP,"#");// split the string in the # and take the word or int or char before#
        M = atoi(B);//convert string to int
        integersArrayP= M;
        arrowP->travelerId=integersArrayP;
        printf("%d\t",integersArrayP);

        B= strtok(NULL,"#");
        M = atoi(B);
        integersArrayP= M;
        arrowP->datePass=integersArrayP;
        printf("%d\t",integersArrayP);

        B=strtok(NULL,"#");
        strcpy(arrowP->travellingtime,B);
        printf("%s\t",arrowP->travellingtime);

        B=strtok(NULL,"#");
        strcpy(arrowP->fromDestP,B);
        printf("%s\t",arrowP->fromDestP);

        B=strtok(NULL,"\n");
        strcpy(arrowP->toDestP,B);
        printf("%s\t",arrowP->toDestP);

        A=A->Next;
        printf("\n");
    }
}
//This function to point to a node before the position i chose it(linked list of passengers)
struct passenger* checkPreviousPas(int id,struct passenger * headerOfPassengers)
{
    struct passenger*position;
    position=headerOfPassengers;

    while (position->Next!=NULL && position->Next->travelerId !=id)
        position=position->Next;

    return position;
}
//This function to point to a node before the position i chose it(linked list of Buses)
struct Bus* checkPreviousBus(int id,struct Bus * headerOfBuses)
{
    struct Bus*position;
    position=headerOfBuses;

    while (position->NextBus!=NULL && position->NextBus->busNum !=id)
        position=position->NextBus;

    return position;
}
/*This function is to add passengers to buses who fits it and compare the time of the passengers and buses to check if
the passengers are agree with buses or Not*/
void addPassengersToBus(struct Bus*headerOfBuses,struct passenger*headerOfPassengers)
{
    struct Bus*tempB=headerOfBuses->NextBus;
    struct passenger*tempP=headerOfPassengers->Next;

    for(;tempB!=NULL;)// for loop rotates on all buses
    {
        tempB->NextPassenger=(struct passenger*)malloc(sizeof(struct passenger));
        tempB->NextPassenger->Next=NULL;

        for(;tempP!=NULL;)// for loop rotates on all passengers
        {
            if ( tempB->dateBus == tempP->datePass && strcmp(tempB->fromDestB, tempP->fromDestP)==0 && strcmp(tempB->toDestB, tempP->toDestP)==0 )
            {
                char*c;char*d;int x,y;

                c=strtok(tempP->travellingtime,":");
                x=atoi(c);

                d=strtok(NULL," ");
                y=atoi(d);

                char *f;char *w;int a,s;

                char G[100];
                strcpy(G,tempB->depTime);

                f=strtok(G,":");
                a= atoi(f);

                w=strtok(NULL,"\n");
                s=atoi(w);

                if ((strcmp(c,f)==-1) || ((strcmp(c,f)==0) && (strcmp(d,w)==-1)))//to modify the time of passengers to match time of buses
                {
                    if (tempB->capacity==0) //the capacity of buses
                    {
                        printf("the bus is full:(\n");
                        break;
                    }
                    printf("add passenger=%d to bus num=%d\n",tempP->travelerId,tempB->busNum);
                    struct passenger*convert =checkPreviousPas(tempP->travelerId,headerOfPassengers);
                    convert->Next =tempP->Next;

                    struct passenger *x=(struct passenger*)malloc(sizeof(struct passenger));
                    x->travelerId=tempP->travelerId;
                    x->datePass=tempP->datePass;
                    strcpy(x->travellingtime,tempP->travellingtime);
                    strcpy(x->fromDestP,tempP->fromDestP);
                    strcpy(x->toDestP,tempP->toDestP);
                    x->Next=tempB->NextPassenger->Next;
                    tempB->NextPassenger->Next=x;
                    tempB->capacity--;
                }
            }
            tempP=tempP->Next;
        }
        tempB=tempB->NextBus;
        tempP=headerOfPassengers->Next;
    }
}
//This function print all the passengers who does not fit any of the buses
void printTheUnmatchedLinkedList(struct Bus*headerOfBuses,struct passenger*headerOfPassengers)
{
    //addPassengersToBus(headerOfBuses,headerOfPassengers);// contribute the passengres to buses
    struct passenger* position =headerOfPassengers;//create a node(bus) so i can change the position this node instead of the header

    if (checkEmptyOfPassengers(headerOfPassengers))// to check if the linked list is empty or not
        printf("the linked list is empty:(try again\n");

    else
        printf("\nprint the unmathed linked list\n");

    while(!lastPass(position,headerOfPassengers))// to check if the position is the last node or not
        {
        position=position->Next;
        printf("%d\t",position->travelerId);
          printf("%d\t",position->datePass);
             printf("%s\t",position->travellingtime);
                printf("%s\t\t",position->fromDestP);
                   printf("%s\t\t",position->toDestP);
                           printf("\n");
    }

}
// This function to print all information of buses after we added passengers to buses
void printAllBusesAfterAddedPassengers(struct Bus* headerOfBuses,struct passenger*headerOfPassengers)
{
    addPassengersToBus(headerOfBuses,headerOfPassengers);// contribute the passengres to buses

    struct Bus* position =headerOfBuses->NextBus;

    if (checkEmptyOfBuses(headerOfBuses))// to check if the linked list is empty or not
        printf("the linked list is empty:(try again\n");

    else
        while (position!=NULL)
        {
            printf("%d\t",position->busNum);
              printf("%d\t",position->dateBus);
                   printf("%s\t",position->depTime);
                     printf("%s\t",position->fromDestB);
                        printf("%s\t",position->toDestB);
                            printf("%d\t",position->tikPrice);
                                printf("%d\t",position->capacity);
                                          printf("\n");
            position=position->NextBus;
        }
}
//This function to print the specific bus with all Id's of passengers of this bus
void PrintAspecificBusInformation(struct Bus* headerOfBuses,struct passenger*headerOfPassengers)
{

    int x;
    struct passenger* temppass=headerOfPassengers->Next;
    struct Bus* L=headerOfBuses->NextBus;

    if (checkEmptyOfBuses(headerOfBuses))// to check if the linked list is empty or not
        printf("\nprint the unmathed array\n");

    printf("Enter the number of Bus you want\n");
    scanf("%d",&x);

    for (;L!=NULL;)
    {

        if (x==L->busNum)
        {
            if(L->NextPassenger->Next == NULL)
                printf("Not NULL");

            printf("The information of the bus num%d \n",x);
            while(L->NextPassenger->Next!=NULL){
                printf("%d\n",L->NextPassenger->Next->travelerId);
                L->NextPassenger->Next=L->NextPassenger->Next->Next;
            }

            printf("%d\t",L->dateBus);
                 printf("%s\t",L->depTime);
                    printf("%s\t",L->fromDestB);
                       printf("%s\t",L->toDestB);
                          printf("%d\t",L->tikPrice);
                               printf("%d\t",L->capacity);
                                    printf("\n");
        }
        L=L->NextBus;
    }
}
//This function to add a passenger to linked list of passengers at the beginning
void addPassengerToPassengersLinkedList(struct passenger* head,int id,int date,char *time,char*from,char*to)
{
    struct passenger* position=head;
    struct passenger* H;

    H = (struct passenger*)malloc(sizeof(struct passenger));

    H->travelerId=id; H->datePass=date; strcpy(H->travellingtime,time); strcpy(H->fromDestP,from); strcpy(H->toDestP,to);
    H->Next=position->Next;
    position->Next=H;
}
//This function to print the linkedd list of passengers after we add a passenger(node)to it
void printAllPassengersAfterAddedPassengers(struct Bus* headerOfBuses,struct passenger*headerOfPassengers)
{
    //addPassengersToBus(headB,headerOfPassengers);

    struct passenger* T =headerOfPassengers;

    if (checkEmptyOfPassengers(headerOfPassengers))
        printf("\nprint the unmathed array\n");

    else
        printf("\nThe passengers after added passengers To buses\n");
    do
    {
        T=T->Next;
        printf("%d\t",T->travelerId);
          printf("%d\t",T->datePass);
            printf("%s\t",T->travellingtime);
               printf("%s\t",T->fromDestP);
                  printf("%s\t",T->toDestP);
                        printf("\n");

    }
    while (!lastPass(T,headerOfPassengers));
    printf("\n");
}
//This function to delete a passenger from a linked list of passengers
void Delete (int id, struct passenger *headerOfPassengers)
{
    struct passenger*J;
    struct passenger*temp;

    J=checkPreviousPas(id,headerOfPassengers);

    if (!lastPass(J,headerOfPassengers))
    {
        temp= J->Next;J->Next=temp->Next;free(temp);
    }
}
//This function to delete a Bus from a linked list of Buses
void DeleteBus(int Num,struct Bus*headerOfBuses)
{
    struct Bus*V;
    struct Bus*temp;

    V=checkPreviousBus(Num,headerOfBuses);

    if (!LastBus(V,headerOfBuses))
    {
        temp= V->NextBus; V->NextBus=temp->NextBus; free(temp);
    }
}






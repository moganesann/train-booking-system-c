// https://online.ktmb.com.my/ Our Project Website
/*
     Done By :
       Moganesan A/L Veragu ( CB19095 )
       Narresh Naidu A/L Subramaniam ( CB19015 )
       Logadarshan A/L Krishnan ( CB19083 )
       Eric Anandan A/L Anthony Jayakumar ( CB19061 )
       Yoshana A/P Selvaraj ( CB19023 )
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct TicketPrice    //nested structure
{
    float adults_price;
    float children_price;
    float senior_price;
    float oku_price;
    float total;
};
struct Passenger //main Structure
{
    int userid;
    char p_name[100];
    char p_icno[20];
    int age;
    char p_gender;
    char p_type[20];
    int seats;
};
 struct User
 {
    char name[100];
    char email[50];
    char icno[20];
    char gender;
    char contact_no[12];
    int adults,children,senior,oku;
   struct TicketPrice f;  //nested structure (array)

 };
struct Payment
{
    char acc_no[15];
    char bank_name[20];
};
struct Booking_date//
{
    int date,month,year;
};
struct Booking                  // Main structure
{
    int ticket_id;
    struct Booking_date d;     //nested structure
    struct User c;            //nested structure
    struct Payment a;         //nested structure
};

struct TrainStation
{
    char station[100];
};
struct TrainTiming
{
    char duration[50];
    int departuretime,arrivaltime;
};
struct Train
{
    char type[20];
    float price;
};
struct Schedule //Main Structure
{
    char departure[100];
    char arrival[100];
    struct TrainStation s;   //nested structure
    struct Train r;        //nested structure
    struct TrainTiming l; //nested structure
};

void trainBooking(struct Schedule x[],struct Booking y[],struct Passenger p[]);
void DisplaySchedule(int arraysize, struct Schedule x[]);
void EditBooking(struct Passenger p[],int);
void SetSchedule(int ,int , struct Schedule x[]);
void pop();
void push(int,struct Passenger p[] );
void displaySeats();
void Display( struct Passenger p[],int);
void Update(struct Passenger p[],int );
void Search(struct Passenger p[],int );
void Sort(int , struct Passenger p[]);
void Delete(struct Passenger p[],int);
float calculate(float , float , float , float );
int StationSelection(int);
int StateSelection();
struct Booking CalcTicket(struct Booking y ,float);

int i,j,seat,negeri,station,arraysize;
int n = 100;
int stack[100],choice,top,x;

int main()
{
    struct Schedule train[50]; // structure (array)
    struct Booking book[100];  // structure (array)
    struct Passenger pass[6]; //stucture array

    char ch;
    do{
        printf("\n");
        printf("    =======================================\n");
        printf("      Welcome to KTM Train Booking System\n");
        printf("    =======================================\n");
        printf("\n           A - Make a train booking \n           B - Display Booking \n           D - Edit Booking Info \n           X - Exit Menu\n\n");
         printf("    =======================================\n");
        printf("\n   Please enter choice: ");
        scanf(" %c", &ch);
        ch = toupper(ch);
        switch (ch)
        {
            case 'A': trainBooking(train,book,pass); break;
            case 'B': Display(pass,seat); break;
            case 'D': EditBooking(pass,seat);  break;
            case 'X': printf("\n\n==============/Exited system/==============\n"); break;
            default: printf("\nInvalid choice. Please select either A, B, D, or X\n");
        }
    } while (ch != 'X');
    return 0;
}

void trainBooking(struct Schedule x[], struct Booking y[],struct Passenger p[])
{
    int e =0;
    int cho;
    char dep[100],arr[100],tpe[100],dur[100];
    int dprttime,arrtime;
    float pri;
    printf("\n\t  Booking Train ");
    printf("\n\t  -------------");
    printf("\n  Enter booking Date (separate each input by space) DD / MM /YYYY : ");
    scanf("%i ",&y[e].d.date);
    scanf("%i ",&y[e].d.month);
    scanf("%i",&y[e].d.year);

    printf("\nYour Departure : Sentral Kuala Lumpur\n");
    printf("\nSelect your destination : \n\n");
    negeri = StateSelection();
    station = StationSelection(negeri);
    SetSchedule(negeri,station,x);
    printf("\n");
    printf("Select your desired train : ");
    scanf("%i",&cho);
    for (int j=0; j<10; j++)
    {
        if(cho == (j+1))
        {
            printf("\n");
            strcpy(dep,x[j].departure);
            strcpy(arr,x[j].arrival);
            strcpy(tpe,x[j].r.type);
            strcpy(dur,x[j].l.duration);
            dprttime = x[j].l.departuretime;
            arrtime = x[j].l.arrivaltime;
            pri = x[j].r.price;
        }
    }
    printf("\n \t *** Account Login ***  \n");
    printf("  Enter Name       : ");
    scanf(" %[^\n]s",&y[e].c.name);
    printf("  Enter Email      : ");
    scanf(" %[^\n]s",&y[e].c.email);
    printf("  Enter IC No      : ");
    scanf(" %[^\n]s",&y[e].c.icno);
    printf("  Enter Gender [M for MALE / F for FEMALE] : ");
    scanf(" %[^\n]s",&y[e].c.gender);
    printf("  Enter Contact No : ");
    scanf(" %[^\n]s",&y[e].c.contact_no);

    int pax;
    int test =  1;
    while (test==1)
    {
        printf("\nInsert number of passengers (Should not exceed more than 6 passengers) : ");
        scanf("%i",&pax);
        if(pax < 1 || pax>6)
        {
            printf("INVALID INPUT!!! TRY AGAIN!!!\n");
            printf("Input is between 1 - 6 !!! ");
            printf("\n");
            continue;  //while (test==1) will loop back again
        }
        printf("\n");
        test=0; //exit looping if selection between 1-9
    }
    printf("Discount According to Passenger Category : \n");
    printf(" Adult 0%% Discount\n Child (age 12 and below) 20%% discount\n Senior Citizen (60 years and below) 30%% discount\n Disabled Person 35%% discount\n\n");

        printf("Enter Number of Passengers [ Adults / Child / Senior Citizen / OKU ] (Separate each input with space) : ");
        scanf("%d %d %d %d",&y[e].c.adults,&y[e].c.children,&y[e].c.senior,&y[e].c.oku);

   seat = y[e].c.adults + y[e].c.children + y[e].c.senior + y[e].c.oku;

   y[e] = CalcTicket(y[e],pri);

     printf("\n  The total Ticket Price Before Discount is : RM %.2f ",seat*pri);
     printf("\n  The total Ticket Price After Discount is : RM %.2f \n",y[e].c.f.total);//testing only
     for(int i=0; i<seat;i++){
             printf("\n");
             printf("Passenger %d Data Entry \n",i+1);
             printf("Passenger ID (int): ");
             scanf("%d", &p[i].userid);
             printf("Passenger Name    : ");
             scanf(" %[^\n]s",&p[i].p_name);
             printf("Passenger IC No   : ");
             scanf(" %[^\n]s" , &p[i].p_icno);
             printf("Passenger Age     : ");
             scanf(" %d" , &p[i].age);
             printf("Passenger Gender [ M for MALE / F for FEMALE ] : ");
             scanf(" %c" , &p[i].p_gender);
             printf("Passenger Type  [Adult / Children / Senior Citizen / OKU]: ");
             scanf(" %[^\n]s" , &p[i].p_type);
    }
             top=-1;
             int j=0;
             do
            {
                printf("\nChoose your Seats option: ");
                printf("\n\t 1.Book Seat Number\n\t 2.Display Booked Seat\n\t 3.Cancel Seat Booking\n\t 4.Confirm Seat\n");
                printf("\n\n Enter the Choice:");
                scanf("%d",&choice);
                switch(choice){
                    case 1: push(seat,p);
                             break;
                    case 2: displaySeats(); break;
                    case 3: pop();
                             break;
                    case 4: j++;
                    printf("\nSeating is confirm !!! \n");
                    break;
                    default: printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
                    }
            }while(j!=seat);

            char confirmation;
            printf("\nDo you wish to confirm the booking ? [Y for Yes / N for No] : ");
            scanf(" %c",&confirmation);
            if(confirmation == 'y' || confirmation == 'Y'){
                printf("\n");
                printf("\nEnter your payment details:\n");
                printf("----------------------------\n\n");

                printf("Enter your bank name: ");
                scanf(" %[^\n]s", y[e].a.bank_name);

                printf("Enter your account no: ");
                scanf(" %s", y[e].a.acc_no);

                printf("\n Booking is successful !\n");
                e++;

            }
            else{
                printf("\n");
                printf("Your Booking process has been terminated. \n");
                printf("Thank you for using the system. \n");
                return 0;
            }
            printf("\n*************************************************************************************************************\n\n");
}

void EditBooking(struct Passenger p[], int seat)
{
    int option;
    bool execute=TRUE;
    while(execute==TRUE){
        printf("\n\n       Edit Booking Info ");
        printf("\n-------------------------------");
		printf("\n 1 - Update Booking Details \n 2 - Sort Booking Details \n 3 - Search Booking Details \n 4 - Delete Booking Details \n 5 - Back to Main Menu");
		printf("\n-------------------------------");
		printf("\nEnter choice: ");
		scanf("%i",&choice);

        switch(choice){
            case 1 : Update(p,seat); break;
            case 2 : Sort(seat,p); break;
            case 3 : Search(p,seat); break;
            case 4 : Delete(p,seat); break;
            case 5 : execute = FALSE; break;
            default: printf("\nEnter only one from the above. Please select either 1, 2, 3, 4 or 5");
        }   }
}
void Update(struct Passenger p[],int seat)
{
    if (seat == 0)
    {
        printf("\n NO DATA AVAILABLE TO BE UPDATED !!!\n");
        return;
    }
    Display(p,seat);
    int dataupdate;
    printf("\nWhich User Id do you wish to update ? : ");
    scanf("%i",&dataupdate);
    for (int m=0; m<seat; m++)
    {
        if(dataupdate == (p[m].userid))
        {
            printf("\n");
            printf("Enter New User ID         : ");
            scanf(" %d",&p[m].userid);
            printf("Enter Passenger Name      : ");
            scanf(" %[^\n]s",&p[m].p_name);
            printf("Enter Passenger Age       : ");
            scanf(" %i",&p[m].age);
            printf("Enter Passenger IC Number : ");
            scanf(" %[^\n]s",&p[m].p_icno);
            printf("Enter Passenger Gender [M for MALE / F for FEMALE] : ");
            scanf(" %c",&p[m].p_gender);
            printf("Enter Passenger Type   [Adult / Children / Senior Citizen / OKU]: ");
            scanf(" %[^\n]s",&p[m].p_type);

            printf("\n\n  -- Updated Data -- \n");
            Display(p,seat);
            return;
        }
    }

        printf("No Searched Data Found \n");
        return;
}

void Delete(struct Passenger p[],int seat)
{
    if (seat == 0)
    {
        printf("\n NO DATA AVAILABLE TO BE DELETED !!!\n");
        return;
    }
    Display(p,seat);
    int id;
    struct Passenger temp;
    printf("Enter Location to Delete Data : ");
    scanf("%i",&id);
     if(id < 0 || id > seat)
    {
        printf("Invalid position! Please enter position between 1 to %d", seat);
    }
    else
    {
        /* Copy next element value to current element */
        for(i=id-1; i<seat-1; i++)
        {
            p[i] = p[i + 1];
        }

        /* Decrement array size by 1 */
        seat--;

        /* Print array after deletion */
        printf("\n -- Data after delete -- \n");

        Display(p,seat);
    }
}

void Sort(int seat, struct Passenger p[])
{
    if (seat == 0)
    {
        printf("\n NO DATA AVAILABLE TO BE SORTED !!!\n");
        return;
    }
    int e =0;
    int k;
    do{
            struct Passenger temp;
            printf("\n");
            printf(" 1 - Sort by User Id\n");
            printf(" 2 - Sort by Age\n");
            printf(" 3 - Sort by Seats \n");
            printf(" 4 - Back");
            printf("\nHow do you want to sort ? : ");
            scanf("%i",&k);
            if(k==1)
            {
                for (int i = 0; i < seat; i++)                     //Loop for ascending ordering
                {
                    for (int j = i+1; j < seat; j++)             //Loop for comparing other values
                    {
                        if (p[i].userid > p[j].userid)                //Comparing other array elements
                        {
                            temp = p[i];         //Using temporary variable for storing last value
                            p[i] = p[j];            //replacing value
                            p[j] = temp;             //storing last value
                        }
                    }
                }
            }
            else if (k==2)
            {
                for (int i = 0; i < seat; i++)   //Loop for ascending ordering
                {
                    for (int j = i+1 ; j < seat; j++)             //Loop for comparing other values
                    {
                        if (p[i].age > p[j].age)//Comparing other array elements
                        {
                             temp = p[i];         //Using temporary variable for storing last value
                            p[i] = p[j];            //replacing value
                            p[j] = temp;         //storing last value
                        }
                    }
                }
            }
            else if (k==3)
            {
                for (int i = 0; i < seat; i++)   //Loop for ascending ordering
                {
                    for (int j = i+1 ; j < seat; j++)             //Loop for comparing other values
                    {
                        if (p[i].seats > p[j].seats)//Comparing other array elements
                        {
                             temp = p[i];         //Using temporary variable for storing last value
                            p[i] = p[j];            //replacing value
                            p[j] = temp;         //storing last value
                        }
                    }
                }
            }
             else
            {
                break;
            }
             printf("\n -- Sorted Data -- \n");
            Display(p,seat);
    } while(k!=4);
}
void Search(struct Passenger p[],int seat)
{
    if (seat == 0)
    {
        printf("\n NO DATA AVAILABLE TO BE SEARCHED !!!\n");
        return;
    }
    int ch;
    int found;
    Display(p,seat);
    do{
        printf("\nWhat you want to search for ? ");
        printf(" \n 1 - User Id");
        printf(" \n 2 - Age");
        printf(" \n 3 - Seats");
        printf(" \n 4 - Name");
        printf(" \n 5 - Back");
        printf("\n Your choice : ");
        scanf("%d",&ch);
        if(ch ==1)
        {
            int id;
            found = 0;
            printf("Enter User ID to Search :");
            scanf("%d",&id);
            for(int i=0;i<seat;i++)
            {
                if(p[i].userid == id)
                {
                    found = 1;
                    printf("\n");
                    printf("\nSearch Key found !");
                    printf("\n -- Searched Data -- \n");
                    printf("\n  User ID  : %d ",p[i].userid);
                    printf("\n  Name     : %s ", p[i].p_name);
                    printf("\n  IC       : %s ", p[i].p_icno);
                    printf("\n  Age      : %d ", p[i].age);
                    printf("\n  Gender   : %c ", p[i].p_gender);
                    printf("\n  Passenger Type : %s ", p[i].p_type);
                    printf("\n  Seats    : %d \n",p[i].seats);
                    break;
                }
            }
            if(found == 0){
                printf("\n -- Sorry, no match found !!! --\n\n");
            }
        }
        else if(ch == 2)
        {
             int age;
             found = 0;
             printf("Enter Age to Search : ");
             scanf("%d",&age);

            for(int i=0;i<seat;i++)
            {
                if(p[i].age == age)
                {
                    found = 1;
                    printf("\n");
                    printf("\nSearch Key found !");
                    printf("\n -- Searched Data -- \n");
                    printf("\n  User ID  : %d ",p[i].userid);
                    printf("\n  Name     : %s ", p[i].p_name);
                    printf("\n  IC       : %s ", p[i].p_icno);
                    printf("\n  Age      : %d ", p[i].age);
                    printf("\n  Gender   : %c ", p[i].p_gender);
                    printf("\n  Passenger Type : %s ", p[i].p_type);
                    printf("\n  Seats    : %d \n",p[i].seats);
                }
            }
                if(found == 0){
                    printf("\n -- Sorry, no match found !!! --\n\n");
                }
        }
        else if(ch == 3)
        {
            int seatss;
             found = 0;
             printf("Enter Seats to Search : ");
             scanf("%d",&seatss);

            for(int i=0;i<seat;i++)
            {
                if(p[i].seats == seatss)
                {
                    found = 1;
                    printf("\n");
                    printf("\nSearch Key found !");
                    printf("\n -- Searched Data -- \n");
                    printf("\n  User ID  : %d ",p[i].userid);
                    printf("\n  Name     : %s ", p[i].p_name);
                    printf("\n  IC       : %s ", p[i].p_icno);
                    printf("\n  Age      : %d ", p[i].age);
                    printf("\n  Gender   : %c ", p[i].p_gender);
                    printf("\n  Passenger Type : %s ", p[i].p_type);
                    printf("\n  Seats    : %d \n",p[i].seats);
                    break;
                }
            }
            if(found == 0){
                    printf("\n -- Sorry, no match found !!! --\n\n");
                }
        }
         else if(ch == 4)
        {
            char name[100];
             found = 0;
             printf("Enter Name to Search : ");
             scanf(" %[^\n]s",&name);

            for(int i=0;i<seat;i++)
            {
                if(strcmp(p[i].p_name, name) == 0)
                {
                    found = 1;
                    printf("\n");
                    printf("\nSearch Key found !");
                    printf("\n -- Searched Data -- \n");
                    printf("\n  User ID  : %d ",p[i].userid);
                    printf("\n  Name     : %s ", p[i].p_name);
                    printf("\n  IC       : %s ", p[i].p_icno);
                    printf("\n  Age      : %d ", p[i].age);
                    printf("\n  Gender   : %c ", p[i].p_gender);
                    printf("\n  Passenger Type : %s ", p[i].p_type);
                    printf("\n  Seats    : %d \n",p[i].seats);
                    break;
                }
            }
               if(found == 0){
                    printf("\n -- Sorry, no match found !!! --\n\n");
                }
        }
    }while(ch!=5);
}

void Display(struct Passenger p[],int seat)
{
    if (seat == 0)
    {
        printf("\n NO DATA AVAILABLE TO BE DISPLAYED !!!\n");
        return;
    }
    printf("\n-----------------------------------------------------------------------------------------------------------");
    printf("\n| User Id |           Name            |  Age  |   IC Number   |   Gender   |    Passenger Type    |  Seats |");
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    for(int i = 0;i<seat;i++)
    {
        printf("  %6d %25s %9i %15s %10c %20s      %7d\n",p[i].userid, p[i].p_name, p[i].age, p[i].p_icno,p[i].p_gender, p[i].p_type,p[i].seats);
    }
    printf("-----------------------------------------------------------------------------------------------------------\n");
}
void push(int seat,struct Passenger p[])
{
    if(top>=seat-1)
    {
        printf("\n\Sorry.You cannot book seat anymore.");
    }
    else
    {
        printf(" Enter a seat number (1-300):");
        scanf("%d",&x);
        if (x > 300)
        {
         printf("\n\t Sorry.The above seat booking are not available ");
        }
        else if (x==stack[top])
        {
         printf("\n\t Sorry.The above seat already booked.Choose another seat. ");
        }
        else
        {
        top++;
        stack[top]=x;
        p[top].seats = x;
        printf("\n\t The seat--(%d)--are successfully booked",stack[top]);
        printf("\n\t Confirm your seat before proceeding to pick the next seat !\n");
        }
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Sorry.No seat founded for cancelation.");
    }
    else
    {
        printf("\n\t The --(%d)-- seat booking are successfully cancelled",stack[top]);
        top--;
    }
}
void displaySeats()
{
    if(top>=0)
    {
        printf("\n SEATS: \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n\n Press Next Choice");
    }
    else
    {
        printf("\n\n The SEAT is empty");
    }

}

struct Booking CalcTicket(struct Booking t,float pri)
{
     float ad,chil,snr,okut;
     ad  = t.c.adults * pri;
     t.c.f.adults_price = ad;
     chil = (t.c.children * pri * 0.8) ; //child 20% discount
     t.c.f.children_price = chil;
     snr = t.c.senior * pri * 0.7; // senior citizen 30% discount
     t.c.f.senior_price = snr;
     okut = t.c.oku * pri * 0.65; // OKU 35% discount
     t.c.f.oku_price = okut;
     float tot;
     tot = calculate(ad,chil,snr,okut);
     t.c.f.total = tot;
     return t;
}
float calculate(float ad, float chil, float snr, float okut)
{
    float w;
    w = ad + chil + snr + okut;
    return w;
}

int StateSelection()
{
    int a;
    int test =  1;
    while (test==1)
    {
        printf("  Which State Station do you wish to choose ? \n");
        printf("    1 - PERLIS \n");
        printf("    2 - KEDAH \n");
        printf("    3 - PENANG \n");
        printf("    4 - PERAK \n");
        printf("    5 - SELANGOR \n");
        printf("    6 - WILAYAH PERSEKUTUAN KUALA LUMPUR \n");
        printf("    7 - NEGERI SEMBILAN \n");
        printf("    8 - MELAKA \n");
        printf("Your option : ");
        scanf("%i",& a);
        if (a<1 || a>8)
        {
            printf(" INVALID INPUT!!! TRY AGAIN!!!\n");
            printf(" Input is between 1 - 8 !!! ");
            printf("\n");
            continue;
            //while (test==1) will loop back again
        }
        printf("\n");
        test=0; //exit looping if selection between 1-9
    }
    return a;
}

int StationSelection(int negeri)
{
    int b;
    printf("\n Which Station do you wish to travel ? : \n");
    if(negeri == 1 )    {
        printf(" 1 - Padang Besar \n 2 - Arau \n");
    }    else if(negeri == 2 )    {
        printf(" 1 - Anak Bukit \n 2 - Alor Setar \n 3 - Gurun \n 4 - Sungai Petani \n");
    }    else if (negeri ==3)    {
        printf(" 1 - Tasek Gelugor \n 2 - Bukit Mertajam \n 3 - Butterworth \n");
    }    else if (negeri == 4)    {
        printf(" 1  - Parit Buntar \n 2  - Bagan Serai \n 3  - Taiping \n 4  - Padang Rengas \n 5  - Kuala Kangsar \n 6  - Sungai Siput \n 7  - Ipoh \n 8  - Batu Gajah \n 9  - Kampar \n 10 - Sungkai \n 11 - Slim River \n 12 - Tanjung Malim\n");
    }    else if (negeri == 5)    {
        printf(" 1  - Rawang \n 2  - Sungai Buloh \n 3  - Kajang \n");
    }    else if(negeri == 6)    {
        printf(" 1  - Kepong Sentral \n 2  - Kuala Lumpur \n 3  - Bandar Tasek Selatan \n");
    }    else if (negeri == 7)    {
        printf(" 1  - Seremban \n 2  - Gemas \n");
    }    else if (negeri == 8)  {
        printf(" 1  - Pulau Sebang / Tampin \n 2  - Batang Melaka  \n");
    }
    printf(" Your option : ");
    scanf("%d",&b);
    return b;
}

void SetSchedule(int negeri,int station, struct Schedule train[])
{
    printf("\n");
    if(negeri == 1 ){
        if(station == 1){
            arraysize = 4;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Padang Besar ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"5h 40m");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1245;
            train[0].r.price = 64.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Padang Besar ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"5hr 42min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1615;
            train[1].r.price = 64.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Padang Besar ");
            strcpy(train[2].r.type,"Platinum 9274");
            strcpy(train[2].l.duration,"5hr 25min");
            train[2].l.departuretime = 920;
            train[2].l.arrivaltime = 1445;
            train[2].r.price = 85.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Padang Besar ");
            strcpy(train[3].r.type,"Platinum 9204");
            strcpy(train[3].l.duration,"5hr 42min");
            train[3].l.departuretime = 1825;
            train[3].l.arrivaltime = 2352;
            train[3].r.price = 85.00;
        }
        else{
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Arau   ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"5hr 22min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1227;
            train[0].r.price = 61.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Arau   ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"5hr 24min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1557;
            train[1].r.price = 61.00;
        }    }
    else if(negeri == 2 ) {
        if(station == 1) {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Anak Bukit ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"5hr 06min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1211;
            train[0].r.price = 59.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Anak Bukit ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"5hr 08min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1541;
            train[1].r.price = 59.00;
        }
        else if (station == 2) {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Alor Setar  ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"5hr 00min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1205;
            train[0].r.price = 58.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Alor Setar  ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"5hr 03min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1536;
            train[1].r.price = 58.00;
        }
        else if (station == 3) {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Gurun   ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"4hr 42min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1147;
            train[0].r.price = 53.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Gurun   ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"4hr 45min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1518;
            train[1].r.price = 53.00;
        }
        else {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Sungai Petani ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"4hr 30min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1135;
            train[0].r.price = 52.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Sungai Petani ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"4hr 33min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1506;
            train[1].r.price = 52.00;
        }    }
    else if (negeri ==3)  {
        if(station == 1)  {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Tasek Gelugor ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"4hr 18min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1123;
            train[0].r.price = 49.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Tasek Gelugor ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"4hr 21min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1454;
            train[1].r.price = 49.00;
        }
        else if (station == 2) {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Bukit Mertajam ");
            strcpy(train[0].r.type,"Platinum 9104");
            strcpy(train[0].l.duration,"3hr 59min");
            train[0].l.departuretime = 1105;
            train[0].l.arrivaltime = 1504;
            train[0].r.price = 65.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Bukit Mertajam ");
            strcpy(train[1].r.type,"Platinum 9372");
            strcpy(train[1].l.duration,"3hr 58min");
            train[1].l.departuretime = 1733;
            train[1].l.arrivaltime = 2131;
            train[1].r.price = 66.00;
        }
        else {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Butterworth  ");
            strcpy(train[0].r.type,"Platinum 9104");
            strcpy(train[0].l.duration,"4hr 11min");
            train[0].l.departuretime = 1105;
            train[0].l.arrivaltime = 1516;
            train[0].r.price = 67.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Butterworth  ");
            strcpy(train[1].r.type,"Platinum 9372");
            strcpy(train[1].l.duration,"4hr 09min");
            train[1].l.departuretime = 1733;
            train[1].l.arrivaltime = 2142;
            train[1].r.price = 68.00;
        }   }
    else if (negeri == 4) {
        if(station == 1)  {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Parit Buntar ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"3hr 48min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1053;
            train[0].r.price = 46.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Parit Buntar ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"3hr 55min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1428;
            train[1].r.price = 45.00;
        }
        else if (station == 2) {
            arraysize = 1;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Bagan Serai ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"3hr 40min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1045;
            train[0].r.price = 44.00;
        }
        else if (station == 3){
            arraysize = 4;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Taiping   ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"3hr 18min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1023;
            train[0].r.price = 40.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Taiping   ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"3hr 26min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1359;
            train[1].r.price = 40.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Taiping   ");
            strcpy(train[2].r.type,"Platinum 9104");
            strcpy(train[2].l.duration,"3hr 13min");
            train[2].l.departuretime = 1105;
            train[2].l.arrivaltime = 1418;
            train[2].r.price = 52.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Taiping   ");
            strcpy(train[3].r.type,"Platinum 9372");
            strcpy(train[3].l.duration,"3hr 12min");
            train[3].l.departuretime = 1733;
            train[3].l.arrivaltime = 2045;
            train[3].r.price = 53.00;
        }
        else if (station == 4) {
            arraysize =1;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Padang Rengas");
            strcpy(train[0].r.type,"Gold 9420");
            strcpy(train[0].l.duration,"3hr 15min");
            train[0].l.departuretime = 1033;
            train[0].l.arrivaltime = 1348;
            train[0].r.price = 37.00;
        }
        else if (station == 5) {
            arraysize = 4;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Kuala Kangsar ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"3hr 03min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 1008;
            train[0].r.price = 36.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Kuala Kangsar ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"3hr 09min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1342;
            train[1].r.price = 36.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Kuala Kangsar ");
            strcpy(train[2].r.type,"Platinum 9104");
            strcpy(train[2].l.duration,"2hr 57min");
            train[2].l.departuretime = 1105;
            train[2].l.arrivaltime = 1401;
            train[2].r.price = 47.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Kuala Kangsar ");
            strcpy(train[3].r.type,"Platinum 9372");
            strcpy(train[3].l.duration,"2hr 56min");
            train[3].l.departuretime = 1733;
            train[3].l.arrivaltime = 2029;
            train[3].r.price = 48.00;
        }
        else if (station == 6)  {
             arraysize = 1;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Sungai Siput ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"2hr 51min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 956;
            train[0].r.price = 34.00;
        }
        else if (station == 7)  {
            arraysize = 6;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Ipoh      ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"2hr 32min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 937;
            train[0].r.price = 31.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Ipoh      ");
            strcpy(train[1].r.type,"Gold 9022");
            strcpy(train[1].l.duration,"2hr 33min");
            train[1].l.departuretime = 850;
            train[1].l.arrivaltime = 1123;
            train[1].r.price = 33.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Ipoh      ");
            strcpy(train[2].r.type,"Gold 9420");
            strcpy(train[2].l.duration,"2hr 38min");
            train[2].l.departuretime = 1033;
            train[2].l.arrivaltime = 1311;
            train[2].r.price = 31.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Ipoh      ");
            strcpy(train[3].r.type,"Gold 9032");
            strcpy(train[3].l.duration,"2hr 33min");
            train[3].l.departuretime = 1900;
            train[3].l.arrivaltime = 2133;
            train[3].r.price = 33.00;

            strcpy(train[4].departure,"KL Sentral");
            strcpy(train[4].arrival,"Ipoh      ");
            strcpy(train[4].r.type,"Platinum 9104");
            strcpy(train[4].l.duration,"2hr 27min");
            train[4].l.departuretime = 1105;
            train[4].l.arrivaltime = 1332;
            train[4].r.price = 40.00;

            strcpy(train[5].departure,"KL Sentral");
            strcpy(train[5].arrival,"Ipoh      ");
            strcpy(train[5].r.type,"Platinum 9372");
            strcpy(train[5].l.duration,"2hr 26min");
            train[5].l.departuretime = 1733;
            train[5].l.arrivaltime = 1959;
            train[5].r.price = 40.00;
        }
        else if (station == 8) {
            arraysize = 6;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Batu Gajah ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"2hr 18min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 923;
            train[0].r.price = 29.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Batu Gajah ");
            strcpy(train[1].r.type,"Gold 9022");
            strcpy(train[1].l.duration,"2hr 19min");
            train[1].l.departuretime = 850;
            train[1].l.arrivaltime = 1109;
            train[1].r.price = 31.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Batu Gajah ");
            strcpy(train[2].r.type,"Gold 9420");
            strcpy(train[2].l.duration,"2hr 24min");
            train[2].l.departuretime = 1033;
            train[2].l.arrivaltime = 1257;
            train[2].r.price = 29.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Batu Gajah ");
            strcpy(train[3].r.type,"Gold 9032");
            strcpy(train[3].l.duration,"2hr 19min");
            train[3].l.departuretime = 1900;
            train[3].l.arrivaltime = 2119;
            train[3].r.price = 31.00;

            strcpy(train[4].departure,"KL Sentral");
            strcpy(train[4].arrival,"Batu Gajah ");
            strcpy(train[4].r.type,"Platinum 9104");
            strcpy(train[4].l.duration,"2hr 13min");
            train[4].l.departuretime = 1105;
            train[4].l.arrivaltime = 1318;
            train[4].r.price = 37.00;

            strcpy(train[5].departure,"KL Sentral");
            strcpy(train[5].arrival,"Batu Gajah ");
            strcpy(train[5].r.type,"Platinum 9372");
            strcpy(train[5].l.duration,"2hr 12min");
            train[5].l.departuretime = 1733;
            train[5].l.arrivaltime = 1945;
            train[5].r.price = 38.00;
        }
        else if (station == 9) {
            arraysize = 6;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Kampar      ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"2hr 05min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 910;
            train[0].r.price = 27.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Kampar      ");
            strcpy(train[1].r.type,"Gold 9022");
            strcpy(train[1].l.duration,"2hr 06min");
            train[1].l.departuretime = 850;
            train[1].l.arrivaltime = 1056;
            train[1].r.price = 29.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Kampar      ");
            strcpy(train[2].r.type,"Gold 9420");
            strcpy(train[2].l.duration,"2hr 11min");
            train[2].l.departuretime = 1033;
            train[2].l.arrivaltime = 1244;
            train[2].r.price = 27.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Kampar      ");
            strcpy(train[3].r.type,"Gold 9032");
            strcpy(train[3].l.duration,"2hr 06min");
            train[3].l.departuretime = 1900;
            train[3].l.arrivaltime = 2106;
            train[3].r.price = 29.00;

            strcpy(train[4].departure,"KL Sentral");
            strcpy(train[4].arrival,"Kampar      ");
            strcpy(train[4].r.type,"Platinum 9104");
            strcpy(train[4].l.duration,"2hr 00min");
            train[4].l.departuretime = 1105;
            train[4].l.arrivaltime = 1305;
            train[4].r.price = 34.00;

            strcpy(train[5].departure,"KL Sentral");
            strcpy(train[5].arrival,"Kampar      ");
            strcpy(train[5].r.type,"Platinum 9372");
            strcpy(train[5].l.duration,"2hr 05min");
            train[5].l.departuretime = 1733;
            train[5].l.arrivaltime = 1938;
            train[5].r.price = 35.00;
        }
        else if (station == 10) {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Sungkai      ");
            strcpy(train[0].r.type,"Gold 9022");
            strcpy(train[0].l.duration,"1hr 44min");
            train[0].l.departuretime = 850;
            train[0].l.arrivaltime = 1034;
            train[0].r.price = 24.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Sungkai      ");
            strcpy(train[1].r.type,"Gold 9032");
            strcpy(train[1].l.duration,"1hr 44min");
            train[1].l.departuretime = 1900;
            train[1].l.arrivaltime = 2044;
            train[1].r.price = 24.00;
        }
        else if (station == 11){
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Slim River ");
            strcpy(train[0].r.type,"Gold 9022");
            strcpy(train[0].l.duration,"1hr 31min");
            train[0].l.departuretime = 850;
            train[0].l.arrivaltime = 1021;
            train[0].r.price = 21.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Slim River ");
            strcpy(train[1].r.type,"Gold 9032");
            strcpy(train[1].l.duration,"1hr 44min");
            train[1].l.departuretime = 1900;
            train[1].l.arrivaltime = 2031;
            train[1].r.price = 21.00;
        }
        else{
            arraysize = 4;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Tanjung Malim");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"1hr 19min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 824;
            train[0].r.price = 18.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Tanjung Malim");
            strcpy(train[1].r.type,"Gold 9022");
            strcpy(train[1].l.duration,"1hr 28min");
            train[1].l.departuretime = 850;
            train[1].l.arrivaltime = 1008;
            train[1].r.price = 18.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Tanjung Malim");
            strcpy(train[2].r.type,"Gold 9420");
            strcpy(train[2].l.duration,"1hr 25min");
            train[2].l.departuretime = 1033;
            train[2].l.arrivaltime = 1158;
            train[2].r.price = 17.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Tanjung Malim");
            strcpy(train[3].r.type,"Gold 9032");
            strcpy(train[3].l.duration,"1hr 18min");
            train[3].l.departuretime = 1900;
            train[3].l.arrivaltime = 2018;
            train[3].r.price = 18.00;
        }
    }
    else if (negeri == 5) {
        if(station == 1)  {
            arraysize = 3;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Rawang      ");
            strcpy(train[0].r.type,"Gold 9022");
            strcpy(train[0].l.duration,"46min");
            train[0].l.departuretime = 850;
            train[0].l.arrivaltime = 936;
            train[0].r.price = 12.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Rawang      ");
            strcpy(train[1].r.type,"Gold 9420");
            strcpy(train[1].l.duration,"52min");
            train[1].l.departuretime = 1033;
            train[1].l.arrivaltime = 1125;
            train[1].r.price = 12.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Rawang      ");
            strcpy(train[2].r.type,"Gold 9032");
            strcpy(train[2].l.duration,"46min");
            train[2].l.departuretime = 1900;
            train[2].l.arrivaltime = 1946;
            train[2].r.price = 12.00;
        }
        else if (station == 2) {
            arraysize = 4;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Sungai Buloh ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"32min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 737;
            train[0].r.price = 11.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Sungai Buloh ");
            strcpy(train[1].r.type,"Gold 9022");
            strcpy(train[1].l.duration,"30min");
            train[1].l.departuretime = 850;
            train[1].l.arrivaltime = 920;
            train[1].r.price = 11.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Sungai Buloh ");
            strcpy(train[2].r.type,"Gold 9420");
            strcpy(train[2].l.duration,"36min");
            train[2].l.departuretime = 1033;
            train[2].l.arrivaltime = 1109;
            train[2].r.price = 11.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Sungai Buloh ");
            strcpy(train[3].r.type,"Gold 9032");
            strcpy(train[3].l.duration,"30min");
            train[3].l.departuretime = 1900;
            train[3].l.arrivaltime = 1930;
            train[3].r.price = 11.00;
        }
        else  {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Kajang      ");
            strcpy(train[0].r.type,"Gold 9425");
            strcpy(train[0].l.duration,"29min");
            train[0].l.departuretime = 2140;
            train[0].l.arrivaltime = 2209;
            train[0].r.price = 11.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Kajang      ");
            strcpy(train[1].r.type,"Platinum 9371");
            strcpy(train[1].l.duration,"29min");
            train[1].l.departuretime = 1217;
            train[1].l.arrivaltime = 1246;
            train[1].r.price = 12.00;
        }
    }
    else if(negeri == 6) {
        if(station == 1)  {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Kepong Sentral ");
            strcpy(train[0].r.type,"Gold 9022");
            strcpy(train[0].l.duration,"21min");
            train[0].l.departuretime = 850;
            train[0].l.arrivaltime = 911;
            train[0].r.price = 10.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Kepong Sentral ");
            strcpy(train[1].r.type,"Gold 9032");
            strcpy(train[1].l.duration,"21min");
            train[1].l.departuretime = 1900;
            train[1].l.arrivaltime = 1921;
            train[1].r.price = 10.00;
        }
        else if (station == 2) {
            arraysize = 6;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Kuala Lumpur  ");
            strcpy(train[0].r.type,"Gold 9222");
            strcpy(train[0].l.duration,"04min");
            train[0].l.departuretime = 705;
            train[0].l.arrivaltime = 709;
            train[0].r.price = 9.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Kuala Lumpur  ");
            strcpy(train[1].r.type,"Gold 9022");
            strcpy(train[1].l.duration,"04min");
            train[1].l.departuretime = 850;
            train[1].l.arrivaltime = 854;
            train[1].r.price = 9.00;

            strcpy(train[2].departure,"KL Sentral");
            strcpy(train[2].arrival,"Kuala Lumpur  ");
            strcpy(train[2].r.type,"Gold 9420");
            strcpy(train[2].l.duration,"04min");
            train[2].l.departuretime = 1033;
            train[2].l.arrivaltime = 1037;
            train[2].r.price = 9.00;

            strcpy(train[3].departure,"KL Sentral");
            strcpy(train[3].arrival,"Kuala Lumpur  ");
            strcpy(train[3].r.type,"Gold 9032");
            strcpy(train[3].l.duration,"04min");
            train[3].l.departuretime = 1900;
            train[3].l.arrivaltime = 1904;
            train[3].r.price = 9.00;

            strcpy(train[4].departure,"KL Sentral");
            strcpy(train[4].arrival,"Kuala Lumpur  ");
            strcpy(train[4].r.type,"Platinum 9104");
            strcpy(train[4].l.duration,"04min");
            train[4].l.departuretime = 1105;
            train[4].l.arrivaltime = 1109;
            train[4].r.price = 9.00;

            strcpy(train[5].departure,"KL Sentral");
            strcpy(train[5].arrival,"Kuala Lumpur  ");
            strcpy(train[5].r.type,"Platinum 9372");
            strcpy(train[5].l.duration,"04min");
            train[5].l.departuretime = 1733;
            train[5].l.arrivaltime = 1737;
            train[5].r.price = 9.00;
        }
        else {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Bandar Tasek Selatan");
            strcpy(train[0].r.type,"Gold 9425");
            strcpy(train[0].l.duration,"14min");
            train[0].l.departuretime = 2140;
            train[0].l.arrivaltime = 2154;
            train[0].r.price = 10.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Bandar Tasek Selatan");
            strcpy(train[1].r.type,"Platinum 9371");
            strcpy(train[1].l.duration,"14min");
            train[1].l.departuretime = 1217;
            train[1].l.arrivaltime = 1231;
            train[1].r.price = 9.00;
        }
    }
    else if (negeri == 7)  {
        if(station == 1)   {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Seremban      ");
            strcpy(train[0].r.type,"Gold 9425");
            strcpy(train[0].l.duration,"1hr 12min");
            train[0].l.departuretime = 2140;
            train[0].l.arrivaltime = 2209;
            train[0].r.price = 11.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Seremban      ");
            strcpy(train[1].r.type,"Platinum 9371");
            strcpy(train[1].l.duration,"1hr 12min");
            train[1].l.departuretime = 1217;
            train[1].l.arrivaltime = 1329;
            train[1].r.price = 12.00;
        }
        else   {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Gemas      ");
            strcpy(train[0].r.type,"Gold 9425");
            strcpy(train[0].l.duration,"2hr 19min");
            train[0].l.departuretime = 2140;
            train[0].l.arrivaltime = 2359;
            train[0].r.price = 27.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Gemas      ");
            strcpy(train[1].r.type,"Platinum 9371");
            strcpy(train[1].l.duration,"2hr 18min");
            train[1].l.departuretime = 1217;
            train[1].l.arrivaltime = 1435;
            train[1].r.price = 34.00;
        }
    }
    else if (negeri == 8) {
        if(station == 1) {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Pulau Sebang/Tampin");
            strcpy(train[0].r.type,"Gold 9425");
            strcpy(train[0].l.duration,"1hr 45min");
            train[0].l.departuretime = 2140;
            train[0].l.arrivaltime = 2325;
            train[0].r.price = 21.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Pulau Sebang/Tampin");
            strcpy(train[1].r.type,"Platinum 9371");
            strcpy(train[1].l.duration,"1hr 44min");
            train[1].l.departuretime = 1217;
            train[1].l.arrivaltime = 1401;
            train[1].r.price = 26.00;
        }
        else {
            arraysize = 2;
            strcpy(train[0].departure,"KL Sentral");
            strcpy(train[0].arrival,"Batang Melaka  ");
            strcpy(train[0].r.type,"Gold 9425");
            strcpy(train[0].l.duration,"2hr 00min");
            train[0].l.departuretime = 2140;
            train[0].l.arrivaltime = 2340;
            train[0].r.price = 24.00;

            strcpy(train[1].departure,"KL Sentral");
            strcpy(train[1].arrival,"Batang Melaka  ");
            strcpy(train[1].r.type,"Platinum 9371");
            strcpy(train[1].l.duration,"1hr 59min");
            train[1].l.departuretime = 1217;
            train[1].l.arrivaltime = 1416;
            train[1].r.price = 30.00;
        }  }
    DisplaySchedule(arraysize,train);
}

void DisplaySchedule(int arraysize, struct Schedule x[])
{
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("| Departure   |         Arrival       |     Train No     | Duration | Depart Time | Arrival Time | Price |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for (int i=0; i<arraysize; i++)
    {
        printf("%i. %11s %24s %16s %10s %10d %10d %13.2f \n",(i+1) ,x[i].departure,x[i].arrival,x[i].r.type,x[i].l.duration,x[i].l.departuretime,x[i].l.arrivaltime,x[i].r.price);
    }
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

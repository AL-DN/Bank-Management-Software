// Author: Alden Sahi
// Date: 05/11/2024
// Project Name: HotelManagement.c

#include <stdio.h>  // I/O lib
#include <stdlib.h> // allows a bunch of general functiong commonly used in c
#include <string.h> // allows the manipulation of strings
#include <ctype.h>  // used to test char. Input
#include <unistd.h>
#include <time.h> // allows use to use timing functions and such

int i, j;
int main_exit;
void closed();
void fordelay(int j);
void menu();
void new_acc();
void edit();
void transact();
void see();
void erase();
void view_list();

struct date
{
    int month, day, year;
};

struct
{
    char name[60]; // strings are arrays of char in c
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
} add, upd, check, rem, transaction;

unsigned int sec = 0; // unsigned means it cannot be assigned a value < 0
clock_t stopclock = CLOCKS_PER_SEC;

void main()
{
    char pass[15], password[15] = "iamlearning";
    int i = 0;
    printf("\n\n\t Enter the password to login :");
    printf("\033[8m"); // prints the octal number(leading 0) 33 +> ESC
    scanf("%s", pass); // since strings are already the mem addr of first char in array we do not need &
    printf("\033c");

    if (strcmp(pass, password) == 0)
    {
        // strcmp(first_str, second_str) returns
        // 0 when they are identitical
        // >0 when the first has a greater ASCII than the second str
        // <0 when the first has a smaller ASCII than the second str
        printf("\n\n Correct Password! Loading...");
        system("clear"); // clears console
        fordelay(5);
        menu(); // calls / opens menu
    }

    else
    {
        printf("/033c");
        printf("\n\n Wrong Password");
    login_try:
        printf("\n Enter 1 to try again and 0 to exit ");
        scanf("%d", &main_exit);

        if (main_exit == 1)
        {
            system("clear");
            main(); // calls the main method again
        }
        else if (main_exit == 0)
        {
            closed();
        }
    }
} // end of main

void menu()
{
    int choice;
    printf("\033c");
    system("clear");
    printf("\n");
    printf("\33[1;31m]"); // 1 - bold, 2-faint, 0-normal // 31-red, 32 green, 33- yellow
    printf("\n\n\t\t\t CUSTOMER ACCOUNT BAKING SYSTEM");
    printf("\n\n\n\t\t    \033[1;32m] WELCOME TO THE MENU");
    printf("\n\n\t\t 1. Create new account \n\t2.Update Information of Exisiting Account \n\t3. Transaction\n\t4. Check the Details of an Exisiting Account \n\t5. Remove Exisiting Account \n\t6. View Customer List\n\t 7. Exit \n\n\n\t\t Enter your choice : .");
    scanf("%d", &choice);
    printf("\033c");
    switch (choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        edit();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        closed();
        break;
    }
} // end of menu()

void fordelay(int j)
{
    while (sec < j) // starts at 0
    {

        if (clock() > stopclock)
        // if the number of ticks > the amount of ticks that happen in a second
        // considering that an if statment executes quicker than a second it will have to wait until it catches up,
        // effectively waiting a second until another second is added
        {
            stopclock += 100000; // == 1 sec => adds 1 mil clicks == speed of a 32 bit system
            printf(".");
            fflush(stdout); // this empties buffer before it reaches capacity ensuring each period is printed seperately
            // TO-DO: Wouldnt this increment sec while stopclock catches up to clock()?
            sec++; // increments
        }
    }
}

void new_acc()
{
    int choice;
    FILE *ptr;
    ptr = fopen("record.dat", "a+"); // a+ is a setting that points to the EOF or creates the file if it doesnt exist
account_no:                          // labels allows for jumps in c
    system("clear");
    printf("\t\t\t      ADD RECORD ");
    printf("\n\n\n Enter today's date (mm/dd/yyyy)");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("Enter Account number: ");
    while (fscanf(ptr, "%d %s %d %d %d %d %s %s %lf %s %f %d/%d/%d \n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        ;
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account Already Exists!");
            goto account_no; // jumps back to add record prompt
        }
    }
    add.acc_no = check.acc_no;
    printf("\n Enter the name");
    scanf("%s", add.name);
    printf("\n Enter the date of birth (mm/dd/yyyy) :");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\n Enter age :");
    scanf("%d", &add.age);
    printf("\n Enter the address :");
    scanf("%s", add.address);
    printf("\n Enter Citizienship Number: ");
    scanf("%s", add.citizenship);
    printf("\n Enter Phone Number: ");
    scanf("%lf", &add.amt);
    printf("\n Enter Account Type \n\t #Saving \n\t #Current \n\t #Fixed(Term: 1 YR)\n\t #Fixed(Term: 2 YR)\n\t #Fixed(Term: 3 YR): ");
    scanf("%s", add.acc_type);
    
    fprintf(ptr, "%d %s %d %d %d %d %s %s %lf %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    fclose(ptr);
    add_invalid:
    printf("\n Account created successfully !!");
    printf("\n\n\n\t Enter 1 to go to the main menu and 0 to Exit : ");
    scanf("%d", &main_exit);
    system("clear");
    if(main_exit==1)
    {
        menu();
    } 
    else if(main_exit == 0)
    {
        closed();
    } 
    else 
    {
        print("\n Invalid !");
        goto add_invalid ;
    }
}

void edit()
{
    

}

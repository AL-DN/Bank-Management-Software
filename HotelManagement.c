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
            main();
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
    printf("\33[1;31m]");
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
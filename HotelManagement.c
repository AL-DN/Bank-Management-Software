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
    char pass[15], password[15] = "iamlearning" int i = 0;
    printf("\n\n\t Enter the password to login :");
    printf("\033[8m");
    scanf("%s", pass);
    printf("\033c");

    if (strcmp(pass, password) == 0)
    {
        // strcmp(first_str, second_str) returns
        // 0 when they are identitical
        // >0 when the first has a greater ASCII than the second str
        // <0 when the first has a smaller ASCII than the second str
        printf("\n\n Correct Password! Loading...");
        system("clear"); // clears console

    }
}
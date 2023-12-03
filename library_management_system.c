#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

// Define Constant KeyWords
#define ENTER 13
#define TAB 9
#define BKSP 8

int main() {

    printf("Welcome to our Library Management System!\nLoading...\n");

    Sleep(2000);

    password();

    return 0;
}

// System Functions
    int passTerminator = 1;

// If the user enters invalid password 3 times then the program gets terminated.
// Password: manager
void password(){

    system("cls"); // clear screen
    fflush(stdin);

    char pwd[255];
    char code[255] = {"manager"};
    int i = 0;
	char ch;

    printf("--------------------\n");
    printf(">>> Login First <<<\n");
    printf("--------------------\n\n");

	printf("Enter your password. Hit ENTER to confirm. \n");
	printf("Password:");

	while(1)
    {

		ch = getch(); // get key

		if(ch == ENTER || ch == TAB)
        {
			pwd[i] = '\0';
			break;
		}
        else if(ch == BKSP)
        {
			if(i > 0)
            {
				i--;
				printf("\b \b"); // for backspace
			}
		}
        else
        {
			pwd[i++] = ch;
			printf("* \b");	// to replace password character with *
		}
	}

    fflush(stdin);

    // verifies the password
    if(strcmp(code, pwd) == 0)
    {
        printf("\nLogin Successful!\n");
        Sleep(2000);
        menu();
    }
    else
    {
        printf("\nInvalid Password!");
        (passTerminator == 3) ? exit(0) : passTerminator++;
        Sleep(2000);
        password();
    }
}

// Main Selection menu between User & Book Panel
void menu(){

    system("cls");
    fflush(stdin);

    int number;

    printf("----------------------------------\n");
    printf(">>> Library Management System <<< \n");
    printf("----------------------------------\n\n");
    printf("> 1. User Management Panel \n");
    printf("> 2. Book Management Panel \n\n");
    printf("> Enter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            printf("User panel\n");
            break;
        case 2:
            printf("Book panel\n");
            break;
        default:
            printf("\n>>> Invalid Input! <<<");
            Sleep(2000);
            menu();
    }
}


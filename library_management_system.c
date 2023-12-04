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
        printf("\nLogin Successful!\nLoading...\n");
        Sleep(2000);
        menu();
    }
    else
    {
        printf("\nInvalid Password!\n");
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
            userPanel();
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

// User Panel sub-functions
void userPanel(){

    system("cls");
    fflush(stdin);

    int number;

    printf("-----------------------------------------------\n");
    printf(">>> Library Management System - User Panel <<< \n");
    printf("-----------------------------------------------\n\n");
    printf("> 1. Add User \n");
    printf("> 2. Modify User \n");
    printf("> 3. List User \n");
    printf("> 4. List Rentals \n");
    printf("> 5. Search User \n");
    printf("> 6. Delete User \n");
    printf("> 7. Open Main Menu \n");
    printf("> 8. Close the Program... \n\n");

    printf("> Enter the number & hit ENTER: ");
    scanf("%d", &number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            printf("Add User\n");
            break;
        case 2:
            printf("Modify User\n");
            break;
        case 3:
            printf("List User\n");
            break;
        case 4:
            printf("Rent List\n");
            break;
        case 5:
            printf("Search User\n");
            break;
        case 6:
            printf("Delete User\n");
            break;
        case 7:
            menu();
            break;
        case 8:
            printf("End Screen\n");
            break;
        default:
            printf("Invalid Input!");
            Sleep(2000);
            userPanel();
    }
}



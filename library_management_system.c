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
            addUser();
            break;
        case 2:
            modifyUser();
            break;
        case 3:
            listUser();
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

// User Functions
// Creates new file if old does not exist and saves user records in it
void addUser(){

label1:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255];
    char gender;
    double sid, phone;

    FILE *pF = fopen("user_records.txt", "ab+");

    if(pF != NULL)
    {
        printf("Enter the First Name: ");
        gets(fname) ;

        printf("Enter the Last Name: ");
        gets(lname);

        printf("Enter Gender [M/F]: ");
        scanf("%c",&gender);

        printf("Enter Student ID: ");
        scanf("%lf",&sid);

        printf("Enter Phone Number: ");
        scanf("%lf",&phone);

        fprintf(pF, "%s %s %c %.0lf %.0lf \n", fname, lname, gender, sid, phone);

        printf("\n>>> User Record Added Successfully <<< \n");

    }
    else
    {
        printf("Unable to open/locate the file.");
    }

    fclose(pF);

    fflush(stdin);

    //retry screen
    char input;
    printf("\nDo you want to enter more records [y/N]: ");
    scanf("%c",&input);

    if(input == 'y' || input=='Y')
    {
        goto label1;
    }
    else if(input == 'n' || input == 'N')
    {
        printf("\nRedirecting to User Panel.");
        Sleep(2000);
        userPanel();
    }
    else
    {
        printf("\nInvalid input. Redirecting to User Panel.");
        Sleep(2000);
        userPanel();
    }
}

// Edit the user details and saves it
void modifyUser(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag = 0;

    char find[255];
    printf("Enter the name of the person you want to modify the detail: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Record Found, Allowing Modifications <<<\n");
            printf("-----------------------------------------------\n\n");

            printf("> Enter First Name: ");
            gets(fname1);

            printf("> Enter Last Name: ");
            gets(lname1);

            printf("> Enter Gender: ");
            gets(gender1);

            printf("> Enter Student ID: ");
            scanf("%lf",&sid1);

            printf("> Enter Phone Number: ");
            scanf("%lf",&phone1);

            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname1, lname1, gender1, sid1, phone1);
            printf("\n\nProcessing your changes....");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname, lname, gender, sid, phone);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("user_records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to User Panel...");
    }

    pF = fopen("user_records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", fname, lname, gender, sid, phone);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    fflush(stdin);

    Sleep(2000);
    userPanel();
}

// Lists all the user records from user_records.txt file
void listUser(){

    system("cls");
    fflush(stdin);

    FILE *pF = fopen("user_records.txt", "r");

    char fname[255], lname[255], gender[5];
    double sid, phone;
    int counter = 0;

    printf("-------------------------------\n");
    printf(">>> List of Users Record <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
       strcat(fname, " ");
       strcat(fname, lname);

        printf("-------------------------------\n");
        printf("> Full Name: %s \n", fname);
        //printf("> Last Name: %s \n", lname);
        printf("> Gender: %s \n", gender);
        printf("> Student-ID: %.0lf \n", sid);
        printf("> Phone No.: %.0lf \n", phone);
        printf("-------------------------------\n\n\n");

        counter++;
    }

    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no user records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("Press any key to get back to User Panel.\n");
    getch();
    userPanel();
}



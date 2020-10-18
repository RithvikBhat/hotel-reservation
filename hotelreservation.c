/*Hotel Reservation System*/

// Header files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>   // For changing Uppercase or lowercase letters
#include <windows.h> // Windows header file for easy access to API
#include <time.h>    // Time

//Structure Declaration (Customer details)
struct CustomerDetails
{
    char roomnumber[10];
    char name[20];
    char address[25];
    char phonenumber[15];
    char nationality[15];
    char email[20];
    char period[10];
    char arrivaldate[10];
} s;

// Functions
void screenheader(); // Name of Hotel
void intro();        // Amenities of Hotel
void login();        // Login Form
void bookroom();     // Booking Room
void viewrecord();   // View customer details
void deleterecord(); // Delete a particular customer detail
void searchrecord(); // Search for the Customer Details
void editrecord();   // Edit the customer details

//Main Function
void main()
{
    char customername;
    char choice;
    screenheader(); // Hotel Name
    intro();        // Amenities
    login();        // Login Form
    while (1)       // Infinte Loop for printing main menu
    {
        // Main Menu Layout
        printf("\n");
        printf("   ******************************  |MAIN MENU|  ***************************** \n");
        printf("\n");
        printf("\t\t       * Where would you like to navigate ? *");
        printf("\n\n");
        printf("\n\t\t\t Enter 1 -> Book a room");
        printf("\n\t\t\t-----------------------------------");
        printf("\n\t\t\t Enter 2 -> View Customer Record");
        printf("\n\t\t\t-----------------------------------");
        printf("\n\t\t\t Enter 3 -> Delete Customer Record");
        printf("\n\t\t\t-----------------------------------");
        printf("\n\t\t\t Enter 4 -> Search Customer Record");
        printf("\n\t\t\t-----------------------------------");
        printf("\n\t\t\t Enter 5 -> Edit Record");
        printf("\n\t\t\t-----------------------------------");
        printf("\n\t\t\t Enter 6 -> Exit");
        printf("\n\t\t\t-----------------------------------");
        printf("\n");

        choice = getche();        //To enter the choice (getche -> takes the keyboard value and echos(prints) it.)
        choice = toupper(choice); //To change character to uppercase

        // Switch statement
        switch (choice)
        {
        case '1':
            bookroom();
            break;
        case '2':
            viewrecord();
            break;
        case '3':
            deleterecord();
            break;
        case '4':
            searchrecord();
            break;
        case '5':
            editrecord();
            break;
        case '6':
            printf("\n\n\t   *****THANK YOU*****\n");
            printf("\n\t FOR TRUSTING OUR SERVICE");
            printf("\n\n");
            exit(0);
            break;
        default:
            printf("Incorrect Input");
            printf("\n Press any key to continue");
            getch();
        }
    }
}

//Heading: Welcome to World Hotels
void screenheader()
{

    printf("\n");
    printf("*************************************************************\n");
    printf("*                                                           *\n");
    printf("*                 Welcome to World Hotel                    *\n");
    printf("*                                                           *\n");
    printf("*************************************************************\n");
}

// Amenities of the hotel
void intro()
{
    int i = 0;
    time_t t; // Getting Real Time
    time(&t);
    printf("\n");
    printf("   -> Address   : Near Cauvery Emporium, M.G.Road, Bengaluru\n");
    printf("   -> Phone No. : 080-27223959\n");
    printf("   -> 100 % Power Back-up\n");
    printf("   -> AC Rooms available\n");
    printf("   -> Hot Water available 24x7\n");
    printf("   -> Automatic Lift\n");
    printf("   -> Ample Parking Space\n");
    printf("   -> Round the clock security\n");
    printf("   -> Free Wi-Fi available\n");
    printf("   -> 24 hours room service\n");
    printf("   -> Laundry service available\n");
    printf("\n");
    for (i = 0; i < 80; i++) // Printing Dashes we use for loop
        printf("-");
    printf("\nCurrent date and time : %s", ctime(&t)); // Printing Time
    for (i = 0; i < 80; i++)                           // Printing Dashes we use for loop
        printf("-");
    printf("\n");
    printf("Press on any character to continue\n");
    printf("\n");
    printf("\n");
    getch();
}

// Login Form Username ="user"  Password ="pass"
void login()
{

    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do
    {
        system("cls"); // Clear screen
        printf("\n");
        printf("   ******************************  |Login Form|  ***************************** \n");
        printf("\n                               ENTER USERNAME: ");
        scanf("%s", &uname);
        printf("\n                               ENTER PASSWORD: ");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*"); // Password should be invisible
            i++;
        }
        pword[i] = '\0';
        // End of string is null character'\0';
        i = 0;
        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0)
        {
            printf("\n\n\t\t\t  WELCOME! Successfully logged in! \n");
            printf("\n");
            break;
        }
        else
        {
            printf("\n\n\t\t\t    SORRY!  Login Unsuccessful. \n");
            printf("\n\t\t    Press on any character to retry logging in.\n");
            printf("\n");
            a++;
            getch();
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("Sorry!\n   Seems like you have entered the wrong username or password multiple times.\n   Please try again later.\n");

        getch();
    }
}

// Booking Room for customer. They have to enter the details.

void bookroom()
{
    // The word FILE is used for File handling i.e it is used for storing data in a file.
    // If we want to perform operations on a file,a special pointer called file pointer is used.

    FILE *f; // In this case *f is the pointer.
    char test;

    //fopen -> Opening of file,
    // a+ -> Searches file, if the file is opened successfully, fopen() loads data into memory and sets a pointer which points to the last character in it. If file doesn't exist, a new file is created. It returns NULL,if it is unable to open the file.

    f = fopen("add.txt", "a+"); // add.txt is name of file.

    if (f == 0) // if file is empty
    {
        f = fopen("add.txt", "w +"); // w+ -> Searches file, if file exists its contents are overwritten. Else, a new file is created. Returns NULL, if unable to open file.
        printf("Please hold on while we set our database in your computer!");
        printf("\n Process completed press any key to continue! ");
        getch();
    }
    while (1)
    {
        system("cls");
        printf("\n Enter Customer Details: \n");
        printf("\n**************************\n");
        printf("\n Enter Room number:\n");
        scanf("\n%s", s.roomnumber);

        printf("Enter Name:\n");
        scanf("%s", s.name);
        printf("Enter Address:\n");

        scanf("\n");
        scanf("%[^\n]%*c", s.address);
        // scanf("\n") is used before scanf("%[^\n]%*c") because at the end of each line, a new line character(\n) is present. So, the statement scanf("%[^\n]%*c") wont work if we dont add scanf("\n") before it, because the last statement will read a new line character from the previous line.

        printf("Enter Phone Number:\n");
        scanf("%s", s.phonenumber);
        printf("Enter Nationality:\n");
        scanf("%s", s.nationality);
        printf("Enter Email:\n");
        scanf("%s", s.email);
        printf("Enter Period(|'x'| days):\n");
        scanf("%s", &s.period);
        printf("Enter Arrival date(dd/mm/yyyy):\n");
        scanf("%s", &s.arrivaldate);

        //Syntax: fwrite(const void *ptr,size_t size,size_t n, FILE *fp);
        // ptr->points to a particular block of memory which contains data items tobe written. In our case, contents of structure 's' is written into the file i.e (struct.CustomerDetails.s)
        // size-> number of bytes of each item to be written. Our case, sizeof(s).
        // n-> number of items to be written. In our case, n=1;
        // fp-> pointer to file where data items will be written. In our case 'f'.
        // On success, fwrite() returns the count of number of items successfully written to the file. On error, it returns number less than n.

        fwrite(&s, sizeof(s), 1, f); // function that writes the data specified by the pointer '&s'.

        printf("\n\n1 Room is successfully booked!!");
        printf("\n Press esc key to enter the Main Menu,  any other key to add another customer detail:");
        test = getche(); // characters entered will get stored in variable "test".

        if (test == 27) //  Upto 27 customer details can be written.
            break;
    }
    fclose(f); //close the file.
}

// View the records of a particular customer
void viewrecord()
{
    FILE *f;
    int i;
    if ((f = fopen("add.txt", "r")) == NULL) // read file.
        exit(0);                             // If file empty exit
    system("cls");

    // Print the customer details
    for (i = 0; i < 118; i++)
        printf("-");
    while (fread(&s, sizeof(s), 1, f) == 1)
    {
        printf("\n\n");
        printf("ROOMNUMBER  :\t%s\n", s.roomnumber);
        printf("NAME        :\t%s\n", s.name);
        printf("ADDRESS     :\t%s\n", s.address);
        printf("PHONENUMBER :\t%s\n", s.phonenumber);
        printf("NATIONALITY :\t%s\n", s.nationality);
        printf("EMAIL       :\t%s\n", s.email);
        printf("PERIOD      :\t%s\n", s.period);
        printf("ARRIVALDATE :\t%s\n", s.arrivaldate);
    }
    printf("\n");
    for (i = 0; i < 118; i++)
        printf("-");
    printf("\n      Press on any character to go back to the Main Menu............. \n");
    fclose(f);
    getch();
}

// Delete customer details from the database
void deleterecord()
{
    // We have to compare two files 'f' and 't' to find a match.
    FILE *f, *t;
    // creating one more variable to compare s.roomnumber
    char roomnumber[20];
    int i = 1;
    if ((t = fopen("temp.txt", "w")) == NULL) //w->write function
        exit(0);
    if ((f = fopen("add.txt", "r")) == NULL) //r->read function
        exit(0);
    system("cls");
    printf("Enter room number of hotel to delete from database: \n");
    scanf("%s", roomnumber);
    while (fread(&s, sizeof(s), 1, f) == 1)
    {
        // After comparing if it is equal, i=0
        if (strcmp(s.roomnumber, roomnumber) == 0)
        {
            i = 0;
            continue;
        }
        else
            fwrite(&s, sizeof(s), 1, t);
    }
    if (i == 1)
    {
        printf("\n\nRecords of Customer in this  Room number is not found!!\n");
        //remove("E:/file.txt");
        //rename("E:/temp.txt","E:/file.txt");
        printf("Please make sure you typed the room number correctly.\n");
        printf("\n      Press on any character to go back to the Main Menu ............. \n");
        getch();
        fclose(f);
        fclose(t);
        main();
    }
    fclose(f);
    fclose(t);
    remove("add.txt");             // Contact is deleted from "add.txt"
    rename("temp.txt", "add.txt"); // File is renamed "temp.txt" to add other contact details except the deleted one
    printf("\n\nThe Customer is successfully removed....\n");
    printf("\n      Press on any character to go back to the Main Menu ............. \n");
    fclose(f);
    fclose(t);
    getch();
}

// Search the contacts of a particuar room number
void searchrecord()
{
    system("cls");
    FILE *f;
    char roomnumber[20];
    int flag = 1;
    f = fopen("add.txt", "r+"); // r+ -> read and point to the first character

    if (f == 0)
        exit(0);
    printf("Enter Room number of the customer: \n");
    scanf("%s", roomnumber);
    while (fread(&s, sizeof(s), 1, f) == 1)
    {
        if (strcmp(s.roomnumber, roomnumber) == 0)
        {
            printf("\n\tRecord Found\n ");
            printf("\nRoom Number  :\t%s", s.roomnumber);
            printf("\nName         :\t%s", s.name);
            printf("\nAddress      :\t%s", s.address);
            printf("\nPhone number :\t%s", s.phonenumber);
            printf("\nNationality  :\t%s", s.nationality);
            printf("\nEmail        :\t%s", s.email);
            printf("\nPeriod       :\t%s", s.period);
            printf("\nArrival date :\t%s\n", s.arrivaldate);
            printf("\n      Press on any character to go back to the Main Menu ............. \n");
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\n\tRequested Customer could not be found!\n");
        printf("\n      Press on any character to go back to the Main Menu ............. \n");
    }
    getch();
    fclose(f);
}

//Edit Customer details
void editrecord()
{
    FILE *f;
    int k = 1;
    char roomnumber[20];
    long int size = sizeof(s);
    if ((f = fopen("add.txt", "r+")) == NULL)
        exit(0);
    system("cls");
    printf("Enter Room number of the customer to edit:\n\n");
    scanf("%s", roomnumber);
    while (fread(&s, sizeof(s), 1, f) == 1)
    {
        if (strcmp(s.roomnumber, roomnumber) == 0)
        {
            k = 0;
            printf("\nEnter Room Number  :");
            scanf("%s", &s.roomnumber);
            printf("\nEnter Name         :");
            scanf("%s", &s.name);
            printf("\nEnter Address      :");
            scanf("%s", &s.address);
            printf("\nEnter Phone number :");
            scanf("%s", &s.phonenumber);
            printf("\nEnter Nationality  :");
            scanf("%s", &s.nationality);
            printf("\nEnter Email        :");
            scanf("%s", &s.email);
            printf("\nEnter Period       :");
            scanf("%s", &s.period);
            printf("\nEnter Arrival date :");
            scanf("%s", &s.arrivaldate);

            /* fseek() is used to move file pointer associated with a given file to a specific position
    Syntax: int fseek(FILE *pointer, long int offset, int position)
    pointer: pointer to a FILE object that identifies the stream
    offset: number of bytes to offset from position.
    position: position from where offset is added.
    returns: zero,if successful, orelse it returns a non-zero value.
    Note:
    SEEK_END : It denotes end of the file.
    SEEK_SET : It denotes starting of file.
    SEEK_CUR : It denotes file pointer's current position.
    */

            fseek(f, size, SEEK_CUR);
            fwrite(&s, sizeof(s), 1, f);
            break;
        }
    }
    if (k == 1)
    {
        printf("\n\n\t\tThe record doesn't exist! \n");
        printf("\n      Press on any character to go back to the Main Menu ............. \n");
        fclose(f);
        getch();
    }
    else
    {
        fclose(f);
        printf("\n\n\t\tRecord has been edited successfully !\n");
        printf("\n      Press on any character to go back to the Main Menu ............. \n");
        getch();
    }
}

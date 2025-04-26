#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "records.h"

int main(int argc, char *argv[])
{
    /* 1. Declare variables here */

    FILE *file = NULL;
    int argcount = 0;
    int selection = 0;
    int size = 0;
    char key1[50] = "";
    char key2[50] = "";

    /* 2. Check command line arguments here. If a command line argument (for the file name) is missing, print out the following: ERROR: Missing file name and end the program */

    for (int i = 0; i < argc; i++)
    {
        file = fopen(argv[i], "r");
        if (file == NULL)
        {
            printf("ERROR: Missing file name\n");
        }
        else
        {
            argcount = i;
            break;
        }
    }

    /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */

    printf("Opening %s...\n", argv[argcount + 1]);
    file = fopen(argv[argcount + 1], "r");
    /* 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open file and end the program. */

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
    }

    /* 5. Do the following to load the records into an array of RouteRecords */

    // 5.1 Call createRecords(), which will read through the file once to find the total number of lines/records in the file. Use this count, to dynamically allocate memory for an array of RouteRecords. It returns a pointer to that array. Don't forget to rewind the file pointer.
    RouteRecord *records = createRecords(file);
    if (records == NULL)
    {
        printf("ERROR: Could not create records\n");
        fclose(file);
        return 1;
    }
    // 5.2 Call fillRecords() to go through the CSV file again to fill in the values. It will then return the actual number of items the array has. Recall that not all records in the original CSV file will be entered into the array. Print the number of unique routes operated by different airlines: Unique routes operated by airlines: ???
    size = fillRecords(records, file);
    // 5.3 Close the the file.

    /* 6. Create an infinite loop that will do the following: */
    while (1)
    {
        // 6.1 Call printMenu()
        printMenu();
        // 6.2 Ask the user to input a value for the menu
        printf("Enter your selection: ");
        scanf("%d", &selection);
        printf("\n");
        // 6.3 Handle the case in which a non-integer value is entered
        if (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5)
        {
            printf("ERROR: Invalid selection\n");
        }
        // 6.4 Create a switch/case statement to handle all the menu options
        switch (selection)
        {
        case 1:
            // 6.4.1 Each option requires the user to enter a search key
            printf("Enter origin: ");
            scanf("%s", key1);
            printf("\n");
            printf("Enter destination: ");
            scanf("%s", key2);
            printf("\n");
            searchRecords(records, size, key1, key2, ROUTE);
            break;
        case 2:
            // 6.4.1 Each option requires the user to enter a search key
            printf("Enter origin: ");
            scanf("%s", key1);
            printf("\n");
            searchRecords(records, size, key1, "", ORIGIN);
            break;
        case 3:
            // 6.4.1 Each option requires the user to enter a search key
            printf("Enter destination: ");
            scanf("%s", key1);
            printf("\n");
            searchRecords(records, size, key1, "", DESTINATION);
            break;
        case 4:
            // 6.4.1 Each option requires the user to enter a search key
            printf("Enter airline: ");
            scanf("%s", key1);
            printf("\n");
            searchRecords(records, size, key1, "", AIRLINE);
            break;
        case 5:
            // 6.4.1 Each option requires the user to enter a search key
            printf("Goodbye!\n");
            free(records);
            fclose(file);
            return 0;
            break;
        default:
            printf("ERROR: Invalid selection\n");
            break;
        }
        // 6.4.1 Each option requires the user to enter a search key
        // 6.4.2 Quit needs to free the array
    }

    return 0;
}
#include stdio.h
#include stdlib.h
#include string.h

#include "records.h"

RouteRecord *createRecords(FILE *file)
{
    char line[256];
    int count = 0;
    int[] passengers = {0, 0, 0, 0, 0, 0};
    char *month = '';
    char *token = '';
    int num = 0;
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        count++;
    }
    rewind(file);

    RouteRecord *records = malloc(count * sizeof(RouteRecord));
    records.passengers = passengers;
    return records;
}

int fillRecords(RouteRecord *r, FILE *file)
{
}

int findAirlineRoute(RouteRecord *r, int length, const char *origin, const char *destination, const char *airline, int curIndex)
{
    if (r.to == destination && r.from == origin && r.carrier == airline)
    {
        return curIndex;
    }
    else if (currIndex == length)
    {
        return -1;
    }
    else
    {
        return findAirlineRoute(r, length, origin, destination, airline, curIndex + 1);
    }
}

void searchRecords(RouteRecord *r, int length, const char *searchKey, SearchType type)
{
}

void printMenu()
{
    printf("\n\n######### Airline Route Records Database MENU #########\n");
    printf("1. Search by Route\n");
    printf("2. Search by Origin Airport\n");
    printf("3. Search by Destination Airport\n");
    printf("4. Search by Airline\n");
    printf("5. Quit\n");
    printf("Enter your selection: ");
}

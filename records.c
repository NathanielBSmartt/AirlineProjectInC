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
    char line[256];
    int month = 0;
    int count = 0;
    char *usg = '';
    char *fg = '';
    char *carrier = '';
    int[] passengers = {0, 0, 0, 0, 0, 0};
    fgets(line, sizeof(line), file); // Header line skip

    while (fgets(line, sizeof(line), file) != NULL)
    {
        month = atoi(strtok(line, ","));
        r[count].from = strtok(NULL, ",");
        r[count].to = strtok(NULL, ",");
        r[count].carrier = strtok(NULL, ",");
        passengers[month - 1] += atoi(strtok(NULL, ","));
        r[count].passengers[0] = passengers[month - 1];

        if (r[count].carrier.length == 2)
        {
            count++;
        }
    }
}

int findAirlineRoute(RouteRecord *r, int length, const char *origin, const char *destination, const char *airline, int curIndex)
{
    if (r.to == destination && r.from == origin && r.carrier == airline)
    {
        return curIndex;
    }else if(r.to == destination && r.from == origin && r.carrier == "")
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

void searchRecords(RouteRecord *r, int length, const char *key1, const char *key2, SearchType type)
{
    int index = 0;

    if (type == ROUTE)
    {
        while(index < length){
            if (r[index].to == key1 && r[index].from == key2)
            {
                printf("%s, %s, %s, %d\n", r[index].to, r[index].from, r[index].carrier, r[index].passengers);
                break;
            }
            index++;
        }
    }
    else if (type == ORIGIN)
    {
        while(index < length){
            if (r[index].from == key1)
            {
                printf("%s, %s, %s, %d\n", r[index].to, r[index].from, r[index].carrier, r[index].passengers);
                break;
            }
            index++;
        }
    }
    else if (type == DESTINATION)
    {
        while(index<length){
            if (r[index].to == key1)
            {
                printf("%s, %s, %s, %d\n", r[index].to, r[index].from, r[index].carrier, r[index].passengers);
                break;
            }
            index++;
        }
    }
    else if (type == AIRLINE)
    {
        while(index<length){
            if (r[index].carrier == key1)
            {
                printf("%s, %s, %s, %d\n", r[index].to, r[index].from, r[index].carrier, r[index].passengers);
                break;
            }
            index++;
        }
    }
}

static void printMenu()
{
    printf("\n\n######### Airline Route Records Database MENU #########\n");
    printf("1. Search by Route\n");
    printf("2. Search by Origin Airport\n");
    printf("3. Search by Destination Airport\n");
    printf("4. Search by Airline\n");
    printf("5. Quit\n");
    printf("Enter your selection: ");
}

int getSizeOfArray(FILE *file){
    char line[256];
    int count = 0;
    fgets(line, sizeof(line), file); // header skip
    while (fgets(line, sizeof(line), file) != NULL)
    {
        count++;
    }
    return count;
}
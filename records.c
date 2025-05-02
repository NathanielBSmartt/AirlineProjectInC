#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "records.h"

RouteRecord *createRecords(FILE *file)
{
    char line[256];
    int count = 0;
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        count++;
    }
    rewind(file);

    if (count == 0)
    {
        fprintf(stderr, "No records found in the file\n");
        return NULL;
    }

    RouteRecord *records = (RouteRecord *)malloc(count * sizeof(RouteRecord));

    if (records == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            records[i].passengers[j] = 0;
        }
    }

    return records;
}

int fillRecords(RouteRecord *r, FILE *file)
{
    char line[256];
    char usg[6] = "";
    char fg[6] = "";
    char carrier[6] = "";
    char *token = NULL;
    int month = 0;
    int count = 0;
    int passengers = 0;
    int index = 0;
    fgets(line, sizeof(line), file); // Header line skip

    while (fgets(line, sizeof(line), file) != NULL)
    {

        token = strtok(line, ",");
        if (token == NULL)
            continue;
        month = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strncpy(usg, token, 3);
        usg[3] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        strncpy(fg, token, 3);
        fg[3] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        token[strlen(token)] = '\0';
        strcpy(carrier, token);

        if (strlen(token) != 2)
        {
            continue;
        }

        token = strtok(NULL, ",");
        if (token == NULL)
            continue;
        passengers = atoi(token);

        index = findAirlineRoute(r, count, usg, fg, carrier, 0);

        if (index == -1)
        {
            index = count;
            strcpy(r[index].from, usg);
            strcpy(r[index].to, fg);
            strcpy(r[index].carrier, carrier);
            count++;
        }

        if (month >= 1 && month <= 6)
        {
            r[index].passengers[month - 1] += passengers;
        }
    }
    return count;
}

int findAirlineRoute(RouteRecord *r, int length, const char *origin, const char *destination, const char *airline, int currIndex)
{
    if (currIndex >= length)
        return -1;

    if (strcmp(r[currIndex].from, origin) == 0 && strcmp(r[currIndex].to, destination) == 0 && strcmp(r[currIndex].carrier, airline) == 0)
    {
        return currIndex;
    }

    return findAirlineRoute(r, length, origin, destination, airline, currIndex + 1);
}

void searchRecords(RouteRecord *r, int length, const char *key1, const char *key2, SearchType type)
{
    double total = 0;
    double avg = 0;
    int found = 0;
    int matches = 0;
    int monthly[6] = {0, 0, 0, 0, 0, 0};
    char months[6][25] = {"January", "February", "March", "April", "May", "June"};

    for (int i = 0; i < length; i++)
    {
        switch (type)
        {
        case ROUTE:
            found = (strcmp(r[i].from, key1) == 0 && strcmp(r[i].to, key2) == 0);
            break;
        case ORIGIN:
            found = (strcmp(r[i].from, key1) == 0);
            break;
        case DESTINATION:
            found = (strcmp(r[i].to, key1) == 0);
            break;
        case AIRLINE:
            found = (strcmp(r[i].carrier, key1) == 0);
            break;
        }
        if (!found)
            continue;

        printf("%s (%s-%s) ", r[i].carrier, r[i].from, r[i].to);
        matches++;

        for (int j = 0; j < 6; j++)
        {
            monthly[j] += r[i].passengers[j];
        }
    }

    printf("\n\n%d record%s found.\n\n", matches, matches == 1 ? "" : "s");

    if (matches == 0)
    {
        printf("No records found.\n");
        return;
    }

    for (int j = 0; j < 6; j++)
    {
        total += monthly[j];
    }

    avg = total / 6.0;

    printf("Statistics:\n");
    printf("Total Passengers: %10.0lf\n", total);

    for (int i = 0; i < 6; i++)
    {
        printf("Pasengers in %s: %10d\n", months[i - 1], monthly[i]);
    }

    printf("Average Passengers per month: %10d\n", (int)avg);
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

int getSizeofArray(FILE *file)
{
    char line[256];
    int count = 0;
    fgets(line, sizeof(line), file); // header skip
    while (fgets(line, sizeof(line), file) != NULL)
    {
        count++;
    }
    return count;
}

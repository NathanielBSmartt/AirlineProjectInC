#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef RECORDS_H
#define RECORDS_H

struct RouteRecord
{
    char to[4];
    char from[4];
    char carrier[3];
    int passengers[6];
};
typedef struct RouteRecord RouteRecord;

typedef enum SearchType
{
    ROUTE,
    ORIGIN,
    DESTINATION,
    AIRLINE
} SearchType;

RouteRecord createRecords(FILEfile);
int fillRecords(RouteRecord r, FILEfile);
int findAirlineRoute(RouteRecord r, int length, const charorigin, const char destination, const charairline, int currIndex);
void searchRecords(RouteRecord r, int length, const charkey1, const char key2, SearchType type);
void printMenu(void);
int getSizeofArray(FILEfile);

#endif

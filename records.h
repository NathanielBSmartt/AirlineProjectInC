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

RouteRecord *createRecords(FILE *file);
int fillRecords(RouteRecord *r, FILE *file);
int findAirlineRoute(RouteRecord *r, int length, const char *origin, const char *destination, const char *airline, int currIndex);
void searchRecords(RouteRecord *r, int length, const char *key1, const char *key2, SearchType type);
void printMenu(void);
int getSizeofArray(FILE *file);

#endif

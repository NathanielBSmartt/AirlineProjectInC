#include stdio.h
#include stdlib.h
#include string.h
#ifndef RECORDS_H
#define RECORDS_H

struct RouteRecord
{
    char *to;
    char *from;
    char *carrier;
    int[6] passengers;
} typedef struct RouteRecord RouteRecord;

typedef enum SearchType
{
    ROUTE,
    ORIGIN,
    DESTINATION,
    AIRLINE
} SearchType;

RouteRecord *createRecords(FILE *file);
int fillRecords(RouteRecord *r, FILE *file);
int findAirlineRoute(RouteRecord *r, int length, const char *origin, const chat *destination, const char *airline, int curIndex);
void searchRecords(RouteRecord *r, int length, const char *searchKey, SearchType type);
void printMenu(void);

#endif
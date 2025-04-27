CC = gcc
CFLAGS = -Wall -g

TARGET = driver

SOURCE = main.c records.c
OBJECT = $(SOURCE:.c=.o)

all:

	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

run:all
	
	./${TARGET} data-2024.csv

clear:
	rm -f ${TARGET} $(OBJECT)

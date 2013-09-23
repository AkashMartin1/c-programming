/***************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 1 2013 Assignment #1 
* Full Name        : Kiriti Kunapareddy
* Student Number   : 3382421
* Yallara Username : s3382421
* Course Code      : COSC-1084
* Program Code     : BP094SEC8
* Start up code provided by Paul Miller and Xiaodong Li
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>

/* constants go here */
#define NUM_OPTION_STATS 5
#define MAX_INPUT_VALUE 6
#define MIN_INPUT_VALUE 1
/* This is used to compensate for the extra character spaces taken up by
   the '\n' and '\0' when user is asked for input through fgets(). */
#define EXTRA_SPACES 2

/* Specifies the maximum input length a user can enter for the options
   menu. */
#define MAX_OPTION_INPUT 1
#define MAX_INT_SIZE 10
#define MAX_STRING_SIZE 20
#define MAX_SIZE 20   
#define MAX 20
#define MAX_TEXT_SIZE 200
#define true 1
#define false 0   


/* provides us with a BOOLEAN type for using TRUE and FALSE */
typedef enum true_false
{
    FALSE=0,TRUE
} BOOLEAN;

/* function prototypes for each option to be implemented */
void perfect_squares(int * option_stats, unsigned number);
void ascii_to_binary(int * option_stats, char * ascii);
void matching_brackets(int * option_stats, char * test_string);
void format_text(int * option_stats, unsigned width, char * text);
void session_summary(int * option_stats);

/* function prototypes for additional functions contained in utility1.c */
void read_rest_of_line(void);

/* functions that I have implemented */
void read_rest_of_line();
int *getInput();
char *getString();
char *getText();
void initateOptions();
void push(char a);
char pop();


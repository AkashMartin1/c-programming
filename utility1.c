/***************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 2 2013 Assignment #1 
* Full Name        : Kiriti Kunapareddy
* Student Number   : 3382421
* Yallara Username : 3382421
* Course Code      : COSC-1084
* Program Code     : BP094SEC8
* Start up code provided by Paul Miller and Padgham
***************************************************************************/
#include "assign1.h"

/***********i**************************************************************
* read_rest_of_line() - clear the buffer of any leftover input. Call this 
* function whenever you detect leftover input in the buffer.
**************************************************************************/
void read_rest_of_line(void)
{
    int ch;
    /* read characters one at a time from standard input until there are
     * no characters left to read
     */
    while (ch=getc(stdin), ch!=EOF && ch!='\n');
    /* reset the error status of the input FILE pointer */
    clearerr(stdin);
}

/* Function getIntInput gets keyboard input from user with an int */
int *getInput(int *Input) {
    char tString[MAX_INT_SIZE + EXTRA_SPACES];
    int x;
    
    fgets(tString, MAX_INT_SIZE + EXTRA_SPACES, stdin); 


    /* Buffer overflow check */
    if(tString[strlen(tString)-1] != '\n') {
        read_rest_of_line();
        tString[0] = '-';
        tString[1] = '1';
        }
    

    /* if line break detected, program reads -2 and returns to main menu */
    

    else if(tString[0] == '\n') {
        tString[0] = '-';
        tString[1] = '2';
        } else if(tString[0] == EOF) {
            tString[0] = '-';
            tString[1] = '1';
            }
        else  {
            for (x = 0; x < strlen(tString); x++ ) {
                if(tString[x] == EOF) {
                    tString[0] = 0;
                    }
                }
            } 

    /* converting from string to int */
    *Input = atoi(tString);
        
    return Input;

}



/*function to get string input*/
char *getString(char *stringInput) {
	fgets(stringInput, MAX_STRING_SIZE + EXTRA_SPACES, stdin);
	
	/*buffer overflow check*/
	if(stringInput[strlen(stringInput) - 1] != '\n') {
		printf("String was too long!\n");
		read_rest_of_line();
		stringInput[0] = '\0';
		}
	return stringInput;
} 

/*function to get string input*/
char *getText(char *stringInput) {
	fgets(stringInput, MAX_TEXT_SIZE + EXTRA_SPACES, stdin);
	
	/*buffer overflow check*/
	if(stringInput[strlen(stringInput) - 1] != '\n') {
		printf("String was too long!\n");
		read_rest_of_line();
		stringInput[0] = '\0';
		}
	return stringInput;
}    

/* initiate option_stats*/
void initateOptions(int * option_stats) {
    int i;
    for(i=0; i < NUM_OPTION_STATS; i++) {
        option_stats[i] = 0;
        }
        return;
    }

int top = -1;
char stack[MAX_SIZE];
/*stack implementation of push and pop*/
void push(char item) {
    
/*pusch function*/
    if(top == (MAX_SIZE-1)) {
        printf("Stack Overflow\n");
        } else {
            top = top+1;
            stack[top] = item;
		
            }
    }
/*pop function*/
char pop(){
  char c;
  if(top == -1) 
      printf("Stack Undeflow\n");
       else 
         c = stack[top--];
         return c;
          }




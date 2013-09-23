/***************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 2 2013 Assignment #1 
* Full Name        : Kiriti Kunapareddy
* Student Number   : 3382421
* Yallara Username : s3382421
* Course Code      : COSC-1084
* Program Code     : BP094SEC8
* Start up code provided by Paul Miller and Lin Padgham
***************************************************************************/
#include "assign1.h"


int main(void)
{

    /*used for session summary*/
    int option_stats[NUM_OPTION_STATS];
    /* loop for displaying the main menu and running the selected
     * option here */

    /*declaration of variables*/
    
    int numInt;
    int done = FALSE; 
    int Input;
    char brackets[MAX_SIZE + EXTRA_SPACES];
    char stringInput[5+2];
    unsigned width =0;
    char text[MAX_TEXT_SIZE + EXTRA_SPACES];
    
    
   /*used for session summary*/ 
    initateOptions(option_stats);


    /*do while loop used for main menu functionality*/
    do {
        printf("\nMain Menu:\n");
        printf("1. Perfect Squares\n");
        printf("2. ASCII to Binary Generator\n");
        printf("3. Matching Brackets\n");
        printf("4. Formatting Text\n");
        printf("5. Session Summary\n");
        printf("6. Exit\n\n");

        printf("Select Your Option:");
        getInput(&numInt);

        switch(numInt) {
            case 1: /*Perfect Squares*/
                    Input = 0;
                    perfect_squares(option_stats, Input);
                    break;
            case 2: /*ASCII to Binary*/
                    ascii_to_binary(option_stats, stringInput);
                    break;
	        case 3: /*Matching Bracket*/
        		    matching_brackets(option_stats, brackets);
		            break;
            case 4: /*formatting text*/
                    format_text(option_stats, width, text);
                    break;
            case 5: /*Session Summary*/
                    session_summary(option_stats);
                    break;
            case 6: /*exit*/
                    return EXIT_SUCCESS;
                    done = TRUE;
                    break;
            }
        /* input validation for menu options */
        if(numInt > MAX_INPUT_VALUE || numInt < MIN_INPUT_VALUE) {
            printf("Please Input Value Between 1 to 6\n");
            }

        } while(done == FALSE);
    /*returns exit as it is int main(void) function*/
    return EXIT_SUCCESS;
}

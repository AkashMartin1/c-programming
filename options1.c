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
#include <stdio.h>
#include <stdlib.h>
/***************************************************************************
* This source file contains important functions to be developed and
* used by various menu options, as indicated. Note that every
* function has as its first parameter the optionsStats array, which
* will be appropriately updated for later reporting of menu option 6.
* You may ignore this parameter and its relevance to each function
* until you develop the sessionSummary() function.
 **************************************************************************/

/**************************************************************************
* perfect_squares() - implements the "Perfect Squares" option (requirement 
* 2) from the main menu. You need to determine whether the number passed
* in is a perfect square and let the user know if it is or not. You also
* need to print the perfect square before and after this value. Finally
* you need to update the option_stats variable appropriately.
**************************************************************************/
void perfect_squares(int * option_stats, unsigned number)
{
	/*variable decleration*/
	int inpt;
	int minint = 1;
	int maxint = 1000000;
	int y, k, i, l, q, w, count = 0;
    int newline = -2, eof = -1;
    
	
	/*printf statments */
	printf("\nPerfect Squares\n");
	printf("---------------\n\n");
	printf("Enter A Positive Integer (1-1000000):");
	getInput(&inpt);

   if(inpt == newline || inpt == eof) {
       return;
       }
	/*input validation*/
	while(inpt < minint || inpt > maxint) {
		printf("\nInteger entered is not between 1-1000000!\n");
		printf("\nEnter A Positive Integer (1-1000000):");
		getInput(&inpt);
		}
	
	/*code for perfect square check*/
	for(y=0; y<=inpt; y++){
	   if(inpt == y * y) {
	   printf("\n%d is a perfect square\n", inpt);
       printf("Perfect square before: %u\n", ((y - 1) * (y - 1)));
       printf("Perfect square after: %u\n", ((y + 1) * (y + 1)));
       k=2;
       }

    } 
    /* code that checks for PF before not a perfect square */
    if(k != 2) {
        printf("\n%d is not a perfect square\n", inpt);
      
        for(l=1; l<inpt; inpt--) {
            for(i=0;i<=inpt;i++) {
                if(inpt == i*i) {
                    printf("Perfect Square before: %d\n", (i*i));
                    count++;   
                }
            }
                if(count==1)
                    { 
                        break;
            }
        }
        for (q=1; q<=inpt; inpt++) {
            for(w=0; w<=inpt; w++) {
                if(inpt == w*w) {
                    count++;
                        if(count==3) {
                            printf("Perfect Square after: %d\n", (w*w));
               }
                
           }
            
       }
            if(count == 3) {
                break;
                }
        }      
           
    }
    option_stats[0]++;
    
}
           

/**************************************************************************
* ascii_to_binary() - implements the "ASCII to Binary Generator" option
* (requirement 3) from the main menu. Essentially, you need to implement
* an algorithm for conversion of integers to binary and apply this to 
* every character in the input array (called 'ascii' here) and print out
* the result. Finally, you need to update the option_stats array 
* appropriately 
**************************************************************************/
void ascii_to_binary(int * option_stats, char * ascii)
{
    /*variable decleration*/
    char inpt[MAX_STRING_SIZE + EXTRA_SPACES];
    int maxint = 5;
    int minint = 1;
    int length;
    int i, j, temp,q,k;
    int a[20];
    
    /* printf statements*/
    printf("\nASCII to Binary Generator\n");
    printf("-------------------------\n\n");
    printf("Enter A String (1-5 characters):");
    getString(inpt);
  
    /* while loop for input validation*/
    while (strlen(inpt) < minint || strlen(inpt) > maxint) {
        printf("Input of Invalid Size\n");
        printf("Enter A String (1-5 characters):");
        getString(inpt);
        if(inpt[0] == '\n'  || inpt[0] == -1){
            return;
            }
        }

        printf("Binary Representation is: ");
        for(length = 0; length < strlen(inpt)-1; length++) {
            /*printf("%d ", inpt[length]);*/
            /* logic of binary representation*/
            temp = inpt[length];
            for(k=0;k<20;k++)
            {
                a[k]=0;
            }
            
            printf(" ");
                
            for(i = 1; temp!=0; ++i) {
                j = temp%2;
                a[i] = j;
                temp = temp/2;
                }
                for(q=8;q!=0;q--){
                 
                    if(a[q]!=1 && a[q]!=0){
                       a[q]=0;
                }
                }
                
                            i=9;
                /* printf("\n a[18] value is :%d\n ",a[18]); */
                for(j=i-1;j>0;--j) {
                    printf("%d", a[j]);
                   }
                   
                    }
             printf("\n");
             /*option stats ++ for session summary*/
             option_stats[1]++;
          }


/**************************************************************************
* matching_brackets() - implements the "Matching Brackets" option 
* (requirement 4) from the main menu. You need to implement an algorithm 
* which will parse a string passed in and determine whether the brackets 
* all match, including the type of brackets. You need to account for 
* {} [] () and you also need to allow for the nesting of brackets. 
* You need to tell the user whether the brackets match or not. Finally you
* need to update the option_stats array appropriately.
**************************************************************************/
void matching_brackets(int * option_stats, char * test_string)
{
     /*variable declerations*/
     char stringInput[MAX_STRING_SIZE + EXTRA_SPACES], tempstack;
     int minint = 1, maxint = 20, i, valid = true, stacktop =-1;
	
     /*printf statments for output*/   
     printf("\nMatching Brackets\n");
     printf("-----------------\n\n");
     printf("Enter a String (1-20 characters):");
     getString(stringInput);

     /*input validation*/
     while (strlen(stringInput) < minint || strlen(stringInput) > maxint) {
         printf("Input of invalid size\n");
         printf("Enter A String (1-20 characters):");
         getString(stringInput);
         
        }
        if(stringInput[0] == '\n' || stringInput[0] == EOF){
            return;
            }
     /*logic of brackets check which uses stack to implement*/    
     for(i =0; i < strlen(stringInput); i++) {
        if(stringInput[i]=='(' || stringInput[i]=='{' || stringInput[i]=='[') {
            /*push function*/
            push(stringInput[i]);
		stacktop = stacktop +1;
            }        
        if(stringInput[i]==')' || stringInput[i]=='}' || stringInput[i]==']') {
            if(stacktop==-1) {
                valid = false;
                } else {        
                    /*pop function*/
                    tempstack=pop();
			stacktop = stacktop - 1;
                    if(stringInput[i]==')' && (tempstack=='{' || tempstack == '[')) {
                        valid = false;
                        }
                    if(stringInput[i]=='}' && (tempstack=='(' || tempstack == '[')) {
                        valid = false;
                        }
                    if(stringInput[i]==']' && (tempstack=='(' || tempstack == '{')) {
                        valid= false;
                        }    
                }
          }
   }

        if(stacktop >=0 ){
            valid = false;
            }
        if(valid == true) {
                printf("Brackets Match!!\n");
                } else {
                    printf("Brackets Do Not Match!!\n");
                    }
    /*option stats incremented for session summary*/
    option_stats[2]++;
}


/**************************************************************************
* format_text() - implements the "Formatting Text" option (requirement 6)
* from the main menu. You will need to parse the text, adding newlines 
* so that no line is longer than "width" which means you will need to 
* replace the first white space character before this with the newline. You
* then need to insert extra spaces so that lines are spaced as evenly as 
* possible. Finally you want to update the option_stats array appropriately.
* 
**************************************************************************/
void format_text(int * option_stats, unsigned width, char * text)
{
    
   int row = 0;
   int col = 0, newline = -2;
   int i, minint = 1, maxint = 200, mintxt = 150, maxtxt = 200;
    
    printf("Formatting Text\n");
    printf("---------------\n\n");
    printf("Enter an integer (maximal number of chars per line):");
    getInput(&width);

    if(width == newline){
        return;
        }
    
	while(width < minint || width > maxint) {
        printf("Input of invalid size\n");
        printf("Enter an interger (maximal number of chars per line):");
        getInput(&width);
        }
    printf("Enter some sentences (between 150 - 200 chars):");
    getText(text);
    	while(strlen(text) < mintxt || strlen(text) > maxtxt) {
        printf("Input of invalid size\n");
        printf("Enter some sentences (between 150 -200 chars):");
        getText(text);
        }  

       
    
   printf("width is %u", width); 
   printf("Formated\n\n");


   for(i = 0; i < strlen(text); i++) {
       
       
       printf("%c", text[i]);
       col++;
       row++;

       if(col == width) {
           printf("\n");
           col = 0;
           }
           
       }
    
    
    
    
    
    
    
    
    
    
    
    
    option_stats[3]++;
}

/**************************************************************************
* session_summary() - implements the "Session Summary" option (requirement
* 7) from the main menu. In this option you need to display the number of 
* times that each option has been run and then update the count of how 
* many times this function has been run.
**************************************************************************/
void session_summary(int * option_stats)
{
    
    int x;
    option_stats[4]++;
    printf("\nSession Summary\n");
    printf("-----------------\n\n");
    printf("Option Count\n");
    printf("------ -----\n");

    for(x=0; x < NUM_OPTION_STATS; x++ ) {
        printf("%6.1d %5.1d \n", x+1, option_stats[x]);
    }
        
        return;
}

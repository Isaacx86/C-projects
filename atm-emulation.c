/* A C Program that Enable's bank customers to manage their personal identification Number */
/* Started 11/5/2020 7:15 PM */
/* Finished 11/5/2020 10:30PM */

/* Program used - Visual Studio code, Compiler used GCC */
/* Changes made to program 11/14/2020 - Fixed do while code indentation, deleted un-needed comments & changed incrementing value to be simpler */
/* Changes made to program 11/18/2020 - changed integer data type to arrays to be able to handle zeroes */

#include <stdio.h>
#include <stdlib.h> // needed for system call (cls ++ clear) and exit(0)
#define MAX 4
int main()
{
    int atm[4] = {1,2,3,4}; // Default pin
    int pin_select[4]; // temporary pin_select to check again atm
    int pin_change[4]; // Holds Pin Change
    int changed_pin[4]; // temporary storage of changed pin for error checking
    int option; // switch variable
    int successful_time =0; // successful time counter
    int unsuccessful_time =0; //  unsuccessful times counter
    int loop = 1; // Makes While Loop true
    int i; // used in for loop


    do //do while loop to keep running total
    {
        printf("*******************************************************************************************\n");
        printf("Please enter the menu option that corresponds with the number\n");
        printf("1. Enter the 4 digit Pin and verify its correct\n");
        printf("2. Change the 4 digit Pin\n");
        printf("3. Display the number of times that the PIN was entered successfully and Incorrectly\n");
        printf("4. Exit program\n\n");
        printf("*******************************************************************************************\n");
        printf("\nPlease enter your option:");

        scanf("%d",&option); //This function is scanning for menu options */

        getchar();// catches any characters entered
        system("CLS||clear"); //Clears any messages on standard output on both osx/unix and windows,


        switch ( option ) // Performs check on which value is entered then corresponds options
        {
            case 1:  // if (int == 2)
                printf("You entered option one, Please now enter your 4 digit pin\n");
                scanf("\n %1d%1d%1d%1d",&pin_select[0],&pin_select[1],&pin_select[2],&pin_select[3]); // assigns each aray type a number
                printf("You have entered %1d%1d%1d%1d\n",pin_select[0],pin_select[1],pin_select[2],pin_select[3]); // prints each array selection

                if(atm[0]==pin_select[0]&&atm[1]==pin_select[1]&&atm[2]==pin_select[2]&&atm[3]==pin_select[3]) // checks default ATM value against entered value
                {
                    printf("You entered the correct pin\n");
                    successful_time++;
                }
                else// This statement is checking if atm is not == pin select and the user output it gives
                {
                    printf("You have incorrectly entered your pin\n");
                    unsuccessful_time++;
                }
                break; // Break is at the end of each case value and default value, it is used for terminating the loop of the switch statement

            case 2: // if (int == 2)
                printf("You have entered option two too change your pin\n");
                printf("Please enter your new 4 digit pin:\n");
                scanf("\n %1d%1d%1d%1d",&pin_change[0],&pin_change[1],&pin_change[2],&pin_change[3]);// This awaits user input for a pin change

                // ensures 4 arrays ( Also error handling )
                if(pin_change[4])
                {
                    printf("Please reinput the pin:\n");
                    scanf("\n %1d%1d%1d%1d",&changed_pin[0],&changed_pin[1],&changed_pin[2],&changed_pin[3]); // Changed pin that later checks itself the pin change
                }
                else // Defines incorrect input of pin
                {
                    printf("You have incorrectly entered the pin, please make sure it is 4 digits!\n");
                }

                // Ensures digits are between 999 and 10000 and checks itself against changed pin
                if(changed_pin[0]==pin_change[0]&&changed_pin[1]==pin_change[1]&&changed_pin[2]==pin_change[2]&&changed_pin[3]==pin_change[3])
                {
                    printf("Verification complete your new pin is now %1d%1d%1d%1d\n",pin_change[0],pin_change[1],pin_change[2],pin_change[3]);

                    for(i=0; i<MAX;i++)// this is the for loop too change the values of i too the correct interger, this will loop through i and put the values in its place.
                    { 
                        atm[i]=pin_change[i]; // this is the user's new up-to date pin
                    }
                }

                else// This else statement tell's the user that they entered the 4 digit pin incorrectly on any occasion
                {
                    printf("Verification could not complete, please make sure too input the 4 digit pin correctly!\n");
                }
                break;

            case 3: // if (int == 3)
                printf("The pin has been entered %d Successful times and %d Unsuccessful times\n\n",successful_time,unsuccessful_time);
                break;

            case 4: // if (int == 4)
                printf("The Program will now be exited!\n");
                exit(0); // this is a system call that will exit the application smoothly with no errors to show
                break;

            default: // This default statement is displayed if incorrect syntax is used e.g random letters, or a long string of numbers
                printf("Invalid operator\n"); // error handling message
                break;
    }

    }while(loop == 1); // loop repeats once value is = 1, (defined in variables)
    return 0; // final return value
}

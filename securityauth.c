/* Programming assignment2.c
This is a security authentication program, In this program the user will be asked to enter a four digit numerical only code, once the code has been verified as only being 4 digits, it will go back to the main menu option.
The second option to encrypt the code they have entered, If it does not compare or match too the encrypted value of 1234 which is 4523, the message that will be displayed tells the user the comparison is not the same, but will still output the encrypted code.
The third option for the user should be selected to decrypt the already encrypted number, there are no comparisons here, it will decrypt the code once the user has entered a code and encrypted it, the code cannot be decrypted if the encryption has not been ran in the first place.
The fourth option is for counting the amount of successful and unsucessful times the code has been compared too the value of 1234 correctly or incorrectly
The fifth and final option is the exiting option, this option will gracefully terminate the application 
Program author: Isaac Barry
Program creation 1/3/2021 - Program completion 4/3/2021 */

// These are the standard library inclusions for the program.
#include <stdio.h>
#include <stdlib.h>

#define PIN 4 // This is a macro within my code, the value of pin is 4, this means i can call pin anywhere in my code

// The following are my function signatures/prototypes in my code, what it does is creates the function with a returning value (int for number return and void for no specific value return)
int compare(int user_code[PIN],int access_code[PIN],int *correct,int *incorrect); // This is the comparison function prototype used in both encryption and decryption.
int enter_code(int user_code[PIN]); // This function is the user entered code option for menu option one.
int encrypt(int user_code[PIN]); // This function is for menu option 2 and will be used to encrypt the user supplied code.
int decrypt(int user_code[PIN]); // This function is for the menu option 3 and will be used to decrypt the user supplied code.
int counter(int *correct,int *incorrect); // This is the counter function, this is called in case 4 and in comparison for calculating the amount of times the code was successfully compared
void exit_app(); // This is for the final function 5, this will exit the code when option 5 is opted for 

int main() // main function
{

    int access_code[PIN]={4,5,2,3}; // Code that will be compared against
    int user_code[PIN]; // User inputted code

    int options; // switch statement value
    int loop =1; // While this is 1, the menu will continue to loop

    int i = 0; // this is the i used in every for loop value
    
    // The following three variables are error used in error checking, to ensure the encrypted code and decrypted code option cannot be selected without a valid user code, and making sure the decrypted code cannot be used without the encryption first. 
    int crypt_complete =0; 
    int decrypt_complete=0;
    int encrypt_needed =0;

    // correct and incorrect counter
    int correct = 0; 
    int incorrect = 0;


do{ // start of do loop 

    printf("\n*************************************************************************************************************************");
    printf("\n1. Enter any code\n");
    printf("2. Encrypt code entered and verify if correct (i.e., matches the authorised access code, i.e., 4523\n");
    printf("3. Decrypt code\n");
    printf("4. Display the number of times the encrypted code entered matches the authorised code (i) Successfully (ii) Incorrectly\n");
    printf("5. Exit Program\n");
    printf("*************************************************************************************************************************\n");

    scanf("%1d",&options); // scans the input for the menu option 
    getchar(); // This is for catching any char's entered into the options
    system("CLS||clear"); // this is a system call that will simply clear the screen 


    switch(options) // Start of switch statement, when for example 1 is entered, case 1 will be displayed
        {
        case 1:
            enter_code(user_code); // calling function enter_code
            crypt_complete=1; // Initializing these two functions too 1 too ensure that user_code must be inputed before encrypted and decrypting
            decrypt_complete=1;
            break; // the use of the break statement ends the process after all code in the case has been processed

        case 2:
            if(crypt_complete ==1){ // Only if crypt complete has the value of 1 (user code has been entered) will case 2 carry out 
                encrypt(user_code); // calling the encryption function passing user_code too it 
                compare(user_code,access_code,&correct,&incorrect); // calling the comparison function, using the predefined access_code which is comparing the values, the counter's are also included
                crypt_complete=0; // ensuring that the encryption function cannot be ran twice, the code must be re-entered
                encrypt_needed =1; // this ensures decryption cannot be ran without encryption
            }
            else if(encrypt_needed==0){
                printf("\n You must enter the code before encrypting it!\n");
            }            
            else{
                printf("\n Your code has already been Encrypted\n");
            }
            break;

        case 3:
            if(decrypt_complete ==1 &encrypt_needed==1){ // if usercode has been entered, and if encryption has been entered already, carry out code. 
                decrypt(user_code); // calls decrypt function for user_code
                decrypt_complete=0; // Initializing both functions to zero to ensure this case cannot be rerun without code entered and encryption entered.
                encrypt_needed=0;
            }
            else if(encrypt_needed==0){
                printf("\n You must encrypt your code before decrypting it!\n");
            }
            else{
                printf("\n Your Code Has Already Been Decrypted\n");
            }
            break;

        case 4:
            counter(&correct,&incorrect); // function for counting the correct comparisons using pointers.
            break;

        case 5:
            exit_app(); // This is the final function, this will be exiting the program when run.

        default: // This is the default statement, if incorrect input is detected within the menu, this will be displayed
            printf("Invalid statement, please try again\n");

        }
    }while(loop==1); // Finishing the do while loop - all code will be looped while loop = 1 


}

int compare(int user_code[PIN], int access_code[PIN], int *correct, int *incorrect) //Function for comparing unchanged access_code, with user supplied code, correct and incorrect pointers are counting correct and incorrect comparisons
{
    int i;
    int match =0; // This variable is used to ensure each value of user-code is equal to access_code
        for(i=0;i<PIN;i++){ // a for loop
            if(*(user_code+i) == *(access_code+i)){  // Using pointer notation too loop through each value of usercode to compare it too access code
                    match++; // because pin is initialized as 4, there can only be four or less matches, therefore for all array values to be the same, match has too = 4 
                }}

 
    if(match == 4) // there can only be four or less matches, therefore for all array values to be the same, match has too = 4 
    {
        printf(" The Correct Code has been entered\n");
        (*correct)++; // pointer to correct variable
    }
    else{ // This is for example if match is less than four, which means not all elements of the array are the same. 
        printf(" The Wrong Code has been entered\n");
        (*incorrect)++; // pointer to incorrect variable
    }
}
    // This function is asking for user input, and required the code to be entered
int enter_code(int user_code[PIN])
{
    int i;
    printf("You have selected option one \n");
    printf("Please enter any code:");
    for(i=0;i<PIN;i++) 
    {
        scanf("%1d",&*(user_code+i)); // a for loop which loops through using pointer notation of user_code
    }
}

int encrypt(int user_code[PIN]){ // This is the function for encrypting the user entered code

    int i = 0;  // for loop i 
    int temp[2]; // creating temp as an array of 2 
    
    // ENCRYPTION ALGORITHM

    // This is for swapping elements 1 and 3

    *(temp) = *(user_code); // pointer notation is being used to enter the first value of temp too the first value of user_code
    *(user_code) = *(user_code+2); // then because temp stores the first value of usercode, usercode value 3 is now passed though the 1'st value
    *(user_code+2) = *(temp); // and the end value of usercode value 3 is now changed too temp which contained the first element in the array

    // This is for swapping elements 2 and four
    *(temp+1) = *(user_code+1); // pointer notation is being used to enter the second element of temp into the second element of user_code
    *(user_code+1) = *(user_code+3); // user_code 2 is then being passed too the element of four because temp stored element 2
    *(user_code+3) = *(temp+1); // element 4 is then given the value of element 2 

    for(i=0;i<PIN;i++)
     {
         if((*(user_code+1)) == 10)
         {
             (*(user_code+i)) =0; // this is a for loop and if statement that ensures if user_code has a value greater than 10, it will change the value to 0 
         }
     }
    printf("\n Your Encrypted code is: ");
     for(i=0;i<PIN;i++)
    {
        (*(user_code+i))++; // this increments usercode by one, as this is the encryption algorithm
        printf("%1d",user_code[i]);
    }
    }


int decrypt(int user_code[PIN]){ // this is the decryption function, this will decrypt the user entered code. 

    int i = 0; // for loop i 
    int temp[2]; // creating temp as an array of 2 

    // DECRYPTION ALGORITHM
    // This is for swapping elements 1 and 3 
    *(temp) = *(user_code); // this will change the value of temp value 1, too user_code value 1
    *(user_code) = *(user_code+2); // then the first element of the user_code array will be initialized too the 3rd element of user_code
    *(user_code+2) = *(temp); // usercode position 3 will now be given the temp value of user_codes first value.

    // This is for swapping elements 2 and 4
    *(temp+1) = *(user_code+1); // This changes the value of temp value 2, too the user_codes second value.
    *(user_code+1) = *(user_code+3); // This will make the second value of the array equal too the fourth
    *(user_code+3) = *(temp+1); // and finally this will store the the second element of the array in the fourth by using the second value of temp

    // this is for making sure any number that has a value == too -1, will change to 9 
    for(i=0;i<PIN;i++)
     {
         if((*(user_code+1)) == -1)
         {
             (*(user_code+i)) =9; // a for loop stating if any element of the array is equal to -1, the element will be changed to 9
         }
     }
    printf("\n Your Decrypted code is: ");
     for(i=0;i<PIN;i++)
    {
        (*(user_code+i))--; // This for is ensuring too subtract one number from each array value
        printf("%1d",user_code[i]);
    }
    }

int counter(int *correct, int *incorrect) // this is the counter function that passes both variables through too list the correct and incorrect times of compared code
{
    printf("The number of correct matches are %d\n",*correct);
    printf("The number of incorrect matches are %d\n",*incorrect);
}

void exit_app() // this is the final function which will exit the program gracefully when the option is called. 
{
    printf("Thank you for using our application, this program will now be exited\n");
    exit(0);   
}

#include <stdio.h>      //This is a header which contains a library of functions for performing inputs and outputs,
                        //some variable types and several macros
#include <string.h>   //header file used to include the 'strstr' function

int main() {
    char line[600];  //Array created to hold the text which needs to be compared from the text file
    int exists = 0; //A condition was set for the different types of files

    FILE *fp;                                //A pointer was allocated to the file used
    fp = fopen("Textfile for 1c).txt", "r"); //Opens a file pointed to for reading

    if (fp == NULL)   //if the pointer points to nothing, meaning that the file foes not exist
    {
        printf("ERROR in opening file."); //the program will output an error showing the user that the file does not exist.
        return 0;                         //ends the program
    }

    while (!feof(fp)){          //if the file is found it will enter the while loop as long as it is not the end of the file
        fgets(line, 600, fp);   //gets a line, 600 characters long from the file

        if (strstr(line, "#include") != NULL) //the characters are compared and if the line includes #include the
                                              // variable 'exists' is set to 1
        {
            exists = 1;
            break;                      //if 'exists' is set to 1 the program will exit the while loop
        }

        if (strstr(line, "<html>") != NULL)//the characters are compared and if the line includes <html> the
                                           // variable 'exists' is set to 2
        {
            exists = 2;
            break;                       //if 'exists' is set to 2 the program will exit the while loop

        }
    }

    if (exists == 2) {                          //checks if after exiting the while loop, exists is set to 2
        if (strstr(line, "</html>") != NULL)    //compares the characters in the last line of the file which is still
                                                // stored in the array and if the line include </html> then exists is set to 3.
            exists = 3;

        else                                    //if after exiting the while loop the exists is set to 2 the program outputs
                                                //that the file is an incomplete HTML file as it only includes the <html>
            printf("The file is an incomplete HTML file");
    }
    if (exists == 1)                        //checks if after exiting the while loop the exists is set to 1
    {
        printf("This is a c file.");        //outputs that the file is a c file
    }

    if (exists == 3)                        //checks if after exiting the while loop the exists is set to 3
    {
        printf("The file is an HTML file"); //outputs that the file is an HTML file
    }

    if (exists == 0)                        //checks if after exiting the while loop the exists is set to 0
    {
        printf("This file is neither a C programming file nor an HTML file.");  //outputs that it an an 'other type' of file
                                                                                //as the program has not found any matching characters
                                                                                //and the value of the variable exists does not change
    }

}

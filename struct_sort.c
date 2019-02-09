/*
 * Project One: Structs and File I/O
 * This program sorts a list of contacts that are read in from a given file 
 * in the command line. The sorted information will be written to another file
 * called sorted contacts.txt. 
 *
 * @author Carlee Yancey
 * @author Every Ball
 * @version 1.0 (February 18, 2019)
 */
#include "struct_sort.h"
#include <stdio.h>

typedef struct{
    char street_add; //The street number and name that the person live on.
    char city; //City that the person lives in. 
    char state[STATE]; //State that person lives in.
    int zip_code[ZIP]; //Zip code that the person lives in.
}sddress_t //Makes a instance of a address for a person.

typedef struct{
    char first_name[NUM_PEOPLE]; //First name of person.
    char last_name[NUM_PEOPLE]; //Last name of person.
    addrees_t address; //Struct address of person.
    int number; //Phone number of the person.
}person_t; //Makes an instance of a person.

/*
 * This function runs the program.
 */
int main(int argc, char **argv){
    
    //Checking if correct number of command line arguments received
    // prints usage message and exits program if it is not
    if( 3 != argc ) {
        fprint("Usage is: struct_sort <inputFile> <outputFile>");
        return 0;
    }

    readFile(argv[1]);
    writeFile(argv[2]);

}

/*
 * This method does a quicksort on the given array of persons.
 *
 * @param  
 * @return
 */
void sort(person_t){

}

/*
 * This method is a helper method for sort. This swaps the places of two 
 * people.
 *
 * @param person1 The first person of the two that are being swaped.
 * @param person2 The second person ot the two that are being swaped.
 */
void swap(person_t *person1, person_t *person2){
    person_t temp = *person1;
    *person1 = *person2;
    *person2 = temp;
}

/*
 * This method reads data from an input file
 *
 * @param  
 * @return
 */
int readFile(char *inputFile) {
    
    FILE *input_p = fopen(inputFile, "r");

    char buff[100];

    while( fgets(buff, 100, input_p) != NULL ) {
        //writes to a file?
    }
}

/*
 * This method writes to a given file
 *
 * @param char* outputFile - the file to output to.
 * @return
 */
int writeFile(char *outputFile) {

}

//I think we may need another method that parses the file and updates the
//  different structs

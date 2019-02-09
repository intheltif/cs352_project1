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
    //if possible: writeFile(readFile(argv[1]), argv[2]) with adjustments

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
 * This reads in a file by a specified input file.
 *
 * @param *inputFile Is the address of the file that is being scaned in.
 * @return 
 */
int readFile(char *inputFile) {
    
    FILE *input_p = fopen(inputFile, "r");

    char buff[100];

    while( fgets(buff, 100, input_p) != NULL ) {
        //Use buff to update person struct
        //TODO: Figure out how each line is seperated, then use regex to split
    }
}

/*
 * This writes to a specified output file.
 *
 * @param *outputFile Is the address that the output is written to.
 * @return 
 */
int writeFile(char *outputFile) {

}

/*
 * This parses a specified array of characters (AKA a string)
 *
 * @param stringToParse The string to be parsed
 * @return
 */
void parseFile(char* stringToParse) {

    //Parses array, then updates structs based on that

}

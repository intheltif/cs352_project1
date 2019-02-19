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
#include <string.h>

/*
 * This function runs the program.
 */
int main(int argc, char **argv){
    
    int i = 0;
    
    //Checking if correct number of command line arguments received
    // prints usage message and exits program if it is not
    if( argc != NUM_ARGS ) {
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
*person_t readFile(char **inputFile) {
    
    /** An array of person_t structs **/
    person_t people[NUM_PEOPLE];
    
    person_t person;
    
    char buff[NUM_PEOPLE];
    
    FILE *input_p = fopen(*inputFile, "r");
    

    while( fgets(buff, 101, input_p) != NULL ) {
        //Passes the address of the beginning of array for parsing
        //parseLine(&buff);
        person.last_name = sscanf(buff, %[^,]);


    }
}

/*
 * This writes to a specified output file.
 *
 * @param *outputFile Is the address that the output is written to.
 * @return 
 */
int writeFile(char **outputFile) {

}

/*
 * This parses a specified array of characters (AKA a string)
 *
 * @param stringToParse The string to be parsed
 * @return
 */
void parseLine(char* stringToParse) {

    //TODO use sscanf() as described in Dr. Holliday's notes
    //ALERT: We may not actually need this function. Still deciding

}

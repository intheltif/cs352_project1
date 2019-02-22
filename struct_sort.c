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
    
    //Checking if correct number of command line arguments received
    // prints usage message and exits program if it is not
    if( argc != NUM_ARGS ) {
        fprint("Usage is: struct_sort <inputFile> <outputFile>");
        return 0;
    }

    int i = 0;
    int sizePeople = 0;
    char* inputFilename = argv[1];
    printf("\n\n%s\n\n", inputFilename);
    person_t* people = (person_t*)calloc(NUM_PEOPLE, (sizeof(person_t)));
    sizePeople = readFile(inputFilename, people);
    
    for(i = 0; i < sizePeople; i++) {
        
        printf("\n\nPerson Details: \n");
        printf("\t(main)Last Name: %s\n", people[i].last_name);
        printf("\t(main)Address: %s, %s, %s, %s\n", 
            people[i].address.street_add,
            people[i].address.city, 
            people[i].address.state,
            people[i].address.zip_code);
        printf("\t(main)Phone: %s\n", people[i].phone_num);

    }
    
    
    writeFile(argv[2]);

}

/*
 * This method takes the last element and makes the element the pivot 
 * and the all smaller than pivot goes to the left, all larger than pivot goes 
 * the right. 
 *
 * @param 
 * @param
 * @param 
 * @return 
 */
int sort(person_t* arr , int low, int high){
    while(arr[high] == 0){ //Finds the end of the array that is not equal to 0.
        high--;
    }
    person_t pivot = arr[high];
    int i = (low - 1); 

    if(int j = low; j <= high - 1; j++){
       if(strcmp(pivot, arr[j]) > 0){
           i++;
           swap(&arr[i], &arr[j]);
       }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    
}

/*
 *This method performs a quickSort on an array of person_t's.
 *
 *@param arr
 *@param low 
 *@param high
 */
void quickSort(person_t* arr , int low, int high){
    if (low < high){
        person_t piv = sort( , low, high);

        quickSort(arr , low, pi - 1);
        quickSort(arr , pi + 1, high); 
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
 * @param inputFile The address of the file that is being scaned in.
 * @return 
 */

int readFile(char* inputFile, person_t* people) {
    
    person_t person;
    int pos = 0;
    char* buff = (char*)calloc(NUM_PEOPLE, sizeof(char*));

    FILE* input_p = fopen(inputFile, "r");

    while( fgets(buff, NUM_PEOPLE, input_p) != NULL ) {
        
        printf("\n(%i)Adding people to array...\n", pos);
        sscanf(buff, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]", 
               person.first_name, person.last_name,
               person.address.street_add, person.address.city, 
               person.address.state, person.address.zip_code, person.phone_num);
        people[pos] = person;
        pos++;

    } // end while loop
    
    return pos;

} // end readFile

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

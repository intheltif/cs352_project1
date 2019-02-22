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
 * This method takes the last element and makes the element the pivot 
 * and the all smaller than pivot goes to the left, all larger than pivot goes 
 * the right. 
 *
 * @param arr This is the array that holds the people to be sorted.
 * @param low Low is the index of the first element in arr.
 * @param high High is the index of the last element in arr.
 * @return arr[i + 1] This is the next item to check.
 */
person_t sort(person_t arr[] , int low, int high){
    while(arr[high] == 0){ //Finds the end of the array that is not equal to 0.
        high--;
    }
    person_t pivot = arr[high];
    int i = (low - 1); 
    int j;
    if(j = low; j <= high - 1; j++){
       if(strcmp(pivot.last_name, arr[j].last_name) > 0){
           i++;
           swap(&arr[i], &arr[j]);
       }
    }
    swap(&arr[i + 1], &arr[high]);
    return arr[i + 1];
}

/*
 *This method performs a quickSort on an array of person_t's.
 *
 *@param arr Arr is the array of people to be sorted.
 *@param low Low is the index of the first element in the array.
 *@param high High is the index of the last element in the array.
 */
void quickSort(person_t arr[] , int low, int high){
    if (low < high){ //makes sure that low is not large that high.
        sort( , low, high);
        quickSort(arr , low, high - 1);
        quickSort(arr , low + 1, high); 
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
*person_t readFile(char *inputFile) {
    
    /** An array of person_t structs **/
    person_t people[NUM_PEOPLE];
    //Assures memory cleared before adding values
    bzero(people, NUM_PEOPLE);

    address_t address;
    person_t person;
    
    char buff[NUM_PEOPLE];
    
    FILE *input_p = fopen(*inputFile, "r");
    

    while( fgets(buff, NUM_PEOPLE, input_p) != NULL ) {
        //Scans each string returned from buff and
        //adds a new person and address struct
        sscanf(idk, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]", 
               person.first_name, person.last_name,
               address.street_add, address.city, address.state,
               address.zipcode, person.phone_num);
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
 * This lowers the last name of a array of person_t.
 *
 * @param arr Arr is an array of person_t's.
 */
void lower(person_t arr[]){
    int i;
    int j;
    char c;
    person_t name;
    char* cName;
    char new[NUM_PEOPLE];
    int k;
    for(i = 0; i <= NUM_PEOPLE; i++){
        for(k = 0; k <= NUM_PEOPLE; k++){
            new[k] = 0;
        }
        name = arr[i];
        cName = name.last_name;
        for(j = 0; j <= NUM_PEOPLE; j++){
            c = cName[j];
            if( c != 0){
                cName[j] = tolower(c);
                new[j] = cName[j];
            }
        }
        strcpy(arr[i].last_name, new); 
    }
}

/*
 * This makes the first letter of a name an uppercase letter with
 * an array of person_t's.
 *
 * @param arr Arr is an array of person_t's.
 */
void fixName(person_t arr[]){
    int i;
    int j;
    int k;
    person_t name;
    char* cName;
    char new[NUM_PEOPLE];
    char c;
    for(i = 0; i <= NUM_PEOPLE; i++){
        name = arr[i];
        cName = name.last_name;
        for(j = 0; j <= NUM_PEOPLE; j++){
            c = cName[j];
            if(j == 0){
                cName[j] = toupper(c);
                new[j] = cName[j];
            }else
                new[j] = cName[j];
        }
        strcpy(arr[i].last_name, new); 
        for(k = 0; k <= NUM_PEOPLE; k++){
            new[k] = 0;
        }
    }
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

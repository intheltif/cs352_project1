/*
 * Project One: Structs and File I/O
 * This program sorts a list of contacts that are read in from a given file 
 * in the command line. The sorted information will be written to another file
 * called sorted contacts.txt. 
 *
 * @author Carlee Yancey
 * @author Every Ball
 * @version 1.0 (February 25, 2019)
 */
#include "struct_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * This function runs the program.
 */
int main(int argc, char **argv){
    
    //Checking if correct number of command line arguments received
    // prints usage message and exits program if it is not
    if( argc != NUM_ARGS ) {
        printf("Usage is: struct_sort <inputFile> <outputFile>");
        return 0;
    }
    //initializing vars
    int i = 0;
    int sizePeople = 0;
    char* inputFilename = argv[INPUT_FILENAME];
    char* outputFilename = argv[OUTPUT_FILENAME];
    person_t* people = (person_t*)calloc(NUM_PEOPLE, (sizeof(person_t)));
    
    sizePeople = readFile(inputFilename, people);


    lower(people, sizePeople);
    quickSort(people, 0, sizePeople);
    fixName(people, sizePeople);
        
    for(i = 0; i < sizePeople; i++) {

        trimWhitespace(people[i]);

        printf("\n\nPerson Details: \n");
        printf("\t(main)Last Name: %s\n", people[i].last_name);
        printf("\t(main)Address: %s, %s, %s, %s\n", 
            people[i].address.street_add,
            people[i].address.city, 
            people[i].address.state,
            people[i].address.zip_code);
        printf("\t(main)Phone: %s\n", people[i].phone_num);

    }
    
    writeFile(outputFilename, people, sizePeople);

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
person_t sort(person_t* arr , int low, int high){
    person_t pivot = arr[high];
    int i = (low - 1); 
    int j;
    for(j = low; j <= high - 1; j++){//Loop as long as j is not larger that high
       if(strcmp(pivot.last_name, arr[j].last_name) > 0){
           i++;
           swap(&arr[i], &arr[j]);
       }else if(strcmp(pivot.last_name, arr[j].last_name) == 0){
            if(strcmp(pivot.first_name, arr[j].first_name) > 0){
                i++;
                swap(&arr[i], &arr[j]);
            }
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
void quickSort(person_t* arr , int low, int high){
    if (low < high){ //makes sure that low is not large that high.
        sort(arr, low, high);
        quickSort(arr , low, high - 1);
        quickSort(arr , low + 1, high);
    }
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
 * This reads in a file from a command line specified input file, reads each
 * line into a buffer, then deconstructs that line, creates a person_t struct,
 * and adds that struct to the next index of the people array.
 *
 * @param inputFile The address of the file that is being scaned in.
 * @param people The address of the array of structs to add to.
 * @return pos The number of items in the array
 */
int readFile(char* inputFile, person_t* people) {
    
    person_t person;
    int pos = 0;
    char* buff = (char*)calloc(NUM_PEOPLE, sizeof(char*));

    FILE* input_p = fopen(inputFile, "r");

    while( fgets(buff, NUM_PEOPLE, input_p) != NULL ) {
        
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
int writeFile(char *outputFile, person_t* people, int size) {
    //TODO write the array of people to the output file

    FILE* output = fopen(outputFile, "w");
    int i;

    for(i = 0; i < size; i++) {

        fputs(people[i].last_name + ", ", output);
        fputs(people[i].first_name + ", ", output);
        fputs(people[i].address.street_add + ", "), output;
        fputs(people[i].address.city + ", "), output;
        fputs(people[i].address.state + ", "), output;
        fputs(people[i].address.zip_code + ", "), output;
        fputs(people[i].phone_num + "\n"), output;
    }
        
}

/*
 * Helper function that trims whitespace from the fields of the person_t
 *
 * @param
 * @return
 */
char* trimWhitespace(person_t person) {

    char* end;
    char* stringToTrim = person.last_name;
    
    if(stringToTrim == 0)
        return stringToTrim;

    end = stringToTrim + strlen(stringToTrim) - 1;
    while(end > stringToTrim && isspace((unsigned char)*end)) end --;

    end[1] = '\0';

    return stringToTrim;
}

/*
 * This lowers the last name of a array of person_t.
 *
 * @param arr Arr is an array of person_t's.
 * @param size Size is the Size of the array.
 */
void lower(person_t arr[], int size){
    int i;
    int j;
    char c;
    person_t name;
    char* cName;
    char new[NAME_SIZE];
    int k;
    for(i = 0; i <= size; i++){//loop through array.
        for(k = 0; k <= NAME_SIZE; k++){//resets the new[] array.
            new[k] = 0;
        }
        name = arr[i];
        cName = name.last_name;
        for(j = 0; j <= NAME_SIZE; j++){//loops through each char of name.
            c = cName[j];
            if(c != 0){//makes sure that a char is present at that point.
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
 * @param size Size is the size of the array.
 */
void fixName(person_t arr[], int size){
    int i;
    int j;
    int k;
    person_t name;
    char* cName;
    char new[NAME_SIZE];
    char c;
    for(i = 0; i <= size; i++){//loops through array
        name = arr[i];
        cName = name.last_name;
        for(j = 0; j <= NAME_SIZE; j++){//loops through each char f name.
            c = cName[j];
            if(j == 0){//makes sure it is the first char of the name.
                cName[j] = toupper(c);
                new[j] = cName[j];
            } else{//keeps the rest of the chars the same.
                new[j] = cName[j];
            }
        }
        strcpy(arr[i].last_name, new); 
        for(k = 0; k <= NAME_SIZE; k++){//resets the array new[].
            new[k] = 0;
        }
    }
}

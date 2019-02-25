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
        //return 1 to show program encountered problem
        return 1;
    }
    //initializing size and for loop i value
    int i = 0;
    int sizePeople = 0;
    
    //Initializing input/output filenames
    char* inputFilename = argv[INPUT_FILENAME];
    char* outputFilename = argv[OUTPUT_FILENAME];

    //initializing people array dynamically
    person_t* people = (person_t*)calloc(NUM_PEOPLE, (sizeof(person_t)));
    
    //reads in contents from file and builds structs, then returns the size.
    sizePeople = readFile(inputFilename, people);

    //converts to lowercase, sorts, then converts to original case
    lower(people, sizePeople);
    printf("Sorting...\n"); // Let's user know that sorting has started.
    quickSort(people, 0, sizePeople);
    fixName(people, sizePeople);
    
    // Trim whitespace on all person struct attributes
    for(i = 0; i < sizePeople; i++) {
        trimWhitespace(people[i]);
    }
    
    //writes sorted structs to an output file
    writeFile(outputFilename, people, sizePeople);
    
    // Letting user know that entire process has finished
    printf("Done!\n");

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
void sort(person_t* arr , int low, int high){
    //initializing pivot and for loop counters
    person_t pivot = arr[high - 1];
    int i = low - 1; 
    int j;
    
    //Loop as long as j is not larger than high
    for(j = low; j <= high - 1; j++){
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
    swap(&arr[i + 1], &arr[high -1]);
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
    
    //Outputs to user that reading of file has started
    printf("Reading...\n");
    
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

    //close file pointer
    fclose(input_p);
    
    return pos;

} // end readFile

/*
 * This writes to a specified output file.
 *
 * @param *outputFile Is the address that the output is written to.
 * @return 
 */
void writeFile(char *outputFile, person_t* people, int size) {

    //Let's use know that writing to file has started
    printf("Writing...\n");

    //Create pointer to user specified output file, create for loop counter
    FILE* output = fopen(outputFile, "w");
    int i;

    for(i = 0; i < size; i++) {
        fprintf(output, "%s, ", people[i].last_name);
        fprintf(output, "%s, ", people[i].first_name);
        fprintf(output, "%s, ", people[i].address.street_add);
        fprintf(output, "%s, ", people[i].address.city);
        fprintf(output, "%s, ", people[i].address.state);
        fprintf(output, "%s, ", people[i].address.zip_code);
        fprintf(output, "%s,\n", people[i].phone_num);
    }

    //close file pointer
    fclose(output);    
}

/*
 * Helper function that trims whitespace from the last_name field 
 * of the person_t.
 *
 * @param person the person struct to trim whitespace on
 * @return stringToTrim the string that was trimed from the person struct
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
    
    int i, j, k, lsize, fsize, blankC;
    char c1, c2;

    person_t name;

    char* cName;
    char* fName;

    for(i = 0; i <= size; i++){//loop through array.
        blankC = 0;
        name = arr[i];
        cName = name.last_name;
        fName = name.first_name;
        lsize = strlen(cName);
        fsize = strlen(fName);
        char new[lsize];
        char fnew[fsize];
        for(k = 0; k <= lsize; k++){//resets the new[] array.
            new[k] = 0;
        }
        for(k = 0; k <= fsize; k++){//resets the new[] array.
            fnew[k] = 0;
        }
        for(j = 0; j < lsize; j++){//loops through each char of name.
            c1 = cName[j];
            if(c1 != 0){//makes sure that a char is present at that point.
                cName[j] = tolower(c1);
                new[j] = cName[j];
            }
        }   
        for(j = 0; j < fsize; j++){//loops through each char of name.
            c2 = fName[j];;
            if(c2 != 0 && c2 != BLANK_CHAR){//makes sure that a char is present at that point.
                fName[j] = tolower(c2);
                fnew[j - blankC] = fName[j];
            }else{ 
                blankC++;
            }
        }   
        strcpy(arr[i].last_name, new); 
        strcpy(arr[i].first_name, fnew); 
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
    int i, j, k, blankC, lsize, fsize;
    person_t name;
    char* cName;
    char* fName;
    char c1, c2;
    for(i = 0; i <= size; i++){//loops through array
        blankC = 0;
        name = arr[i];
        cName = name.last_name;
        fName = name.first_name;
        lsize = strlen(cName);
        fsize = strlen(fName);
        char new[lsize];
        char fnew[fsize];
        for(k = 0; k <= lsize; k++){//resets the array new[].
            new[k] = 0;
        }     
        for(k = 0; k <= fsize; k++){//resets the array new[].
            fnew[k] = 0;
        }     
        for(j = 0; j < lsize; j++){//loops through each char f name.
            c1 = cName[j];
            if(j == 0){//makes sure it is the first char of the name.    
                  cName[j] = toupper(c1);
                  new[j] = cName[j];
            }else{//keeps the rest of the chars the same.
                     new[j] = cName[j];
            }
        }
        for(j = 0; j < fsize; j++){//loops through each char f name.
            c2 = fName[j];
            if(c2 != 0 && c2 != BLANK_CHAR){
                if((j - blankC) == 0){//makes sure it is the first char of the name.
                    fName[j] = toupper(c2);
                    fnew[j- blankC] = fName[j];
                }else{//keeps the rest of the chars the same.
                    fnew[j-blankC] = fName[j];
                }
            }else
                blankC++;
        }
        strcpy(arr[i].last_name, new);
        strcpy(arr[i].first_name, fnew); 
    }
}

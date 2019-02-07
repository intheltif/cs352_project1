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

typedef struct{
    char street_add;
    char city;
    char state[STATE];
    int zip_code[ZIP];
} address_t //makes a instance of a address for a person.

typedef struct{
    char first_name[NUM_PEOPLE];
    char last_name[NUM_PEOPLE];
    addrees_t address;
    int number; 
} person_t; //makes an instance of a person.

/*
 * Description
 *
 * @param person_t 
 * @return
 */
void sort(person_t){

}

/*
 * Description
 *
 * @return
 */
int main(void){

}

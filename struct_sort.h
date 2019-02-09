/*
 * Project One: Struct and File I/O in C
 * Description`
 *
 * @author Carlee Yancey
 * @author Evert Ball
 * @version 1.0 (February 18, 2019)
 */

#define NUM_PEOPLE 100;
#define STATE 3;

typedef struct{
    char street_add;
    char city;
    char state[STATE];
    int zip_code;
}address_t //Makes instance of a persons address.

typedef struct{
    char first_name;
    char last_name;
    address_t address;
    int phone_num;
}person_t //Makes an instance of a person.

void sort(person_t person);

void swap(person_t *person1, person_t *person2);

int readFile(char *inputFile);

int writeFile(char *outputFile);

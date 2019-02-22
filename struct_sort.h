/*
 * Project One: Struct and File I/O in C
 * Description`
 *
 * @author Carlee Yancey
 * @author Evert Ball
 * @version 1.0 (February 18, 2019)
 */
#define NAME_SIZE 20;
#define NUM_PEOPLE 101;
#define STREET_ADDR_SIZE 31;
#define PHONE_NUM_SIZE 13;
#define STATE 3;
#define NUM_ARGS 3;

/*
 *Makes a instance of a persons address
 */
typedef struct{
    char street_add[STREET_ADDR_SIZE];
    char city[STREET_ADDR_SIZE];
    char state[STATE];
    int zip_code;
}address_t;

/*
 *Makes an instance of a person
 */
typedef struct{
    char first_name[NAME_SIZE];
    char last_name[NAME_SIZE];
    address_t address;
    char phone_num[PHONE_NUM_SIZE];
}person_t;

person_t sort(person_t, int, int);

void quicksort(person_t, int, int);

void swap(person_t*, person_t*);

void lower(person_t, int);

void fixName(person_t, int);

*person_t readFile(char*);

int writeFile(char*);

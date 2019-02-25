Author: Carlee Yancey 
Author: Evert Ball
Version: 1.0 (Fedruary 18, 2019)

Project 1: Structs and File I/O in C
struct_sort (executable)
struct_sort.c
struct_sort.h
text_files/
    contacts.txt - Dr. Holliday provided input file
    sorted_contacts.txt - Dr. Holliday provided output file
    unsorted_contacts.txt - A larger input file to sort
    new_sorted_contacts.txt - the larger file, sorted

#Usage
    
    Complile
        gcc -Wall struct_sort.c -o struct_sort
    To run 
        ./struct_sort <input_filename> <output_filename>

#Output
    
    Displays message to screen when reading, writing, and when file contents have
    been sorted and placed in output file.

    Thus user will see as follows:

        Reading...
        Sorting...
        Writing...

        Done!



#Known Issues
    
    -When sorting on larger files, our sorting algorithm takes longer than
     specified O(nlogn);

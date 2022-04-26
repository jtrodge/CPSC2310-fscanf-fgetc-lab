/*
  Jason Rodgers
  CPSC 2311 Sp22 Section 01
  jtrodge@g.clemson.edu
*/

#include "Lab3Fgetc.c"

int main(int argc, char* argv[]) {
    // Special case for reading in command line arguments
    assert(argc >= 2);
    FILE* in = fopen(argv[1], "r");
    assert(in != NULL);
    // Call function to delete comments from file and print to terminal
    start(in);
    // Close file once finished
    fclose(in);

    return 0;
}

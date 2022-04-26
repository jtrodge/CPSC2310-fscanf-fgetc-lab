#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char* argv[]) {

    assert(argc >= 2);
    FILE* in = fopen(argv[1], "r");
    assert(in != NULL);

    /*
    fscanf(in, "%d", num); // read in number
    studentInfo_t* stu = (studentInfo_t*)malloc(*num, sizeof(studentInfo_t));
    int i = 0;
    for(i = 0; i < *num; i++)
    {
        fscanf(in, "%s %s %d", stu[i].fName, stu[i].lName, &stu[i].age); // read in all info
    }
    return stu;
    */
    char c;
    int numline = 0;
    for(c = getc(in); c != EOF; c = getc(in)) {
      if (c == '\n') {
        numline++;
      }
    }
    fclose(in);
    FILE* input = fopen(argv[1], "r");
    char program[100];
    for (int i = 0; i < numline; i++) {
      fscanf(input, "%s", program[i]); // %[^/n]s
      fprintf(stdout, "%s", program[i]);
    }
    fclose(input);



    return 0;
}

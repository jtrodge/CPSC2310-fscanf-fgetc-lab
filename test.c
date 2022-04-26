#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct StudentInfo
{
    char fName[20];
    char lName[20];
    int age;
}studentInfo_t;

studentInfo_t* readData(FILE* in, int* num);
void printData(studentInfo_t* stu, int num);

int main(int argc, char* argv[])
{
    
    int num = 0;
    assert(argc >= 2);
    FILE* in = fopen(argv[1], "r");
    assert(in != NULL);

    /*Read the data*/
    studentInfo_t* stu = readData(in, &num);

    /*print the entries*/
    printData(stu, num);

    /*clean up*/
    free(stu);
    stu = NULL;
    fclose(in);

    /*ANOTHER TEST*/
    char name1[20];
    strcpy(name1, "Yvon Feaster");
    printf("%s\n", name1);
    
    return 0;
}

studentInfo_t* readData(FILE* in, int* num)
{
    fscanf(in, "%d", num);
    studentInfo_t* stu = (studentInfo_t*)calloc(*num, sizeof(studentInfo_t));
    int i = 0;
    for(i = 0; i < *num; i++)
    {
        fscanf(in, "%s %s %d", stu[i].fName, stu[i].lName, &stu[i].age);
    }
    return stu;
}

void printData(studentInfo_t* stu, int num)
{
    int i = 0;
    for(i = 0; i < num; i++)
    {
        printf("%s %s age: %d\n", stu[i].fName, stu[i].lName, stu[i].age);
    }
}

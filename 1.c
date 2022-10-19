/*to prevent unwanted warnings in visual studios*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*because of function isspace()*/
#include <ctype.h>


typedef struct  
{
    /*these sizes for names are **not** meaningful, just will probably work with expected data*/
    char ime[40];
    char prezime[40];
    int bodovi;
} Student;

int brojStudenta(char fileName[40]);
/*writes data from file to our array of structure*/
/*returns int to check if worked properly as file may fail to open*/
int writeToStructStudentData(char fileName[40], Student* Students, int n);
void outputStudentData(Student* Students, int n, int brojBodova);

int main()
{
    FILE* fp = NULL;
    Student* Students;
    /*size of fileName is not meaningful*/
    char fileName[40];
    int studentCount = 0;
    int maxPoints = 0;
    /*to check if correctly added data to Students array; assume it doesn't*/
    int returnValue = -1;


    printf("enter file name of student data: ");
    scanf("%s", fileName);
    printf("enter max nummber of points on kolokvij (more than 0): ");
    scanf("%d", &maxPoints);

    /*finds number of students or nonempty lines*/
    studentCount = brojStudenta(fileName);

    if (studentCount < 0) 
    {
        /*what's the best way to deal with this situation?*/
        return -1;
    } else if (studentCount == 0) 
    {
        printf("error: zero students\n");
        return -1;
    }

    /*allocate memory for the number of students in file*/
    Students = (Student*) malloc(sizeof(Student)*studentCount);

    returnValue = writeToStructStudentData(fileName, Students, studentCount);

    if (returnValue == 0)
    {
        outputStudentData(Students, studentCount, maxPoints);
    } else 
    {
        printf("error: unable to store student data as wanted\n");
    }

    return 0;
}

int brojStudenta(char fileName[40])
{
    FILE* fp = NULL;
    /*lastCh for comparison so empty lines aren't counted*/
    char ch, lastCh = '\n';
    int studentCount = 0;
    /*won't count line if is true*/
    bool isEmptyLine = true;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("error: unable to open file %s\n", fileName);
        /*is this useful*/
        fclose(fp);
        return -1;
    } 

    while ((ch = getc(fp)) != EOF)
    {
        /*checks if this line is empty (doesn't check if already know isn't)*/
        if (isEmptyLine && !isspace(lastCh))
        {
            isEmptyLine = false;
        }

        /*now at end of nonempty line*/
        if ((ch == '\n') && (!isEmptyLine))
        {
            studentCount++;
            /*next iteration of while loop leads to a new line or EOF*/
            isEmptyLine = true;
        }
        lastCh = ch;
    }

    /*adds one student if file ended with nonempty line*/
    if (!isEmptyLine) {
        studentCount++;
    }

    fclose(fp);
    return studentCount;
}

/*returns -1 if unable to open file*/
int writeToStructStudentData(char fileName[40], Student* Students, int n)
{
    FILE* fp = NULL;
    /*used to count through students and add data*/
    int i = 0;

    fp = fopen(fileName, "r");

    if (fp == NULL) 
    {
        printf("error: unable to open file\n");
        return -1;
    }

    for (i = 0; i < n; i++)
    {
        fscanf(fp, " %s %s %d", Students[i].ime, Students[i].prezime, &(Students[i].bodovi));
    }

    fclose(fp);
    return 0;
}

/*maybe should give cleaner, nicer output but hopefully it's fine*/
/*returns 0 if no problems (not including maxPoints in wrong range)*/
void outputStudentData(Student* Students, int n, int maxPoints)
{
    int i = 0; 
    float relativePoints = 0;

    printf("\n");
    if (maxPoints <= 0)
    {
        printf("sorry there was an error with the number of max points\n");
        printf("unable to print relative points\n\n");
        for (i = 0; i < n; i++)
        {
            printf("name: %s, last name: %s, absolute points: %d\n", Students[i].ime, Students[i].prezime, 
            Students[i].bodovi);
        }
    }

    for (i = 0; i < n; i++)
    {
        relativePoints = (float) Students[i].bodovi / maxPoints * 100;
        printf("name: %s, last name: %s, absolute points: %d, relative points: %.2f\n", Students[i].ime, 
        Students[i].prezime, Students[i].bodovi, relativePoints);
    }
}
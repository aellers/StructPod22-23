#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct  
{
    char ime[40];
    char prezime[40];
    int bodovi;
} Student;

int brojStudenta(char fileName[40]);
void inputStudentData(char fileName[40], Student* Students, int n);
void outputStudentData(Student* Students, int n, int brojBodova);

int main()
{
    FILE* fp = NULL;
    /*niz studenta*/
    Student* Students;
    /*this is an arbitrary size for the file name*/
    char fileName[40];
    int studentCount = 0;
    /*da se moze izracunati relativni broj bodova; not sure what's best value to set as
    * should I set it to sth like 100 or fifty or ?
    */
    int maxPoints;


    printf("enter file name of student data: ");
    scanf("%s", fileName);
    /*prints filename; could remove but idk*/
    printf("file name: %s\n", fileName);
    printf("enter max nummber of points on kolokvij (more than 0): ");
    scanf("%d", &maxPoints);

    /*finds number of students or nonempty lines*/
    studentCount = brojStudenta(fileName);

    if (studentCount < 0) 
    {
        printf("there was an error\n");
        /*what's the best way to deal with this situation?*/
        return -1;
    } else if (studentCount == 0) {
        printf("error: zero students\n");
        return -1;
    }

    printf("student count: %d\n", studentCount);

    /*allocate memory for the number of students in file*/
    Students = (Student*) malloc(sizeof(Student)*studentCount);

    inputStudentData(fileName, Students, studentCount);

    outputStudentData(Students, studentCount, maxPoints);

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
        printf("error: unable to open file %s", fileName);
        /*is this a bad idea to use?*/
        return -1;
    } 


    while ((ch = getc(fp)) != EOF)
    {
        /*checks if this line empty (doesn't check if already know isn't)*/
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

    /*adds one student if file didn't end with empty line*/
    if (!isEmptyLine) {
        studentCount++;
    }

    fclose(fp);

    return studentCount;
}

void inputStudentData(char fileName[40], Student* Students, int n)
{
    FILE* fp = NULL;
    /*used to count through students and add data*/
    int i = 0;

    fp = fopen(fileName, "r");

    if (fp == NULL) 
    {
        printf("error: unable to read file");
        return;
    }

    for (i = 0; i < n; i++)
    {
        fscanf(fp, " %s %s %d", Students[i].ime, Students[i].prezime, &(Students[i].bodovi));
    }


    fclose(fp);

}

/*maybe should give cleaner, nicer output but hopefully it's fine*/
void outputStudentData(Student* Students, int n, int maxPoints)
{
    int i = 0; 
    float relativePoints = 0;

    for (i = 0; i < n; i++)
    {
        relativePoints = (float) Students[i].bodovi / maxPoints * 100;
        printf("name: %s, last name: %s, absolute points: %d, relative points: %.2f\n", Students[i].ime, 
        Students[i].prezime, Students[i].bodovi, relativePoints);
    }


}
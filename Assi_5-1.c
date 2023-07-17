//==================================================================================================================
//
// 5-1- Program which writes structure in file. Structure should contains
//      information of student.
//
// Viraj_Shinde 
//
//==================================================================================================================

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#pragma pack(1)

struct Student
{
    int Rollno;
    int sName[20];
    float Marks;
    int Age;
};

int main(int argc,char *argv[])
{
    struct Student sObj;
    char Fname[20];
    int fd;

    sObj.Rollno = 11;
    sObj.Marks = 89.99f;
    sObj.Age = 25;

    strcpy(sObj.sName,"Viraj");

    printf("Enter File Name : \n");
    scanf("%s",Fname);

    fd = creat(Fname,0777);

    write(fd,&sObj,sizeof(sObj));

    return 0;
}

//////////////////////////////////////////////////////////////////////////
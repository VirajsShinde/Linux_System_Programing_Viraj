//===============================================================================================================
//
// 1.3- Program which accept file name and mode from user and that program check wheather our program
//      can access that file in accepted mode or not.
//
// Viraj_Shinde
//
//============================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/dir.h>
#include<dirent.h>

int main(int argc, char * argv[])
{
    char fName[20];
    char fMode[10];

    int fd = 0;
    int Mode = 0;

    printf("Enter the File Name : \n");
    scanf("%s",fName);

    printf("Enter the Mode : \n");
    scanf("%s",fMode);

    if(strcmp(fMode,"Read") ==  0)
    {
        Mode = R_OK;
    }
    else if(strcmp(fMode,"Write") == 0)
    {
        Mode = W_OK;
    }
    else
    {
        Mode = X_OK;
    }

    if(access(argv[1], Mode) < 0)
    {
        printf("Unable to acess %s file in %s mode \n",fName,fMode);
    }
    else
    {
        printf("you can access %s file in %s mode \n",fName, fMode);
    }

    return 0;
}

//==========================================================================================================

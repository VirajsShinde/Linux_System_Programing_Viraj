//===============================================================================================================
//
// 1.2- Program which accept file name and mode from user and then open that file in specific mode.
//
// Viraj_Shinde
//
//============================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

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
        Mode = O_RDONLY;
    }
    else if(strcmp(fMode,"Write") == 0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }

    fd = open(fName,Mode);

    if(fd == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }
    else
    {
        printf("File sucessfully opened with fd : %d\n",fd);
    }

    return 0;
}

//==========================================================================================================

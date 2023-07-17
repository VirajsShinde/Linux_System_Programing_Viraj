//============================================================================================================
//
// 1.4- Program which accept file name from user and print all the information about that file.
//
// Viraj_Shinde
//
//============================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    char fName[20];
    struct stat sobj;

    printf("Enter the File Name : \n");
    scanf("%s",fName);

    stat(fName,&sobj);

    printf("File name : %s\n",fName);
    printf("File size : %d\n",sobj.st_size);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Inode Number : %d\n",sobj.st_ino);
    printf("File System number : %d\n",sobj.st_dev);
    printf("Number of Blocks : %d\n",sobj.st_blocks);

    return 0;
}

//==========================================================================================================

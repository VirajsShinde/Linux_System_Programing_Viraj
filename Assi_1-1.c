//============================================================================================================
//
// 1.1- Program which accept file name from user and open that file.
//
// Viraj_Shinde
//
//============================================================================================================

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
    char fName[20];
    int fd = 0;

    printf("Enter the File Name : \n");
    scanf("%s",fName);

    fd = open(fName,O_RDONLY);

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

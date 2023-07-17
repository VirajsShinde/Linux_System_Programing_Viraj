//===============================================================================================================
//
// 1.5- Program which accept file name and number of bytes from user and read that number of bytes from file. 
//
// Viraj_Shinde
//
//============================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    char fName[20];
    char Buffer[20] = {'\0'};
    int iNo = 0;
    int Ret = 0;

    int fd = 0;
    
    printf("Enter the File Name : \n");
    scanf("%s",fName);

    printf("Enter Number of bytes that you want to read : \n");
    scanf("%d",&iNo);

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

    Ret = read(fd,Buffer,iNo);

    if(Ret == 0)
    {
        printf("Unable to read data from file \n");
        return -1;
    }
    
    printf("Data from file is : %s\n",Buffer);

    return 0;
}

//==========================================================================================================
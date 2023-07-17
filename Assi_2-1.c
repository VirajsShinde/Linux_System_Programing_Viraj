//==============================================================================================================
//
// 2-1- Program which accept file name and Read Whole data from file.
//
// Viraj_Shinde 
//
//============================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
    int fd =  0;
    char Buffer[BLOCKSIZE];

    int Ret = 0;

    if(argc != 2)
    {
        printf("Insuficient Argument\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open \n");
        return-1;
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,Ret);
    }
    
    close(fd);

    return 0;
}
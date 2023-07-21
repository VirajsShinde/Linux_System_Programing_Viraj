//============================================================================================================
//
// 2-2- Program which accept file name and Write String in that file.
//
// Viraj_Shinde
//
//============================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
    int fd =  0;

    char Buffer[BLOCKSIZE];

    int Ret = 0;
    int byteSize = 0;

    if(argc != 3)
    {
        printf("Insuficient Argument\n");
        return -1;
    }

    fd = open(argv[1], O_RDWR);

    if(fd == -1)
    {
        printf("unable to open \n");
        return-1;
    }
    
    byteSize = strlen(argv[2]);

    write(fd,argv[2],byteSize);
   
    close(fd);

    return 0;
}

//=============================================================================

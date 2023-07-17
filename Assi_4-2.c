//==================================================================================================================
//
// 4-2- Program which accept directory name from user and create new directory of that name 
//
// Viraj_Shinde 
//
//==================================================================================================================

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int Ret = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    Ret = mkdir(argv[1], 0777);
    
    if(Ret == -1)
    {
        printf("Unable to create directory \n");
        return -1;
    }
    else
    {
        printf("Directory with name %s created succesfully \n",argv[1]);
    }
    return 0;
}

//============================================================================================================
//
// 2-3- Program which accept directory name from user and print all file name from that directory.
//
// Viraj_Shinde 
//
//============================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{   
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("Insuficient Argument\n");
        return -1;
    }    

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open Directory\n");
        return -1;
    }

    printf("===========================================\n");
    printf("Entaries from directory file\n");
    printf("===========================================\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%20s : %ld\n",entry->d_name,entry->d_ino);
    }

    printf("===========================================\n");

    closedir(dp);

    return 0;
}

//=============================================================================

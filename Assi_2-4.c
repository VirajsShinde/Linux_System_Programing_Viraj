//============================================================================================================
//
// 2-4- Program which accept directory name from user and print all file name and its types from that directory.
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
    struct stat sobj;
    char name[30];

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
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            printf("%20s is Regular File\n",entry->d_name);
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("%20s is a directory File\n",entry->d_name);
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("%20s is a symbolic link File\n",entry->d_name);
        }

    }

    printf("===========================================\n");

    closedir(dp);

    return 0;
}

//=============================================================================

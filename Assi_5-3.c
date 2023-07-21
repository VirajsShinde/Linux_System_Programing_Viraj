//==================================================================================================================
//
// 5-3- Program which accept directory name from user and write information 
//      of all regular file in and then read the contents from that file.
//
// Viraj_Shinde 
//
//==================================================================================================================

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    char *buffer = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
    int fd = 0;
    char entryName[30];
    int ret = 0;

    struct FileInfo fobj;

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);

            printf("File %s with Size %d\n",entry->d_name,sobj.st_size);
        }
    }

    closedir(dp);
    
    return 0;
}
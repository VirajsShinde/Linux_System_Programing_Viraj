//=================================================
// Linux System Programing | Viraj_Shinde         
//=================================================

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char * argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    
    struct stat sobj;

    char DirName[20];
    char name[30];
    char namecopy[30] = {"\0"};
    int Size = 0;
    
    printf("Please Enter Directory Name : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == -1)
    {
        printf("Unable to open Directory..\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if((sobj.st_size) == 0)
            {
                Size = sobj.st_size;
                strcpy(namecopy,name);
            }
        }
    }
    
    printf("Name of Empty file is : %s with size %d \n",namecopy,Size);

    close(dp);
    
    return 0;
}
























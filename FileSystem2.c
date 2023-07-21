//=================================================
// Linux System Programing | Viraj_Shinde         
//=================================================

#include<stdio.h>

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("Please enter your first name as command line argument");
        return -1;
    }
    else
    {
        printf("Welcome to Application : %s\n",argv[1]);
        return 0;
    }
}
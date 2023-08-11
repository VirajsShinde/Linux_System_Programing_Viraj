//==================================================================================================================
//
// 9-3- Program which print priority of process.
//
// Viraj_Shinde 
//
//==================================================================================================================
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/resource.h>

int main()
{
    int ret = 0;

    ret = getpriority(PRIO_PROCESS,0);

    printf("Priority of process is %d\n",ret);

    return 0;
}

//output = 0
//==================================================================================================================
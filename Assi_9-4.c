//==================================================================================================================
//
// 9-4- Program which increase priority of process by 5.
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

    printf("Current Priority of process is %d\n",ret);

    ret = nice(5);

    printf("Increased Priority of process is %d\n",ret);

    return 0;
}
//==================================================================================================================
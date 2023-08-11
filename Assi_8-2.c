//==================================================================================================================
//
// 8-2- Program which create 3 level process hieararchy where process
//      1 creates process 2 and it internally creates process 3. .
//
// Viraj_Shinde 
//
//==================================================================================================================

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int Ret = 0;
    int RetX = 0;
    int cpid = 0;
    int Exit_status = 0;

    Ret = fork();

    if(Ret == 0)  // Process2  
    {
        printf("Child Process2 is running with PTD : %d\n",getpid());
        execl("./Process2","NULL",NULL);
        RetX = fork();

        if(RetX == 0)   //Process3
        {
            printf("Child Process3 is running with PTD : %d\n",getpid());
            execl("./Process3","NULL",NULL);
        }
        else        // Process2
        {
            printf("Parent Process2 is running with PID : %d\n",getpid());
            cpid = wait(&Exit_status);
            printf("Child Process3 terminated having PID %d with exit status %d\n",cpid,Exit_status);
        }


    }
    else        // Process1
    {
        printf("Parent Process1 is running with PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Child Process2 terminated having PID %d with exit status %d\n",cpid,Exit_status);
    }

    return 0;
}


//==================================================================================================================
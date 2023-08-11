//==================================================================================================================
//
// 10-5- Program which get thread id inside its thread function.
//
// Viraj_Shinde 
//
//==================================================================================================================
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
  printf("Thread id from thread function is: %d\n", pthread_self());
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID,            // Address of pthread_attr_t structure object
                          NULL,           // Thread attributes
                          ThreadProc,     // Address of callback function
                          NULL);     // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread ID from main function is : %d\n",TID);
    pthread_join(TID,NULL);

    printf("End of main thread\n");
    return 0;
}
//==================================================================================================================

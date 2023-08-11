//==================================================================================================================
//
// 10-4- Program which creates single thread and it accept one value
//       from user and it return some value to the caller thread.
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
  int i = (int)ptr;
  printf("Value received from user is : %d\n",(int)ptr);
  pthread_exit(++i);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int no = 0;
    int value = 0;

    printf("Enter the value that you want to provide to the thread :\n");
    scanf("%d",&no);

    ret = pthread_create(&TID,            // Address of pthread_attr_t structure object
                          NULL,           // Thread attributes
                          ThreadProc,     // Address of callback function
                          (int *)no);     // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n",TID);
    pthread_join(TID,&value);
    printf("Return value from thread is : %d\n",value);

    printf("End of main thread\n");
    return 0;
}
//==================================================================================================================

//==============================================================================================================
//
// 4-1- Program which is used to Demonstrate the Concept of I/0 Redirection.
//
// Viraj_Shinde
//============================================================================================================

#include<stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iAns = 0;

    scanf("%d",&iNo1);

    scanf("%d",&iNo2);

    iAns = iNo1 + iNo2;

    printf("Ans is : %d\n",iAns);

    return 0;
}

//./myexe > Output.txt < Input.txt
//=============================================================================
/*Program to print pascals triangle using recursion*/

#include<stdio.h>

int pascal(int n, int i)
{
  int m;
    if (i<n)
    {
        for (m=0;m<n-i;m++)
        {
            printf("%c", ' ');
        }
        int k=1;
        for(int t=0;t<=i;t++)            
        {
          printf("%d",k);
          printf("%c",' ');
          k=k*(i-t)/(t+1);
        }
        printf("\n");
        i++;
        return pascal(n, i);
    }  
}


int main()
{
    int n, i=0;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    pascal(n, i);
}
#include<stdio.h>

int main()
{
  int a[17] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9}, i, j,b[10]={0},c[17];
  for(i=0;i<17;i++)
  {
    b[a[i]]++;
  }
  for(j=1;j<10;j++)
  {
    b[j]=b[j]+b[j-1];
  }
  for(i=16;i>=0;i--)
  {
    b[a[i]]--;
    c[b[a[i]]]=a[i];
  }
  for (i = 0; i < 17; i++)
    printf("%d\n", c[i]);
}
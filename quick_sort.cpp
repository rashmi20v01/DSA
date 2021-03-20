#include <stdio.h>

int quick(int a[], int l, int h)
{
  int pivot = a[l], start = l, end = h, temp;
  while(start<end)
  {
  while (a[start] <= pivot)
    start++;
  while (a[end] > pivot && end>=0)
    end--;
  if (start < end)
  {
    temp = a[start];
    a[start] = a[end];
    a[end] = temp;
  }
  }
  temp = a[end];
  a[end] = a[l];
  a[l] = temp;
  printf("end=%d\n",a[end]);
  return end;
}
void sort(int a[], int l, int h)
{
  if (l < h)
  {
    int loc=quick(a, l,  h);
    sort(a, l, loc-1);
    sort(a, loc+ 1, h);
  }
}
int main()
{
  int a[8] = {170,45,75,90,2,802,2,66},l=0,h=7;
  sort(a,l,h);
  for(int i=0;i<8;i++)
  printf("%d\n",a[i]);
}
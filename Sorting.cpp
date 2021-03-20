/*Program to sort 15 randomly ordered elements in an array using quick sort*/

#include <stdio.h>

int n = 0;

int quick(int a[], int l, int h)
{
  int pivot = a[l], start = l, end = h, temp;
  n++;
  while (start < end)
  {
    while (a[start] <= pivot)               //finding position of element which is greater than pivot element              
      start++;
    while (a[end] > pivot)                 //finding position of element which is lesser than pivot element
      end--;
    if (start < end)
    {
      temp = a[start];                       //swapping a[start] with a[end]
      a[start] = a[end];
      a[end] = temp;
    }
  }
  temp = a[end];                            //swapping a[end] with a[l];
  a[end] = a[l];
  a[l] = temp;
  return end;
}
void sort(int a[], int l, int h)
{
  if (l < h)
  {
    int loc = quick(a, l, h);
    sort(a, l, loc - 1);        //dividing array into subarrays
    sort(a, loc + 1, h);
  }
}
int main()
{
  int a[15], l = 0, h = 14;
  printf("Enter the elements of array:");
  for (int i = 0; i < 15; i++)
    scanf("%d", &a[i]);
  sort(a, l, h);
  printf("Array after sorting:\n");
  for (int i = 0; i < 15; i++)
    printf("%d ", a[i]);
  printf("\nNumber of iterations=%d\n", n);
}
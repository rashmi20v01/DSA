#include <stdio.h>

int linear(int A[], int key)
{
  int i;
  for (i = 0; i < 10; i++)
  {
    printf("The compared element in %d iteration=%d \n", i+1,A[i]);
    if (A[i] == key)
    {
      printf("The element is in %d index \n", i);
      break;
    }
  }
  if(i==10)
    printf("The element is not present in the array! \n");
  return 0;
}

int binary(int A[], int key)
{
  int low = 0, high = 9, mid,k=0;
  while (low <= high)
  {
    k++;
    mid = (low + high) / 2;
    printf("Middle element in %d iteration=%d \n",k,A[mid]);
    if (A[mid] == key)
    {
      printf("The element is in %d index \n", mid);
      break;
    }
    else if (key > A[mid])
      low = mid + 1;
    else if (key < A[mid])
      high = mid - 1;
  }
  if(low>high)
  {
    printf("The element is not present in the array! \n");
  }
  return 0;
}

int main()
{
  int A[10], key;
  printf("Enter the elements of array in sorted order: ");
  for (int i = 0; i < 10; i++)
    scanf("%d", &A[i]);
  printf("Enter the element you want to search: ");
  scanf("%d", &key);
  printf("For linear search: \n");
  linear(A, key);
  printf("FOR binary search: \n");
  binary(A, key);
  
}
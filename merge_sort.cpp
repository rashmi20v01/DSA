#include <stdio.h>

void join(int a[], int l, int mid, int h)
{
  int b[7], i = l, j = mid + 1, k = l;
  while (i <= mid && j <= h)
  {
    if (a[i] > a[j])
    {
      b[k] = a[j];
      j++;
    }
    else
    {
      b[k] = a[i];
      i++;
    }
    k++;
  }
  if (i <= mid)
  {
    while (i <= mid)
    {
      b[k] = a[i];
      k++;
      i++;
    }
  }
  else
  {
    while (j <= h)
    {
      b[k] = a[j];
      j++;
      k++;
    }
  }
  for (k = l; k <= h; k++)
    a[k] = b[k];
}

void merge(int a[], int l, int h)
{
  if (l < h)
  {
    int mid = (l + h) / 2;
    merge(a, l, mid);
    merge(a, mid + 1, h);
    join(a, l, mid, h);
  }
}

int main()
{
  int a[7] = {34, 21, 7, 10, 2, 26, 4};
  int l = 0, h = 6;
  merge(a, l, h);
  for (int i = l; i <= h; i++)
    printf("%d\n", a[i]);
}
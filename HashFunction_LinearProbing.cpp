/*Program to implement hash function by linear probing*/

#include <stdio.h>
#include<stdlib.h>

void insert();
void search();
void display();
int table[20]={NULL};

int main()
{
  int ch,j=0;
  while(j!=-1)
  {
  printf("Enter your choice!\n1.Insert\n2.Display\n3.Quit\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
    insert();
    break;
    case 2:
    display();
    break;
    case 3:
    j=-2;
  }
  j++;
  }
}

int hash(char s[])      //hash function
{
  int n=0;
  for(int i=0;s[i]!='\0';i++)
  n=n+s[i];
  return n;
}
void insert()
{
  int m = 20,probe,c=0;
  char s[10];
  printf("Enter the roll numbers!");
  for (int i = 0; i < m; i++)
  {
    scanf("%s", &s);
    probe = hash(s) % m;
    while (table[probe] != NULL)
    {
      c++;
      probe = (probe + 1) % m;
    }
    table[probe] = hash(s);
  }
  printf("The number of collisions=%d\n",c);
}
void display()
{
  printf("Elements in hash table are:");
   for(int i=0;i<20;i++)
  {
    printf("%d\n",table[i]);
  }
}

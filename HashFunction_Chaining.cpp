/*Program to implement hash function by chaining*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10

struct node
{
  char s[10];
  struct node *next;
};
struct node *p;
int c=0;
node *head[TABLE_SIZE] = {NULL};
int hash(char s[])                    //hash function
{
  int n = 0;
  for (int i = 0; s[i] != '\0'; i++)
    n = n + s[i];
  return n;
}
void insert()
{
  int i, t;
  char rollNo[9];
  printf("Enter RollNumber to be inserted in the hash table ");
  scanf("%s", &rollNo);
  t = hash(rollNo);
  int key = t % TABLE_SIZE;
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->next = NULL;
  strcpy(temp->s, rollNo);
  if (head[key] == NULL)
  {
    head[key] = temp;
  }
  else
  {
    c++;
    p = head[key];
    while (p->next != NULL)
    {
      p = p->next;
    }
    p->next = temp;
  }
}
void display()
{
  int i;
  for (i = 0; i < TABLE_SIZE; i++)
  {
    printf("The roll numbers at index=%d:", i);
    if (head[i] == NULL)
    {
      printf("No Hash Entry\n");
    }
    else
    {
      for (p = head[i]; p != NULL; p = p->next)
        printf("%s\n", p->s);
    }
  }
}

void search()
{
  int i, t;
  char rollNo[9];
  printf("Enter the Roll Number to be searched : ");
  scanf("%s",rollNo);
  t = hash(rollNo);
  int index = t % TABLE_SIZE;
  if (head[index] == NULL)
    printf("\n Roll number not found\n");
  else
  {
    for (p = head[index]; p != NULL; p = p->next)
    {
      if (strcmp(rollNo, p->s))
      {
        printf("Roll number found\n");
        break;
      }
    }
    if (p == NULL)
      printf("\n Roll number not found\n");
  }
}
int main()
{
  int i = 0;
  while (i < 20)
  {
    insert();
    i++;
  }
  printf("Number of collisions=%d\n",c);
  display();
  search();
}
/*Operations on single linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  char s;
  struct node *next;
};
struct node *head = NULL;
void insert();
void del();
void display();
int returnIndex();
void add();

int main()
{
  int ch, i = 0, j = 0;
  while (j < 10)
  {
    add();
    j++;
  }

  while (i != -1)
  {
    printf("Enter your choice:\n 1.insert node\n 2.delete node\n 3.display data\n 4.return index of node\n 5.Quit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      insert();
      break;
    case 2:
      del();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("The index is: %d\n", returnIndex());
      break;
    case 5:
      i = -2;
    }
    i++;
  }
}

void add()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->next = NULL;
  printf("Enter integer and character value of node: ");
  scanf("%d %c", &temp->data, &temp->s);
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    struct node *p;
    p = head;
    while (p->next != NULL)
      p = p->next;
    p->next = temp;
  }
}

void insert()
{
  int loc, n;
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->next = NULL;
  printf("Enter integer and character value of node: ");
  scanf("%d %c", &temp->data, &temp->s);
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    printf("Add node in?\n 1.Beginning\n 2.Middle\n 3.End \n");
    scanf("%d", &n);
    if (n == 1)
    {
      temp->next = head;
      head = temp;
    }
    else if (n == 2)
    {
      printf("Enter the location: ");
      scanf("%d", &loc);
      int j = 1;
      struct node *p;
      p = head;
      while (j < loc - 1)
      {
        p = p->next;
        j++;
      }
      temp->next = p->next;
      p->next = temp;
    }
    else if (n == 3)
    {
      struct node *p;
      p = head;
      while (p->next != NULL)
        p = p->next;
      p->next = temp;
    }
  }
}

int returnIndex()
{
  int d, c = 0;
  printf("Enter the integer value of who's index u want to find: ");
  scanf("%d", &d);
  struct node *p;
  p = head;
  while (p->data != d && p->next!=NULL)
  {
    p = p->next;
    c++;
  }
  if(p->data != d && p->next==NULL)
  return -1;
  else
    return c;
}
void display()
{
  if (head == NULL)
    printf("No node element to display! \n");
  else
  {
    struct node *p;
    p = head;
    printf("linked list data:\n%d %c \n", p->data, p->s);
    while (p->next != NULL)
    {
      p = p->next;
      printf("%d %c \n", p->data, p->s);
    }
  }
}

void del()
{
  int pos;
  int k;
  if (head == NULL)
    printf("No node to delete! \n");
  else
  {
  printf("Enter where u want to delete the node from?\n1.Beginning\n2.Middle or End\n");
  scanf("%d", &k);
  struct node *p;
  p = head;
  if (k == 1)
  {
    head = p->next;
    free(p);
  }
  else if (k == 2)
  {
    int m = 1;
    struct node *q;
    printf("Enter location from which u want to delete:");
    scanf("%d", &pos);
    while (m < pos - 1)
    {
      p = p->next;
      q = p;
      m++;
    }
    q = p->next;
    p->next = q->next;
    q->next = NULL;
    free(q);
  }
  }
}
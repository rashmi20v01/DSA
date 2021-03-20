//Queue implementation using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
int c=0;

void enqueue();
void dequeue();
void display();
void isEmpty();
void size();

int main()
{
  int ch, j;
  for (int i = 0; i < 10; i++)
  {
    enqueue();
  }
  while (j != -1)
  {
    printf("Enter your choice:\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.display\n5.size\n6.Quit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
       break;
    case 3:
      isEmpty();
      break;
    case 4:
      display();
      break;
    case 5:
     size();
     break;
    case 6:
      j = -2;
    }
    j++;
  }
}

void enqueue()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  printf("Enter the node elements: ");
  scanf("%d", &temp->data);
  if (front == NULL)
  {
    front = temp;
    rear = temp;
  }
  else
  {
    rear->next = temp;
    rear = rear->next;
  }
  c++;
}
void isEmpty()
{
  if (front == NULL)
    printf("Queue is empty!\n");
  else
  {
    printf("Queue is not empty!\n");
  }
  
}

void dequeue()
{
  struct node *p;
  if (front == NULL)
    printf("No node element to remove!\n");
  else
  {
    p = front;
    front = p->next;
    free(p);
    c--;
  }
}

void display()
{
  struct node *p;
  if (front == NULL)
    printf("No node element to display!\n");
  else
  {
    p = front;
    printf("Queue elements are: \n");
    while (p != rear)
    {
      printf("%d \n", p->data);
      p = p->next;
    }
    printf("%d \n", p->data);
  }
}

void size()
{
  if(front!=NULL)
  printf("The size of queue:%d \n",c);
  else
  printf("The queue doesnt have any node!");
}
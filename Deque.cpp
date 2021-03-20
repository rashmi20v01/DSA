//Deque implementation using doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *right;
  struct node *left;
};

struct node *front = NULL;
struct node *rear = NULL;
int c=0;

void enQueueFront();
void enQueueRear();
void deQueueFront();
void deQueueRear();
void isEmpty();
void size();
void display();

int main()
{
  int ch, j;
  for (int i = 0; i < 10; i++)
  {
    enQueueRear();
  }
  while (j != -1)
  {
    printf("Enter your choice:\n1.Enqueue in front\n2.Enqueue in rear\n3.Dequeue in front\n4.Dequeue in rear\n5.isEmpty\n6.display\n7.size\n8.Quit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      enQueueFront();
      break;
    case 2:
      enQueueRear();
      break;
    case 3:
      deQueueFront();
      break;
    case 4:
      deQueueRear();
      break;
    case 5:
      isEmpty();
      break;
    case 6:
      display();
      break;
    case 7:
      size();
      break;
    case 8:
      j = -2;
    }
    j++;
  }
}

void enQueueFront()
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
    temp->right = front;
    front->left = temp;
    front = temp;
  }
  c++;
}
void enQueueRear()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  printf("Enter the node elements:");
  scanf("%d", &temp->data);
  if (front == NULL)
  {
    front = temp;
    rear = temp;
  }
  else
  {
    rear->right = temp;
    temp->left = rear;
    rear=temp;
  }
  c++;
}
void deQueueFront()
{
  struct node *p;
  if (front == NULL)
    printf("No node element to remove!\n");
  else
  {
    p = front;
    front = p->right;
    free(p);
    c--;
  }
}
void deQueueRear()
{
  struct node *p;
  if (rear == NULL)
    printf("No node element to remove!\n");
  else
  {
    p = rear;
    rear = p->left;
    p->left->right = NULL;
    c--;
  }
}

void isEmpty()
{
  if (front == NULL)
    printf("Deque is empty!\n");
  else
  {
    printf("Deque is not empty!\n");
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
      p = p->right;
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
/*Program to implement binary search tree*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int num;
  struct node *left, *right;
};
struct node *root = NULL;
void insert();
void del();
void mirror();

void display_inorder(struct node *t) //Display inorder traversal of BST
{
  if (t->left)
    display_inorder(t->left);
  printf("%d\n", t->num);
  if (t->right)
    display_inorder(t->right);
}

void display_preorder(struct node *t) //Display preorder traversal of BST
{
  printf("%d\n", t->num);
  if (t->left)
    display_preorder(t->left);
  if (t->right)
    display_preorder(t->right);
}

void mirror(struct node *t) //Convert tree to its mirror tree
{
  struct node *temp;
  if (t)
  {
    mirror(t->left);
    mirror(t->right);
    temp = t->left;
    t->left = t->right;
    t->right = temp;
  }
  else
    return;
}

int main()
{
  int ch, i = 0;
  while (i != -1)
  {
    printf("Enter your choice:\n1.Insert\n2.Delete\n3.Display inorder\n4.Display preorder\n5.Mirror\n6.Quit ");
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
      struct node *t;
      t = root;
      display_inorder(t);
      break;

    case 4:
      display_preorder(root);
      break;

    case 5:
      mirror(root);
      break;

    case 6:
      i = -2;
    }
    i++;
  }
}

void insert() //Insert elements in a BST
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  printf("Enter value to be inserted:");
  scanf("%d", &temp->num);
  temp->left = NULL;
  temp->right = NULL;
  if (root == NULL)
    root = temp;
  else
  {
    struct node *parent, *current;
    parent = root;
    current = root;
    while (current)
    {
      parent = current;
      if (temp->num < current->num)
        current = current->left;
      else
      {
        current = current->right;
      }
    }
    if (temp->num < parent->num)
      parent->left = temp;
    else
      parent->right = temp;
  }
}

void del() //Delete elements from BST
{
  int ele;
  printf("Enter the element you want to delete:");
  scanf("%d", &ele);
  struct node *parent, *current;
  parent = root;
  current = root;
  while (current->num != ele)
  {
    parent = current;
    if (ele < current->num)
      current = current->left;
    else
      current = current->right;
    if(current==NULL)
    {
      break;
    }
  }
    if(current==NULL)
    {
    printf("Element not present in tree!\n");
    return;
    }
  if (current->left == NULL && current->right == NULL)
  {
    if (current == parent->left)
    {
      parent->left = NULL;
      free(current);
    }
    else
    {
      parent->right = NULL;
      free(current);
    }
  }
  else if (current->left != NULL && current->right == NULL)
  {
    if (current == parent->right)
    {
      parent->right = current->left;
      current->left = NULL;
      free(current);
    }
    else if (current == parent->left)
    {
      parent->left = current->left;
      current->left = NULL;
      free(current);
    }
  }
  else if (current->right != NULL and current->left == NULL)
  {
    if (current == parent->left)
    {
      parent->left = current->right;
      current->right = NULL;
      free(current);
    }
    else if (current == parent->right)
    {
      parent->right = current->right;
      current->right = NULL;
      free(current);
    }
  }
  else if (current->left != NULL and current->right != NULL)
  {
    struct node *p, *t;
    p = current->left;
    if (p->right != NULL)
    {
      while (p->right != NULL)
      {
        t = p;
        p = p->right;
      }
      current->num = p->num;
      t->right = NULL;
      free(p);
    }
    else
    {
      current->num = p->num;
      current->left = p->left;
      p->left = NULL;
      free(p);
    }
  }
}
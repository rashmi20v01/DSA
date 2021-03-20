/*Program to implement Breadth first search and depth first search*/
#include<stdio.h>
#include<stdlib.h>

int adj[9][9]={{0,0,0,0,0,0,0,0,0},
               {0,0,1,0,0,1,0,0,0},
               {0,1,0,0,0,0,1,0,0},
               {0,0,0,0,1,0,1,1,0},
               {0,0,0,1,0,0,0,0,1},
               {0,1,0,0,0,0,0,0,0},
               {0,0,1,1,0,0,0,1,0},
               {0,0,0,1,0,0,1,0,1},
               {0,0,0,0,1,0,0,1,0}};
int visited[10]={0},q[100],f=-1,r=-1;

void bfs();
void enqueue(int);
void dequeue(); 
void dfs(int);

int main()
{
  printf("Elements in graph according to BFS are:\n");
  bfs();
  printf("Elements in graph according to DFS are:\n");
  dfs(1);  //starting vertex for dfs is 1.
}

void bfs()
{
  int v=1;                     //starting vertex=1
  enqueue(v);                  //In this method the vertices are selected based on the order in which they r in the matrix.So the adjacent elements are enqueued in 
  printf("%d\n",v);            //ascending order.
  visited[1]=1;
  while(f!=-1 && r!=-1)
  {
  dequeue();
  for(int i=0;i<9;i++)
  {
    if(adj[v][i]==1 && visited[i]==0)
    {
    enqueue(i);              
    printf("%d\n",i);              //print vertice
    visited[i]=1;
    }
  }
  v=q[f];
  }
}
void enqueue(int v)
{
  if(f==-1)
  f=0;
  r++;
  q[r]=v;
}
void dequeue()
{
  f++;
  if(f>r)
  {
    f=-1;
    r=-1;
  }
}

void dfs(int v)                   //In this method the adjacent vertice to be added is based on the order in which they r in the matrix.So the lowest adjacent vertice is 
{                                 //selected and pushed into the stack.
  static int vis[9]={0};
  int i;
  if(vis[v]==0)
  {
    printf("%d\n",v);           //print vertice
    vis[v]=1;
  for(i=1;i<9;i++)
  {
    if(adj[v][i]==1 && vis[i]==0)
      dfs(i);                  //recursive call
  }
  }
}
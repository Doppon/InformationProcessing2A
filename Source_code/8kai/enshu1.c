#include<stdio.h>
#include<malloc/malloc.h>
#include "PLIB2.h"
#define N 5
static int start=0;
static int end=4;
static int adj[N][N]={
  {0,16,0,10,0},
  {0,0,12,8,0},
  {0,0,0,7,11},
  {0,5,0,0,13},
  {0,0,0,0,0}};
static char V[N+1]="sabct";//V[5]は辿り着けなかった場合に使用(？)
int flow[N][N];
int BFS();
void rest();
void printflow();
int path[N+1];
int parent[N];

int main(void){
  int visit[N];
  int i,j,counter=0;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++)
      flow[i][j]=0;
      
  printf("ノード記号とノード番号の対応:");
  for(i=0;i<N;i++)
    printf("%c=%d ",V[i],i);
  printf("\nstart=%c(%d) end=%c(%d)",V[start],start,V[end],end);
  printf("\n開始前");
  printflow();
  
  while(BFS()==1){
    printf("\n 第%d回目",++counter);
    rest(); 
    printflow();
  }
  
  printf("\n残余グラフに、拡張可能経路がない(終了)");
  printf("\n*/\n");
  
  return 0;}
void rest(){

  int i,j,k,Num,temp,min=99999;     
  k=end;
  j=N;
  Num=0;
  
  while(1){
    path[j--]=k; 
    Num++;
    k=parent[k];
    if(k==-1)
      break; //-1→始点
  }
 
   j=1;
   path[0]=Num; //path←数
   for(i=N-Num+1;i<=N;i++)
     path[j++]=path[i];
  printf("\npath;");
  for(k=1;k<path[0];k++){
    temp=adj[path[k]][path[k+1]]; 
    if(temp<min)
      min=temp;
  }
  for(i=1;i<=path[0];i++)
    printf("-%d-",path[i]);
  printf("\nflow=%d",min);
  
  for(k=1;k<path[0];k++){
    adj[path[k]][path[k+1]]=adj[path[k]][path[k+1]]-min;
    flow[path[k]][path[k+1]]=flow[path[k]][path[k+1]]+min;
    adj[path[k+1]][path[k]]=adj[path[k+1]][path[k]]+min;
  }
}

void printflow(){

  int i,j;
  
  printf("\n残余グラフのフロー\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf(" %2d ",adj[i][j]);
    printf("\n");
  }
  
  printf("\n最大流れのフロー\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf(" %2d ",flow[i][j]);
    printf("\n");
  }
  
}


int BFS()//Breadth First Search
{
  int visit[N];
  int i,n;
  for(i=0;i<N;i++){
    visit[i]=0;
    parent[i]=-2;
  }
  visit[start]=1,Enqueue(start);
  parent[start]=-1;
  while(queuehead!=queuetail){
    n=Dequeue();
    if(n==end){
      return 1;
    }else{
      for(i=0;i<N;i++){
        if((adj[n][i]!=0)&&(visit[i]==0)){
          visit[i]=1;
          parent[i]=n;
          Enqueue(i);
          printf("   ---Visiting node [%c] <-- Parent node = [%c]\n",V[i],V[n]);
        }
      }
    }
  }
  return 0;
}

#include<stdio.h>
#include<malloc.h>
#include "PLIB2.h"
#define N 5
static int adj[N][N]={

  {0,1,0,1,0},
  {0,0,1,1,0},
  {0,0,0,1,1},
  {0,1,0,0,1},
  {0,0,0,0,0},

};

static char V[N+1]="sabct";
static int start=0;
static int end=4;
int parent[N];
int visit[N];
int BFS();

int main(void){
  int i,n;
  printf("ノードの記号と番号の対応");
  for(i=0;i<N;i++){
    printf("%c=%d ",V[i],i);
    printf("\nstart=%c(%d) end=%c=(%d)\n",V[start],start,V[end],end);

  }
    BFS();
  return 0;
}

int BFS(){//Breadth First Search
    int i,n;
queuehead=queuetail=0;
  for(i=0;i<N;i++){
    visit[i]=0;//譛ｪ險ｪ蝠・    
parent[i]=-2;//隕ｪ縺ｧ縺ｪ縺・・繝ｼ2
  }
  visit[start]=1;Enqueue(start);
  parent[start]=-1;
  while(queuehead!=queuetail){
    n=Dequeue();
    if(n==end) return 1;
    else{
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


#include<stdio.h>
#include<malloc/malloc.h>
#include "PLIB2.h"
#define N 6 //頂点の数
static int adj[N][N]={
//隣接行列：(隣接有り = 1, 隣接無し = 0)
  {0,1,0,1,1,0},
  {1,0,1,0,1,0},
  {0,1,0,0,1,0},
  {1,0,0,0,1,1},
  {1,1,1,1,0,1},
  {0,0,0,1,1,0},
};
static char V[N+1]="S12345";
static int start=0;
static int end=5;
int main(void){
  int i,n,visit[N]; //(未訪問 = 0, 訪問済 = 1)
  printf("/***(112頁)chap-6-4-2.グラフの探索(幅優先)***\n");
  queuehead=queuetail=0;
  for(i=0;i<N;i++){
    // 全ノード未訪問に設定
    visit[i]=0;
  }
  visit[start]=1;
  Enqueue(0);
  while(queuehead!=queuetail)
  {
    n=Dequeue(); //キューからデータを一個取り出す
    printf("Visit:%c(%d)\n",V[n],n);
  	if(n==end){
  	   printf("***solved***Goal=%c(%d)\n",V[n],n);
  	   printf("\n");
  	   return 0;
  	}
    else{
      for(i=0;i<N;i++){
        if(visit[i]!=1 && adj[n][i]==1){
          visit[i]=1;
          Enqueue(i);
        }
  	  }
    }
  }
  printf("\n*/\n");
  return 0;
}

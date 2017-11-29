#include<stdio.h>
#include "PLIB2.h" 
#define N 6 
static int w[N][N]={
  {0,1,0,1,1,0}, 
  {1,0,1,0,0,0}, 
  {0,1,0,0,0,0}, 
  {1,0,0,0,1,1}, 
  {1,0,0,1,0,1}, 
  {0,0,0,1,1,0}  
}; 
static char V[N+1]="S12345";
static int start=0; 
static int end=6; 
void DFS_R(int,int*);
int main(void){
  int i,n,visit[N]; 
  puts("/***(P115)chap6-4 2.グラフの探索(深さ優先探索:再帰版)***\n");
  for(i=0;i<N;i++){
    visit[i]=0;    
  }
  visit[start]=1; 
  DFS_R(start,visit); 
  printf("\n*/\n");
}


void DFS_R(int n,int *visit){
  int i;
  printf("Visit:%c(%d)\n",V[n],n);
  if(n==end){
    printf("***solved***Goal=%c(%d)\n",V[n],n);
    return ;
  }
  for(i=0;i<N;i++)
    if(w[n][i]==1 && visit[i]==0){
      visit[i]=1; 
      DFS_R(i,visit);
    }
}


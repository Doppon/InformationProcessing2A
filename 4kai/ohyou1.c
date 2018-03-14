#include<stdio.h>
#include<malloc/malloc.h>
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
int main(void){
  int i,n,visit[N];
  printf("***chap6-4 2グラフの探索(深さ優先)***\n");
  for(i=0; i<N; i++){
    visit[i] = 0;
  }
  stacktop = 0;
  sides = 0;
  push(start);
  while(stacktop>0){
    n = pop();
    printf("pop=%d ",n);
    if(visit[n] == 0){
      visit[n] = 1;
      sides = n;
      printf("\nVisit:%c\n",V[n]);
      if(n == end){
        printf("***solved***Goal=%c\n",V[n]);
      }
      else{
        for(i=N; i>=0; i--){
          if(w[n][i]==1&&visit[i]==0){
            push(i);
            printf("push=%d ",i);
          }
        }
      }
    }
  }
  printf("\n*/\n");
}

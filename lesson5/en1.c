//演習３
#include<stdio.h>
#define N 9
#define M 99.0
static double w[N][N]={
  {M,2.0,M,M,1.0,2.0,M,M,M},
  {M,M,3.0,M,M,M,4.0,M,M},
  {M,M,M,1.0,M,M,M,M,M},
  {M,M,M,M,M,M,M,M,1.0},
  {M,M,M,M,M,3.0,M,M,M},
  {M,M,M,4.0,M,M,2.0,M,M},
  {M,M,0.5,M,M,M,M,1.0,M},
  {M,M,M,M,M,M,M,M,2.0},
  {M,M,M,M,M,M,M,M,M}};
static char V[N+1]="sabcdefgh";
double cost[N];
int visit[N];
int parent[N];
void shortest_path(void);
void printprocess(int);
int start;
int check;
int main(void){
  int j,k,p;
  double min;
  printf("/***(120頁)アルゴリズム6.4(Dijistra法)***");
  printf("\n開始頂点番号、プリント指定(1=point,0=not)を入力　:例　0 1\n");
  scanf("%d%d",&start,&check);
  if(start<0||N<=start){
    printf("頂点指定エラー　%d,start");
    return;}
  if(check==1){
    printf("cost=開始点からのコスト和(99.9:到達不可),visit=1(訪問済)　\n");
    printf("parent=直前頂点(-1:開始点の直前,-2:直前頂点なし)\n");
  }
  printf("\n頂点 %c(%d)から開始\n",V[start],start);
  for(k=0;k<N;k++){
    cost[k]=M;
    visit[k]=0;
    parent[k]=-2;
  }
  cost[start]=0;
  parent[start]=-1;
  for(j=0;j<N;j++){
    min=M;
    for(k=0;k<N;k++){
      if(visit[k]==0&&cost[k]<min){
        min=cost[k];
        p=k;
      }
    }
    visit[p]=1;
    for(k=0;k<N;k++){
      if((cost[p]+w[p][k])<cost[k]){
        cost[k]=cost[p]+w[p][k];
        parent[k]=p;
      }
    }
    if(check==1)
      printprocess(j+1);
    }
    shortest_path();
    printf("\n*/\n");
}
void shortest_path(void){
  int k,i,p,q,path[N];
  printf("開始点からの全ての点へのコスト和を表示(Dijkstra法)");
  for(k=0;k<N;k++){
    if(cost[k]==M){
      printf("\ntotal cost=%2.1f(from %d to %d)No Path",cost[k],start,k);
      continue;
    }
    p=k;q=N-1;
    path[q--]=k;
    while(parent[p]!=-1){
      path[q--]=parent[p];
      p=parent[p];
    }
    path[q]=parent[p];
    printf("\ntotal cost=%02.1f(from %d to %d)",cost[k],start,k);
    for(i=q+1;i<N;i++)printf("-%d-",path[i]);
  }
  return;
}
void printprocess(int j){
 int k;
  printf("%d回目\n",j);
    for(k=0;k<N;k++)
      printf("%c(%2d):cost=%02.1f visit=%1d parent=%2d\n",V[k],k,cost[k],visit[k],parent[k]);    return;}

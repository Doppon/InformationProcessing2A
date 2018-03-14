#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define True 1
#define False 0
#define N0 100
#define M0 100
#define graph "graph_data.txt"
#define print_tree 1

int N = N0, M = M0;
int m;
float tree_total_cost=0.0;
struct node{ int father;};
struct arc{
  int no;//枝番号
  int node1,node2;//両端の節点
  float cost;//枝のコスト
};
struct node NODE[N0+1];//ノード番号
struct arc ARC[M0+1];//アーク番号

void Kruskal();
void Sort_Arcs(struct arc a[],int left,int right);
void Read_Data();
void Print_Data();

int main(void){
  // 無向グラフの最小完全木
  Read_Data();
  Print_Data();
  Sort_Arcs(ARC,1,M);
  Kruskal();
  printf("\n\n3. ツリー総コスト = %7.2f\n",tree_total_cost);
  printf("\n");
  return 0;
}

void Kruskal(){
  int i,k,u,v;
  for(i=1;i<=N;i++){
    NODE[i].father = i;
  }
  m = 0;
  for(k=1;k<=M;k++){
    u = ARC[k].node1;
    v = ARC[k].node2;
    while(u!=NODE[u].father){
      u = NODE[u].father;
    }
    while(v!=NODE[v].father){
      v = NODE[v].father;
    }
    if(u!=v){
      // 両端が異なるグループに属するとき
      NODE[u].father = v;// 代表店を合併
      tree_total_cost += ARC[k].cost;
      printf("  %3d  %3d  %3d\t%7.2f\n",ARC[k].no,ARC[k].node1,ARC[k].node2,ARC[k].cost);
      m++;
    }
    if(m>=N-1) break;
  }
}

void Sort_Arcs(struct arc a[], int left, int right){//ソート
  int i,j;
  struct arc s,t;  
  if(left<right){
    s = a[(left+right)/2];
    i = left - 1;
    j = right + 1;
    while(1){
      while(a[++i].cost<s.cost);
      while(a[--j].cost>s.cost);
      if(i>=j){
        break;
      }      
      t = a[i];
      a[i] = a[j];
      a[j] = t; 
    }
    Sort_Arcs(a,left,i-1);
    Sort_Arcs(a,j+1,right); 
  }
}

void Read_Data() {
  FILE *fp;
  fp = fopen("graph_data.txt","r");

  if(fp==NULL){
    printf("ファイルオープン失敗\n");
    return;
  }

  int n = 0;
  int no[1];
  int node[2];
  float cost[1];

  while( !feof(fp) && n < 100 ){
    fscanf(fp,"{%d,%d,%d,%f}\n",&no[0],&node[0],&node[1],&cost[0]);
    ARC[n].no = no[0];
    ARC[n].node1 = node[0];
    ARC[n].node2 = node[1];
    ARC[n].cost = cost[0];
    n++;
  }

  fclose(fp);
}

void Print_Data(){
  int k;
  printf("/*** 完全最小木問題 ***\n\n");
  printf("1. 入力データ \n");
  printf("  枝  始点  終点  コスト\n");
  for(k=1;k<=M;k++){
    printf("  %3d  %3d  %3d  %7.2f\n",ARC[k].no,ARC[k].node1,ARC[k].node2,ARC[k].cost);
  }
  printf("\n\n 2. 最小完全木\n");
  printf("  枝  始点  終点  コスト\n");
}

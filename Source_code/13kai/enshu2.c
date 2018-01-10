#include<stdio.h>
#include<math.h>
#define True 1
#define False 0
#define N0 6
#define M0 13
#define print_tree 1
int N=N0,M=M0;
int m;
float tree_total_cost=0.0;
struct node{ int father;};
struct arc{
  int no;
  int node1,node2;
  float cost;
};
void Kruskal();
void Sort_Arcs(struct arc a[],int left,int right);
void Print_Data();
struct node NODE[N0+1];
struct arc ARC[M0+1]={
{0,0,0,0.0},
{1,1,3,1.0},
{2,3,5,9.0},
{3,5,6,2.0},
{4,4,6,12.0},
{5,2,4,5.0},
{6,1,2,4.0},
{7,3,4,8.0},
{8,1,5,7.0},
{9,2,6,6.0},
{10,1,4,7.0},
{11,2,3,3.0},
{12,3,6,11.0},
{13,4,5,10.0}
};

int main(void){
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
      NODE[u].father = v;
      tree_total_cost += ARC[k].cost;
      printf("  %3d  %3d  %3d\t%7.2f\n",ARC[k].no,ARC[k].node1,ARC[k].node2,ARC[k].cost);
      m++;
    }
    if(m>=N-1)
      break;
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

#include<stdio.h>
  int main(){
    struct arc{
    int no;//枝番号
    int node1,node2;//両端の節点
    float cost;//枝のコスト
  };

  struct arc ARC[16]

  FILE *fp;
  fp = fopen("graph_data.txt","r");

  int n = 0;
  int no[1];
  int node[2];
  float cost[1];

  while(  ){
    fscanf(fp,"{%d,%d,%d,%f}",&no[0],&node[0],&node[1],&cost[0]);
    ARC[n].no = no[0];
    ARC[n].node1 = node[0];
    ARC[n].node2 = node[1];
    ARC[n].cost = cost[0];
  }

  fclose(fp);
}
#include<stdio.h>
#define n 5
#define WMAX 10
int C =WMAX;
typedef struct SOL {
  int v;
  int w;
  int t[n+1];
}SOL;
static int w[n+1]={0,2,3,4,5,6};
static int v[n+1]={0,4,5,8,9,11};
SOL D[1000];
int check(int,int,int);


int main(void){
  int i,j,k,m2,Vmax=0,Wmax2=0,t_max[n+1];//V価値　W重さ　T要素
  int m=0,x=0;
  D[0].v=0;D[0].w=0;
  for(x=0;x<=n;x++){
   D[0].t[x]=0;
  }
  printf("(0,0,{0})追加\n");
  for(k=1;k<=n;k++){
    m2=m;
    for(i=0;i<=m;i++){//既出D[i]
      if(D[i].w+w[k]<=C){
	      if(check(m2,i,k)==1){
	      m2++;
	      D[m2].v=D[i].v+v[k];
	      D[m2].w=D[i].w+w[k];
	        for(j=1;j<=n;j++){
            D[m2].t[j]=D[i].t[j];
          }
          D[m2].t[k]=1;
          printf("(%d,%d,{",D[m2].v,D[m2].w);
          for(x=1;x<=n;x++){
            if(D[m2].t[x]==1){
              printf("%d,",x);
            }
          }
	        printf("\b})を追加");
          if(D[m2].v>Vmax){
            Vmax=D[m2].v;
            Wmax2=D[m2].w;
            for(j=1;j<=n;j++){
              t_max[j]=D[m2].t[j];
            }
          }
	      }
      }
    }
    printf("\n");
    m=m2;
  }
  //???最適解の表示
  printf("\n\n最適解は (%d,%d,{",Vmax,Wmax2);
  for(x=1;x<=n;x++){
    if(D[m2].t[x]==1){
      printf("%d,",x);
    }
  }
  printf("\b})\n");
  return 0;
}

int check(int m,int i,int k){
  int p;//return 0;重複
  for(p=0;p<=m;p++){
    if((D[p].v >= D[i].v+v[k]) && (D[p].w == D[i].w+w[k])){
      return 0;
    }
  }
  return 1;
}


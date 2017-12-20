#include<stdio.h>
#define n 5
#define WMAX 10
int C =WMAX;
typedef struct SOL {
  int v;
  int w;
  int t[n+1];//ナニコレｗ -> 多分、判定の鍵
}SOL;

static int w[n+1]={0,2,3,4,5,6};
static int v[n+1]={0,4,5,8,9,11};
SOL D[1000];
int check(int,int,int); //自分の言ってた単価について計算

int main(void){
  int i,j,k,m2,Vmax=0,Wmax2=0,t_max[n+1];//V価値　W重さ　T要素
  int m=0;

  //初期化を行う
  D[0].v=0;
  D[0].w=0;
  for(k=0;k<=n;k++){
   D[0].t[k]=0;
  }
  printf("\n(0,0,{0})追加 => 初期化完了!!\n");

  for(k=1;k<=n;k++){
    m2=m;
    for(i=0;i<=m;i++){
      if(D[i].w+w[k]<=C){ //重量制限のチェック
	      if(check(m2,i,k)==1){
	      m2++;
	      D[m2].v=D[i].v+v[k];
	      D[m2].w=D[i].w+w[k];
	        for(j=1;j<=n;j++){
            D[m2].t[j]=D[i].t[j];
          }
          D[m2].t[k]=1;
          //新しく追加した解の表示
          printf("(%d,%d,{",D[m2].v,D[m2].w);
          for(k=1;k<=n;k++){
            if(D[m2].t[k]==1){
              printf("%d,",k);
            }
          }
	        printf("\b})を追加\n");

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
    m=m2;
  }
  //最適解の表示
  printf("最適解は (%d,%d,{",Vmax,Wmax2);
  for(k=1;k<=n;k++){
    if(D[m2].t[k]==1){
      printf("%d,",k);
    }
  }
  printf("\b})\n\n"); //バックスペーズを用いて綺麗に合わせるテク
  return 0;
}

int check(int m,int i,int k){
  int p;//return 0;重複
  for(p=0;p<=m;p++){
    if((D[p].w == D[i].w+w[k]) && (D[p].v >= D[i].v+v[k])){
      return 0;
    }
  }
  return 1;
}


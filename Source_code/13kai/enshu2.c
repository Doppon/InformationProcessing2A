#include<stdio.h>
#define n 5
#define WMAX 10
int C = WMAX;
typedef struct cell{int v;int t[n+1];}cell;
static int w[n+1]={0,2,3,4,5,6};
static int v[n+1]={0,4,5,8,9,11};
cell D[n+1][WMAX+1];
int main(void){
  int i,j,k,q,x,g,Vmax=0,t_max[n+1];
  for(j=0;j<=C;j++){
    D[0][j].v=0;//初期化
    for(k=0;k<=n+1;k++){
      D[0][j].t[k]=0;//t[0]~t[n+1]=0,ただt[0]使わないからk=1でよくね?
    }
  }
  for(i=1;i<=n;i++){//D[0][x]は自明でv=0,t={��}
    for(j=0;j<=C;j++){
      if(j<w[i]){
	D[i][j].v=D[i-1][j].v;//コピー[i-1?
	for(k=1;k<=n+1;k++){
	  D[i][j].t[k]=D[i-1][j].t[k];//コピーt[k-1?
	}
      }else{//j>w
	//荷物iを加えたセルで価値が高い→更新
	if(D[i-1][j-w[i]].v+v[i]>D[i-1][j].v){//w[i]
	  D[i][j].v=D[i-1][j-w[i]].v+v[i];//w[i]
	  for(k=1;k<=n;k++){
	    D[i][j].t[k]=D[i-1][j-w[i]].t[k];
	  }
	  D[i][j].t[i]=1;//判定
	  if(D[i][j].v>Vmax){
	    Vmax=D[i][j].v;
	    for(k=1;k<=n;k++){//1-nまで(t[5]→6番目
	      t_max[k]=D[i][j].t[k];
	    }
	  }
	}else{
//価値が高まらない場合
	  D[i][j].v=D[i-1][j].v;
	  for(k=1;k<=n;k++){
	    D[i][j].t[k]=D[i-1][j].t[k];
}
	}}//出力
      printf("[v=%d,T=",D[i][j].v);
      printf("{");q=0;
	for(g=1;g<=n;g++){
	  if(D[i][j].t[g]==1){
	      q=1; 
	    printf("%d,",g);
             }
	}
		if(q!=1){printf(" ");}
	printf("\b}]");


      
      }
    printf("\n");
  }
  printf("\n\n最適解は[v=%d:T={",Vmax);
  x=0;
   
  
	
	for(x=1;x<=n+1;x++){
	  if(t_max[x]==1){
	  
	    printf("%d,",x);
             }
	}
	printf("\b}]\n");
	return 0;



}

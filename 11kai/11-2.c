#include<stdio.h>
//#define M 99999
//int F[M];

int fib(int n){
  int i,t;
  long int F[n];
  F[0]=F[1]=1;//長整数型9,223,372,036,854,775,808～9,223,372,036,854,775,807
  //  printf("\n%d\n",F[0]);
  for(i=2;i<=n;i++){
    F[i]=F[i-1]+F[i-2];
    //t=F[i];//応急処置。どうしたら上手く動くか謎
  }
  return F[n];
}

int main(void){
  int i,n;
  printf("解法アルゴリズム２：動的計画法\n");
  printf("F(n)までを求める:n=");
  scanf("%d",&n);
  for(i=0;i<=n;i++){
    printf("F(%d)=%d\n",i,fib(i));
  }
  return 0;
}

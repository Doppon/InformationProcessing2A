#include <stdio.h>
int main(void){
  int n,m,i,max,a,b,t;

  printf("mの数値を入力してください:");
  scanf("%d",&m);
  printf("nの数値を入力してください:");
  scanf("%d",&n);
  printf("\n");

  if(n>m){
    max=m;
  }else{
    max=n;
  }

  for(i=1;i<=max;i++){
    a=m%i;
    b=n%i;
    if(a==0&&b==0){
      printf("約数:%d\n",i);
      t=i;
    }
  }
  printf("------------------------");
  printf("\n%dと%dの最小公約数:%d\n",m,n,t);
  return 0;
}

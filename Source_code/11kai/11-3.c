#include<stdio.h>
int main(void){
  int a=1,b=1,i,n,c;
  printf("解法アルゴリズム３：メモリ量の節約\n");
  printf("f(n)までを求める。\nn=");
  scanf("%d",&n);
  for(i=0;i<=n;i++){
    if(i>1){
    c=a+b;
    a=b;
    b=c;
    //    printf("aaaaaaaa");
    }
  printf("f(%d)=%d\n",i,b);
  
    }


}

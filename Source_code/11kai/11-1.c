#include<stdio.h>
int main(void){
  int i,n,x;
  printf("F(n)までを求めるn=");
  scanf("%d",&n);
  for(i=0;i<=n;i++){
    x=F(i);
    printf("F(%d)=%d\n",i,x);
  }
}

int F(int n){
  if((n==0 || n==1)){
    return 1;
  }else if(n >=2){
    return F(n-1) + F(n-2);
  }else{
    return -1;
  }
}

#include <stdio.h>
int gcd(int,int);
int main(void){
  int a,b,g;
  printf("mの数値を入力してください:");
  scanf("%d",&a);
  printf("nの数値を入力してください:");
  scanf("%d",&b);
  g=gcd(a,b);
  printf("%dと%dの最大公約数は%d\n",a,b,g);
  return 0;
}
int gcd(int m, int n){
  if(n==0){
    return m;
  }else{
    return gcd(n,m%n);
  }
}

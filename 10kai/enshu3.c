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
int gcd(int m,int n){
  int t=0;
  while(n != 0){
    t = m % n;
    m = n;
    n = t;
  }
  return m;
}


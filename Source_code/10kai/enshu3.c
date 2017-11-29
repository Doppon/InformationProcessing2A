#include <stdio.h>
int gcd(int,int);




int main(void){
  int a,b,x;
  printf("解法アルゴリズム３：(２)の高速化\n");
  printf("m:");
  scanf("%d",&a);
  printf("n:");
  scanf("%d",&b);
  x=gcd(a,b);
  printf("%dと%dの最大公約数は%d\n",a,b,x);



}
int gcd(int m,int n){
  int t;
  while(t!=0){
   
    t=m%n;
    m=n;
    n=t;
}
  return m;
  }

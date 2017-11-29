#include <stdio.h>
int gcd(int,int);
int main(void){
  int x,a,b,t;//
  printf("アルゴリズム５：（４）の高速化\n");
  printf("m:");
  scanf("%d",&a);
  printf("n:");
  scanf("%d",&b);



  t=gcd(a,b);

  printf("%dと%dの最小公倍数は%d\n",a,b,t);

  return 0;


}
int gcd(int m, int n){

  if(n==0){
    return m;
  }
  else {

    return gcd(n,m%n);
  }}

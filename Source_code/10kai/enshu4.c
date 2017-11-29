#include <stdio.h>
int gcd(int,int);
int main(void){
  int x,a,b,t;//
  printf("アルゴリズム４：再帰を用いた解法\n");
  printf("m:");
  scanf("%d",&a);
  printf("n:");
  scanf("%d",&b);



  t=gcd(a,b);

  printf("%dと%dの最大公約数は%d\n",a,b,t);

  return 0;


}
int gcd(int m, int n){

    if(m>n){
      return gcd(m-n,n);
    }
    else if(n>m){
      return gcd(m,n-m);
    }else{

  

  return m;

    }}

#include <stdio.h>
int gcd(int,int);


int gcd(int m, int n){

      while(m!=n){
  	if(m>n){
	  m=m-n;
	}
	else{
	  n=n-m;
	}
      
      }
  
      return m;

    }
int main(void){
  int a,b,g;
  printf("解法アルゴリズム２：問題をより小さな問題にする\n");
  printf("m:");
  scanf("%d",&a);
  printf("n:");
  scanf("%d",&b);
  g=gcd(a,b);
  printf("%dと%dの最大公約数は%d\n",a,b,g);
  return 0;}







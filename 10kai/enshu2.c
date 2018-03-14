#include <stdio.h>
int gcd(int,int);
int gcd(int m, int n){
  while(m!=n){
  	if(m>n){
	    m=m-n;
	  }else{
	    n=n-m;
	  }
  }
  return m;
}
int main(void){
  int a,b,g;
  printf("mの数値を入力してください:");
  scanf("%d",&a);
  printf("nの数値を入力してください:");
  scanf("%d",&b);
  g=gcd(a,b);
  printf("------------------------\n");
  printf("%dと%dの最大公約数は%d\n",a,b,g);
  return 0;
}







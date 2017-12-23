#include <stdio.h>
int main(void){
  int n;
  printf("硬貨交換する金額を入力：");
  scanf("%d",&n);
 
 

  //////////////void Change(x){
  int a,b,c,d;//50 10 5 1
  int m;
  a=n/50; m=n%50;
  b=m/10; n=m%10;
  c=n/5; m=n%5;
  d=m;
  printf("交換結果\n50円玉:%d枚\n10円玉:%d枚\n5円玉:%d枚\n1円玉:%d枚\n",a,b,c,d);

  return 0;
}

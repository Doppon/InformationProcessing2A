#include<stdio.h>
#include"PLIB2.h"
int main(void){
  int a,b;
  while(a!=3){
    printf("You can chose the operating. Puts the number\n1.Push,2.Pop,3.End　:");
    scanf("%d",&a);
    if(a==1){
      printf("Please puts the data input to the stack:");
      scanf("%d",&b);
      push(b);
      printstack(stack);
    }
    else if(a==2){
      pop();
      printstack(stack);
    }
    else if(a==3){
      printf("終了します\n");
      break ;
    }
    else{
      printf("数値は1から3までです\nもう一度入力してください\n");
      continue ;
    }
  }
}

#include<stdio.h>
#include "PLIB2.h"
int main(void){
  int x,y;
  printf("---キューの操作---\n");
  while(x!=3){
    printf("操作を選択してください\n1．Enqueue/2.Dequeue/3.終了\n  No:");
    scanf("%d",&x);
    if(x==1){
      printf("挿入するデータを入力してください:");
      scanf("%d",&y);
      Enqueue(y);
      printqueue();
    }else if(x==2){
      y=Dequeue();
      printf("Dequeue: %d\n",y);
      printqueue();
    }else if(x==3){
      printf("キューの操作を終了します\n");
      break;
    }else{
      printf("---Error---\n指定された操作から選択してください\n---\n");
    }
  }
  return 0;
}

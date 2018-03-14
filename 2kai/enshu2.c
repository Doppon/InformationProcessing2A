#include<stdio.h>
#include "PLIB.h"
#define HEAPSIZE 100
int heap[HEAPSIZE];
#define data_number 10
static int data[data_number]={58,12,39,90,49,26,68,47,15,39};
void pushheap(int *,int *,int);

void pushheap(int *heap,int *n,int x){
  int i,j;
  if(++(*n)>=HEAPSIZE){
   printf("Heap Overflow");
   return;
  }
  else{
    heap[*n]=x;
    i=*n;
    j=i/2;
    //printf("\n%d,&d\n\n",i,j);
    while((j>0)&&(x>heap[j])){
      heap[i]=heap[j];
      i=j;
      j=i/2;
      //printf("\n%d,&d\n\n",i,j);
    }
    heap[i]=x;
  }
}

int maxheap(int *heap,int *n){
  int x,i,j,t;
  if(*n==0){
    printf("Heap Underflow");
    return -1;
  }
  else{
    x=heap[1];
    heap[1]=heap[(*n)--];
    i=1;
    while(i*2<=*n){
      j=i*2;
      if((i*2+1<=(*n))&&(heap[i*2]<heap[i*2+1]))j=i*2+1;
      if(heap[i]>=heap[j]) break;
      else{
      	t=heap[i];heap[i]=heap[j];heap[j]=t;
      }
      i=j;
    }
  }
  return x;
}

int main(void){
  int i=0,number=0;
  printf("--- データをヒープに格納 ---\n");
  printf("start ");
  printheap(heap,number);
  for(i=0;i<data_number;i++){
    printf("in =%2d",data[i]);
    pushheap(heap,&number,data[i]);
      printheap(heap,number);
  }
  printf("\n--- Heapから最大要素の取り出し ---\n");
  printf("start  ");
  printheap(heap,number);
  while(number>0){
    printf("out=%02d ",maxheap(heap,&number));
    printheap(heap,number);
  }
  return 0;
}

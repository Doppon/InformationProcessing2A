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
    while( (j>0) && (x>heap[j]) ){
      heap[i]=heap[j];
      i=j;
      j=i/2;
    }
    heap[i]=x;
  }
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
}

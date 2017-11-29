
#include<stdio.h>
#define N 10
#include "PLIB.h"
static int data[N]={58,12,39,90,49,26,68,47,15,39};
void swap(int*,int*);
void printdata(int*,int);
void quicksort(int,int);


void swap(int *a,int *b){
  int g;
  g=*a;
  *a=*b;
  *b=g;
}
void printdata(int* data,int n){
  int i;
  for(i=0;i<n;i++)
    printf("%02d ",data[i]);
}

void quicksort(int l,int h){
  int i,j,mid,x;
  if(l<h){
    mid=(l+h)/2;
    x=data[mid];
    i=l;j=h;
    printdata(data,N);
    printf("(i=%d,mid=%d,j=%d,x=%d)\n",i,mid,j,x);
    while(i<=j){
      while(data[i]<x)i++;
      while(data[j]>x)j--;
      if(i<=j)swap(&data[i++],&data[j--]);
    }
    quicksort(l,j);
    quicksort(i,h);
  }


}


int main(void){

  printf("***　クイックソート　**\n");
  quicksort(0,N-1);
  printdata(data,N);
  printf("\n*/\n");
  return 0;
}



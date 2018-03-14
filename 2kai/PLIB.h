void printsort(int *data,int n,int k){
  int i;
  printf("\n%2d回目のスキャン結果",k);
  for(i=0;i<n;i++)printf("%d ",data[i]);
}
void printheap(int *heap,int n){
  int i;
  printf("heap(n=%02d):",n);
  for(i=1;i<=n;i++)
    printf("%02d ",heap[i]);
  printf("\n");
}

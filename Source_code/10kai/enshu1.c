#include <stdio.h>
int main(void){
  int n,m,i,x,a,b,t;//
  printf("解法アルゴリズム１：原始的な方法\n");
  printf("m:");
  scanf("%d",&m);
  printf("n:");
  scanf("%d",&n);
  printf("\n//計算過程\n");
  if(n>m){x=m;
  }else{x=n;
}

  for(i=1;i<=x;i++){
    a=m%i;
    b=n%i;
    if(a==0&&b==0){
      printf("%d\n",i);
      t=i;
    }
}






  
  printf("//\n%dと%dの最小公約数は %d\n",m,n,t);

  return 0;


}

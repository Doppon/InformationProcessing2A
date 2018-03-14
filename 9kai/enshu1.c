#include<stdio.h>
#include<string.h>
int AL71(char*,int,char*,int);
int main(void){
  char T[]="Saitama Ken Ohmiya shi Fukasaku 308 Shibaura";
  char P1[]="Fukasaku",P2[]="Tamachi";

  int nn,rc;//rc:return code
  printf("/***(アルゴリズム7.1力まかせ法)**\n");
  nn=sizeof(T)-1;
  rc=AL71(T,nn,P1,sizeof(P1)-1);
  if(rc>=0) printf("%sの位置は %d\n",P1,rc);
  else printf("%sはテキストに含まれない\n",P1);
  rc=AL71(T,nn,P2,sizeof(P2)-1);
  if(rc>=0) printf("%sの位置は %d\n",P2,rc);
  else printf("%sはテキストに含まれない\n",P2);printf("\n");
  return 0;
}
int AL71(char *T,int n,char *P,int m){
  int i,j;
  for(i=0;i<n-m;i++){
    for(j=0;j<m;j++)
      if(T[i+j]!=P[j])
	    break;
      if(j==m)
      return i;
	}
  return -1;
}

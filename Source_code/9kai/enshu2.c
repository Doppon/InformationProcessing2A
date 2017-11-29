//P145 アルゴリズム7.5（ボイヤームーア法
#include<stdio.h>
#include<string.h>

int BM(char*,int,char*,int);
void make_shift1(char*,int);
void make_shift2(char*,int);
int shift1[256],shift2[32],icase[32];
void print_shift1();
void print_shift2();


int main(void){
  char T[]="XJKLySAKLBASDBJKLBJKABCSASBJDH%A%JKLBSAABS";
  char P[]="JKLBJK";

  int n,m,rc;
  printf("/** アルゴリズム 7.5(ボイヤームーア法)**\n");
  printf("T=%s\nP=%s\n",T,P);
  n=strlen(T); m=strlen(P);
  make_shift1(P,m);print_shift1();
  make_shift2(P,m);print_shift2(P,m);

  rc=BM(T,n,P,m)+1;//テキストの先頭を1番目
  if(rc>=0)
    printf("\n%sをテキスト先頭(＝1番目)から %d 番目に検出\n",P,rc);
  else
    printf("\nテキスト内に、 %s は見つかりません(終了)\n",P);
  printf("*/\n");
  return 0;
}


int BM(char* T,int n,char* P,int m){

  int i=0,j,max,iflag;
  
  while(i<=n-m){
    iflag=0;
    for(j=m-1;j>=0;j--)if(T[i+j]!=P[j]){iflag=1;break;}
    if(iflag==0) return i;
    printf("\nT[%3d]=%c P[%d]=%c",i+j,T[i+j],j,P[j]);
    
    max=(j-shift1[(int)T[i+j]])>=shift2[j] ? (j-shift1[(int)T[i+j]]) : shift2[j];
    
    /* 次の5行のプリント出力は途中経過観測 */
    printf("\nT[%3d]=%c P[%d]=%c ",i+j,T[i+j],j,P[j]);
    if((j-shift1[(int)T[i+j]])>=shift2[j])
      printf("(i+j=%2d j=%d max=j-shift1[%c]=%d selected)",i+j,j,T[i+j],j-shift1[(int)T[i+j]]);
    else
      printf("(i+j=%2d j=%d max=shift2[%d]=%d selected)",i+j,j,j,shift2[j]);
    i+=max;
    
  }
  return -1;
}

void make_shift1(char *P,int len){
  int i;
  for(i=0;i<256;i++)shift1[i]=-1;
  for(i=0;i<len;i++)shift1[(int)P[i]]=i;
}

void make_shift2(char *P,int m){
  int ip,j,k,nflag;
  for(j=0;j<m;j++){
    shift2[j]=m;
    icase[j]=3;
  }

  for(j=m-1;j>0;j--){
    for(k=0;k<=j;k++){//
      nflag=0;
      for(ip=m-1;ip>=j+1;ip--){//
        if(P[ip-k]!=P[ip]){nflag=1;break;}
        }
        if((nflag==0)&&(P[j-k]!=P[j])){//
          shift2[j]=k;icase[j]=1;break;
        }
      }
      if(icase[j]==1) continue;
      for(k=j+1;k<=m-1;k++){//
        nflag=0;
        for(ip=m-1;ip>=k;ip--){//
          if(P[ip-k]!=P[ip]){nflag=1;break;}
        }
        if(nflag==0){
          shift2[j]=k;icase[j]=2;break;
        }
      }
    }
  }
void print_shift1(){
  int i;
  for(i=32;i<127;i++)
    if(shift1[i]>=0) printf("shift1[%c]=%2d\n",(char)i,shift1[i]);
  printf("shift1[他の文字] = -1\n");printf("\n");
}
void print_shift2(char *P,int m){int i;
  for(i=0;i<m;i++)printf("shift2[%d]=%d(case%1d)\n",i,shift2[i],icase[i]);
  printf("\n");

}



#include<stdio.h>
#define n 5
#define WMAX 10
int C = WMAX;
typedef struct cell{int v;int t[n+1];}cell;
static int w[n+1]={0,2,3,4,5,6};
static int v[n+1]={0,4,5,8,9,11};
cell D[n+1][WMAX+1];
int main(void){
  int i,j,k,q,x,g,Vmax=0,t_max[n+1];
  for(j=0;j<=C;j++){
    D[0][j].v=0;//�����
    for(k=0;k<=n+1;k++){
      D[0][j].t[k]=0;//t[0]~t[n+1]=0,����t[0]�Ȥ�ʤ�����k=1�Ǥ褯��?
    }
  }
  for(i=1;i<=n;i++){//D[0][x]�ϼ�����v=0,t={��}
    for(j=0;j<=C;j++){
      if(j<w[i]){
				D[i][j].v=D[i-1][j].v;//���ԡ�[i-1?
					for(k=1;k<=n+1;k++){
	  				D[i][j].t[k]=D[i-1][j].t[k];//���ԡ�t[k-1?
					}
      }else{//j>w
			//��ʪi��ä�������ǲ��ͤ��⤤������
				if(D[i-1][j-w[i]].v+v[i]>D[i-1][j].v){//w[i]
	  			D[i][j].v=D[i-1][j-w[i]].v+v[i];//w[i]
	  			for(k=1;k<=n;k++){
	    			D[i][j].t[k]=D[i-1][j-w[i]].t[k];
	  			}
	  			D[i][j].t[i]=1;//Ƚ��
	  			if(D[i][j].v>Vmax){
	    			Vmax=D[i][j].v;
	    			for(k=1;k<=n;k++){//1-n�ޤ�(t[5]��6����
	      			t_max[k]=D[i][j].t[k];
	    			}
	  			}
				}else{
				//���ͤ���ޤ�ʤ����
	  		D[i][j].v=D[i-1][j].v;
	  		for(k=1;k<=n;k++){
	    	D[i][j].t[k]=D[i-1][j].t[k];
}
	}}//����
      printf("[v=%d,T=",D[i][j].v);
      printf("{");q=0;
	for(g=1;g<=n;g++){
	  if(D[i][j].t[g]==1){
	      q=1; 
	    printf("%d,",g);
             }
	}
		if(q!=1){printf(" ");}
	printf("\b}]");


      
      }
    printf("\n");
  }
  printf("\n\n��Ŭ���[v=%d:T={",Vmax);
  x=0;
   
	for(x=1;x<=n+1;x++){
	  if(t_max[x]==1){
	  
	    printf("%d,",x);
             }
	}
	printf("\b}]\n");
	return 0;
}

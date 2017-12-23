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
    D[0][j].v=0;
    for(k=0;k<=n;k++){
      D[0][j].t[k]=0;
    }
  }
  for(i=1;i<=n;i++){
    for(j=0;j<=C;j++){
      if(j<w[i]){
				D[i][j].v=D[i-1][j].v;
					for(k=1;k<=n;k++){
	  				D[i][j].t[k]=D[i-1][j].t[k];
					}
      }else{
				if(D[i-1][j-w[i]].v+v[i]>D[i-1][j].v){//w[i]
	  			D[i][j].v=D[i-1][j-w[i]].v+v[i];//w[i]
	  			for(k=1;k<=n;k++){
	    			D[i][j].t[k]=D[i-1][j-w[i]].t[k];
	  			}
	  			D[i][j].t[i]=1;
	  			if(D[i][j].v>Vmax){
	    			Vmax=D[i][j].v;
	    			for(k=1;k<=n;k++){
	      			t_max[k]=D[i][j].t[k];
	    			}
	  			}
				}else{
					D[i][j].v=D[i-1][j].v;
					for(k=1;k<=n;k++){
					D[i][j].t[k]=D[i-1][j].t[k];
					}
				}
			}
      printf("[v=%d,T=",D[i][j].v);
      printf("{");q=0;
			for(g=1;g<=n;g++){
	  		if(D[i][j].t[g]==1){
	      q=1; 
	    	printf("%d,",g);
        }
			}
			if(q!=1){printf(" ");}
			printf("\b}]\n");
  	}
  printf("\n");
	}
printf("\n\n最適解:[v=%d:T={",Vmax);
x=0;   
for(x=1;x<=n;x++){
	if(t_max[x]==1){  
	  printf("%d,",x);
  }
}
printf("\b}]\n");
return 0;
}

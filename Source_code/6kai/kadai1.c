//演習４
#include <stdio.h>
#include <stdlib.h>
#define N 9
#define M 99.0
#include <malloc/malloc.h>
struct LIST2{int node;double cost;struct LIST2 *next;};

void printlist(struct LIST2 *head){
  struct LIST2 *p;
  p=head;
  if(p==NULL)printf("printlist: 終了(headの内容=%p)\n",p);//???のヶ所
      printf("head 側からプリント出力(headの内容=%p)\n",head);
  
  while(p!=NULL){
    printf("p=%p,(p->node=%d,p->cost=%f,p->next=%p)\n",p,p->node,p->cost,p->next);
    if(p->next!=NULL)
    p=p->next;
    else
      break;
  }
}


struct LIST2 *inputdata(){
  struct LIST2 *new_r,*tail,*head;int x;double y;
  printf("ノード番号とコストを1行ずつ入力(例:1 2.3(-1 -1:dデータ終了))\n");
  head=tail=NULL;
  while(1){
    scanf("%d %lf",&x,&y);
    if(x<0)break;
    new_r=(struct LIST2 *)malloc(sizeof(struct LIST2));
    if(tail==NULL){
      head=new_r;
  }else{
      tail->next=new_r;
      }
    new_r->node=x;
    new_r->cost=y;
    new_r->next=NULL;
    tail=new_r;
  };
  printlist(head);
  return head;}


static struct LIST2 *nodes[N]={NULL};
static char V[N+1]="sabcdefgh";
double cost[N];
int visit[N];
int parent[N];
void shortest_path(void);
void printprocess(int);
int start;
int check;


int main(void){
  int i,j,k,p,ic=0;
  double min;
  struct LIST2 *tmp_p;
  printf("/***(120頁)アルゴリズム 6.4(Dijkstra法)***");
  printf("重み行列の入力：\n");
  while(1){
    printf("出ノード番号(-1:終了)＝");
    scanf("%d",&i);
    if(i<0)break;
    else nodes[i]=inputdata();
  }
  printf("\n頂点開始番号、プリント指定(1=print,0=not)を入力　:例　0 1\n");
  scanf("%d %d",&start,&check);
  if(start<0||N<=start){printf("頂点指定エラー　%d\n",start);
    return 0;}
  if(check==1){
    printf("cost=開始点からのコスト和(99.9:到達不可),visit=1(訪問済)\n");
    printf("parent=開始頂点(-1:開始点の直前,-2:直前頂点なし\n");
   }
  printf("\n頂点%c(%d)から開始\n",V[start],start);
  for(k=0;k<N;k++){
    cost[k]=M;
    visit[k]=0;
    parent[k]=-2;
  }
  cost[start]=0;
  parent[start]=-1;
  for(j=0;j<N;j++){
    min=M;
    ic=0;
    for(k=0;k<N;k++){
      if(visit[k]==0&&cost[k]<min){
	min=cost[k];
	p=k;
	ic++;
      }
    }
      if(ic==0)break;
      visit[p]=1;
      if(nodes[p]==NULL)continue;
      tmp_p=nodes[p];
      for(k=0;k<N;k++){//↓
	if(cost[p]+tmp_p->cost < cost[tmp_p->node]){
	  cost[tmp_p->node]=cost[p]+tmp_p->cost;
	  parent[tmp_p->node]=p;
	}
	if(tmp_p->next==NULL)break;
	tmp_p=tmp_p->next;
      }//↑
      if(check==1)printprocess(j+1);
  }
    shortest_path();
    printf("\n*/\n");
    return 0;
  }
 
void shortest_path(void){
  int i,k,p,q,path[N];
  printf("\n開始点から全ての点へのコスト和を表示(Dijkstra法)");
  for(k=0;k<N;k++){
    
    if(cost[k]==M){
      printf("\ntotal cost=%2.1f(from %d to %d) No path",cost[k],start,k);
      continue;
    }
    p=k;
    q=N-1; 
    path[q--]=k;
    while(parent[p]!=-1){
      path[q--]=parent[p];
      p=parent[p];
    }
    path[q]=parent[p];
    printf("\ntotal cost=%02.1f(from %d to %d)",cost[k],start,k);    
    for(i=q+1;i<N;i++)
      printf("-%d-",path[i]);
  }
  return;
}

void printprocess(int j){

  int k;
  
  printf("%d回目\n",j);
  
  for(k=0;k<N;k++)
    printf("%c(%2d):cost=%02.1f visit=%1d parent=%2d\n",V[k],k,cost[k],visit[k],parent[k]);
    
}



















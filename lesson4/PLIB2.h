#define STACKSIZE 10000
static int stacktop;
static int stack[STACKSIZE];
void push(int x){
  if(stacktop==STACKSIZE){
    printf("Error:Overflow\n");
    return ;
  }else{
    stack[stacktop++]=x;
  }
}

int pop(void){
  if(stacktop==0){
    printf("Error:Underflow\n");
    return -1;
  }
  return stack[--stacktop];
}

void printstack(int *stack){
  int i=0;
  while(i<stacktop){
    printf("stacs[%d]=%d",i,stack[i]);
    printf("\n");
    i++;
  }
}

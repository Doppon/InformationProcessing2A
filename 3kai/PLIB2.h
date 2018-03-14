#define Q_SIZE 10000
static int queue [Q_SIZE];
static int queuehead;
static int queuetail;
void Enqueue(int x){
  queuetail=(queuetail+1)%Q_SIZE;
  printf("Enqueue:%d(queuehead=%d,queuetail=%d)\n",x,queuehead,queuetail);
  queue[queuetail]=x;
  if(queuehead==queuetail){
    printf("Error:Overflow\n");
    return;
  }
}

int Dequeue(){
  if(queuehead==queuetail){
    printf("Errror:Underflow\n");
    return -1;
  }
  queuehead=(queuehead+1)%Q_SIZE;
  return queue[queuehead];
}

int printqueue(){
  int i;
  if(queuehead==queuetail){
    printf("[キューは空です]");
    return -1;
  }
  else{
    for(i=queuehead+1;i<=queuetail;i++){
      printf("[%d]",queue[i]);
    }
  printf("\n");
  }
  return 0;
}



typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;

void main_init(Queue *q){
  q->headPtr=NULL;
  q->tailPtr=NULL;
  q->size=0;
}
void enqueue_struct(Queue* q, int order,int qty,int cus){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){ 
  new_node -> customer_n = cus ;
  new_node -> order = order ;
  new_node -> qty = qty ;
  new_node -> nextPtr = NULL ;

  if(q->size == 0) q->headPtr = new_node ;
  else q->tailPtr->nextPtr = new_node ;
  q->tailPtr = new_node ;
  q->size++;
 }else printf("No space left.");
}


int dequeue_struct(Queue *q){
   NodePtr t = q->headPtr;
   int price;
  
   if(t){
    int amount = q->headPtr->qty ; 
    switch(q->headPtr->order){
      case 1 : price = 100 ;printf("My order is %d.\n",q->headPtr->order);printf("Customer no : %d.\n",q->headPtr->customer_n);printf("Ramen\n");break ;
      case 2 : price = 20 ;printf("My order is %d.\n",q->headPtr->order); printf("Customer no : %d.\n",q->headPtr->customer_n);printf("Somtum\n");break ;
      case 3 : price = 50 ;printf("My order is %d.\n",q->headPtr->order);printf("Customer no : %d.\n",q->headPtr->customer_n);printf("Fried Chicken\n");break ;
      default : price = 0 ; printf("No food. ") ; break;
    }
    
    int value = amount*price ;

    q->headPtr = t->nextPtr ;
    if(q->size == 1) q->tailPtr = NULL;
    q->size--; 
    free(t);
    return value;
   }
   printf("Empty queue\n");
   return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {

  Queue  q;
  main_init(&q) ;
  
  int i,x,customer_n=1;
  
  for(i=1;i<argc;i++){
    if(strcmp(argv[i],"x")==0) {
      
      if(q.size!=0){
        int prices ;
        printf("\n");
        prices = dequeue_struct(&q);

        printf("You have to pay %d\n",prices);
        int cash ;
      if(prices!=0){
        do{
          printf("Cash : ");
          scanf("%d",&cash) ;
        }while(cash<prices);

        printf("Thank you\n");
        if(cash!=prices)printf("Charge is : %d\n",cash-prices);
          }
        }else dequeue_struct(&q) ;
      }
    else {
      enqueue_struct(&q,atoi(argv[i]),atoi(argv[i+1]),customer_n++);
      i++;
      }
  }

  printf("======================\n");
  printf("There are %d ppl left in the queue.\n",q.size);

  return 0;
}

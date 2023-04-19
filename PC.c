//producer consumer problem using semaphoner
#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=10,x=0;
int choice,i;
void producer(){
	-- mutex;
	++full;
	--empty;
	x++;
	printf("\nProducer produces item %d:",x);
	++mutex;
}


void consumer(){
	--mutex;
	--full;
	++empty;
	printf("\n Consumer consumes item %d:",x);
	x--;
	++mutex;

}
int main(){
	printf("\n******************************************************************************************************\n");
	printf("MENU\n");
	printf("1.PRODUCER\n");
	printf("2.CONSUMER\n");
	printf("3.exit");
	printf("\n******************************************************************************************************\n");
	for(i=1;i>0;i++){
	printf("\nEnter the choice(1/2/3):\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:{
		if((mutex==1)&& (empty!=0)){
			producer();
		}	
		else
			printf("buffer is full");
		break;
		}
	case 2:{
		if ((mutex==1) && (full !=0)){
			consumer();			
		}
		else
			printf("buffer is empty");
		break;
		}
	case 3:
		printf("Chose to exit\n");
		exit(0);
		break;
	default:
		printf("Chose the wrong option!!!");
			
	}

	}
}

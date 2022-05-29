/*
******************************************************************************
*Create date : 2022/5/29
*Last modify date : 2022/5/29
*Usage : 
*	Producer comsumer problem
******************************************************************************
*/
#include "p-c.h"

BUFFER pcBuffer;

static void initialization()
{
	int i;

	create_buffer(&pcBuffer,1,MAXSIZE);

	errno = 0;
	sem_init(&mutex,0,1);
	if (errno) {
		perror("main.c:22:8:error");
		exit(-1);
	}
	sem_init(&items,0,0);
	if (errno) {
		perror("main.c:27:8:error");
		exit(-1);
	}

	sem_init(&items,0,MAXSIZE);
	if (errno) {
		perror("main.c:33:8:error");
		exit(-1);
	}
	
	for (i = 0;i < THREAD_NUM;i++) {
		pthread_t *producertid = 
				(pthread_t *)malloc(sizeof(pthread_t));
		pthread_t *consumertid = 
				(pthread_t *)malloc(sizeof(pthread_t));

		pthread_create(producertid,NULL,producer,&pcBuffer);
		if (errno) {
			perror("main.c:37:8:error");
			exit(-1);
		}
		pthread_create(consumertid,NULL,consumer,&pcBuffer);
		if (errno) {
			perror("main.c:42:8:error");
			exit(-1);
		}
	}
	
}

void test()
{
	int ret;
	create_buffer(&pcBuffer,1,MAXSIZE);
	push(&pcBuffer,10);
	push(&pcBuffer,11);
	push(&pcBuffer,12);
	push(&pcBuffer,13);
	print_stack(&pcBuffer);

	printf("Size:%d\n",pcBuffer.size);
	print_stack(&pcBuffer);
}

int main()
{	
	int err;
	initialization();
	
	while(1) {
	}
}


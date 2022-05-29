/*
******************************************************************************
*Create date : 2022/5/29
*Last modify date : 2022/5/29
*Usage : 
*	Producer comsumer operation header
******************************************************************************
*/
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

#define MAXSIZE 100
#define THREAD_NUM 10

typedef struct BUFFER
{
	int maxsize;
	int *buffer;
	int size;
	int s_top;
}BUFFER;

int pop(BUFFER *stack);
int push(BUFFER *stacl,int a);

void *producer(void *s);
void *consumer(void *s);


int create_buffer(BUFFER *stack,int type,int size);
void print_stack(BUFFER *stack);

int err;


sem_t mutex;
sem_t items;

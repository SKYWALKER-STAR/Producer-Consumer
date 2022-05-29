/*
******************************************************************************
*Create date : 2022/5/29
*Last modify date : 2022/5/29
*Usage : 
*	Producer comsumer operations
******************************************************************************
*/
#include "p-c.h"
/*
******************************************************************************
* @brief	: initialize buffer
* @stack	: stack
* @type		: determin which kind of data you want 
* @size		: buffer size
******************************************************************************
*/

int create_buffer(BUFFER *stack,int type,int size)
{
	int i;
	switch(type) {
		case 1:
			stack->buffer = (int*)malloc(size * 4);
			break;
		default:
			return -1;
	}
	
	for (i = 0;i < size;i++)
		stack->buffer[i] = -1;
	stack->maxsize = size;
	stack->size = 0;
	stack->s_top = 0;
	return 0;
}
/*
******************************************************************************
* @brief	: destroy buffer
* @buffer	: the buffer you want to destroy
******************************************************************************
*/
void destroy_buffer(BUFFER *stack)
{
	free(stack->buffer);
	stack->size = 0;
	stack->s_top = 0;
}

/*
******************************************************************************
* @brief	: pop from stack
* @stack	: 
******************************************************************************
*/
int pop(BUFFER *stack)
{
	int value;
	if (stack->size == 0) {
		printf("From pop error\n");
		return -1;
	}
	else {
		stack->s_top -= 1;
		value = stack->buffer[stack->s_top];
		stack->buffer[stack->s_top] = -1;
		stack->size -= 1;
		return value;
	}
}

/*
******************************************************************************
* @brief	: push into stack
******************************************************************************
*/

int push(BUFFER *stack,int a)
{
	if (stack->size == MAXSIZE) 
		return -1;
	else {
		stack->buffer[stack->s_top] = a;
		stack->s_top += 1;
		stack->size += 1;
		return a;
	}
}

/*
******************************************************************************** @brief		: print stack
********************************************************************************/

void print_stack(BUFFER *stack)
{
	int i;
	for (i = 0;i < stack->maxsize;i++)
		printf("%d ",stack->buffer[i]);
	printf("\n");
}

/*
*******************************************************************************
* @brief	: produce
*******************************************************************************
*/

void *producer(void *stack)
{
	while(1) {
		sem_wait(&mutex);
		push((BUFFER*)stack,1);
		sem_post(&mutex);
		sem_post(&items);
	}
}
/*
******************************************************************************
* @brief	: consumer
******************************************************************************
*/

void *consumer(void *stack)
{
	char c;
	while(1) {
		c = getchar();
		if ( c == 'a') {
			sem_wait(&items);
			sem_wait(&mutex);
			pop((BUFFER*)stack);
			print_stack((BUFFER*)stack);
			sem_post(&mutex);
		}
	}
}


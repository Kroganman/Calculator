#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    float *elem;
    int top;
    int max;
}stack_struct;


float pop(stack_struct *stack)
{
    if(stack->top < 0)
        printf("The number was removed from the stack, but now stack is empty!\n");
    return stack->elem[stack->top--];
}

void push(stack_struct *stack, float elem)
{
    if(stack->top >= stack->max - 1)
        printf("Element added, but there is no more place on the stack!\n");
    stack->elem[++stack->top] = elem;
}

void initStack(stack_struct *stack, int max_elem)
{
    stack->max = max_elem;
    stack->top = -1;
    stack->elem = (float*) malloc(sizeof(float) * max_elem);
    if( stack->elem == NULL)
    {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }
}

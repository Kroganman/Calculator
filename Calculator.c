#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char **argv)
{
    stack_struct *stack = (stack_struct*)malloc(sizeof(stack_struct));
    initStack(stack,argc);

    int j;
    float enter = 0;

    for(j = 1; j < argc; j++)
    {
        if(sscanf(argv[j],"%f",&enter) > 0) /* Check for input */
            push(stack,atof(argv[j]));
        else
        {
            if(*argv[j] == '+')
            {
                push(stack,pop(stack) + pop(stack));
            }
            else
                if(*argv[j] == '*')
                {
		   push(stack,pop(stack) * pop(stack));
                }
            else
                if(*argv[j] == '-')
                {
                   enter = pop(stack);
                   push(stack, pop(stack) - enter);
		}
            else
                if(*argv[j] == '/')
                {
                   enter = pop(stack);
                   push(stack, pop(stack) / enter);
		}
        }
    }

    printf("%.3g\n",stack->elem[stack->top]);

    free(stack->elem);
    free(stack);  /* Stack cleaning */
    return 0;
}

#include "tester.h"

void	test_init_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			printf("%10d |", *(int *)(stack_a->content));
			stack_a = stack_a->next;
		}
		else
			printf("           |");
		if (stack_b != NULL)
		{
			printf("%10d", *(int *)(stack_b->content));
			stack_b = stack_b->next;
		}
		else
			printf("           ");
		printf("\n");
	}
}
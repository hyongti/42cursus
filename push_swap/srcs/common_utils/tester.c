#include "tester.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_a != NULL)
		{
			printf("%10d |", *(int *)(tmp_a->content));
			tmp_a = tmp_a->next;
		}
		else
			printf("           |");
		if (tmp_b != NULL)
		{
			printf("%10d", *(int *)(tmp_b->content));
			tmp_b = tmp_b->next;
		}
		else
			printf("           ");
		printf("\n");
	}
	printf("-----a-----|-----b-----\n\n");
}
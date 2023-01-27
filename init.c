#include "push_swap.h"

void init (int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	//check()

	fillstack(ac, av, stack_a, stack_b);
	
}

void fillstack(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	init_stack(stack_a, ac - 1);
	init_stack(stack_b, ac - 1);
	ac--; //ilk index harici sondan eklemek icin
	while (ac > 0)
	{
		//stack_a->array[i - 1] = ft_atoi(av[i]);
		push(stack_a, ft_atoi(av[ac]));
		ac--;
	}

}


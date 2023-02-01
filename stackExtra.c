/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackExtra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:43:45 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/01 09:51:58 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(t_stack *stack, char *msg)
{
	int	i;

	i = stack->top;
	while (i > -1)
	{
		printf("%d\n", stack->array[i]);
		i--;
	}
	printf("_\n%s top: %d\n", msg, peek(stack));
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	free(stack_a);
	free(stack_b);
}

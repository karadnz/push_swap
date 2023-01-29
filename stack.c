/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:43:57 by mkaraden          #+#    #+#             */
/*   Updated: 2023/01/29 06:41:25 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resize(t_stack *stack)
{
	int	i;
	int	*tmp;
	int	new_size;

	i = 0;
	new_size = stack->size * 2;
	tmp = (int *)malloc(sizeof(int) * new_size);
	while (i < stack->size)
	{
		tmp[i] = stack->array[i];
		i++;
	}
	free(stack->array);
	stack->array = tmp;
	stack->size = new_size;
}

void	init_stack(t_stack *stack, int size)
{
	stack->size = size;
	stack->array = (int *)malloc(sizeof(int) * stack->size);
	stack->top = -1;
}

void	push(t_stack *stack, int num)
{
	if (stack->top > stack->size)
		resize(stack);
	stack->top += 1;
	stack->array[stack->top] = num;
}

void	pop(t_stack *stack)
{
	if (stack->top > -1)
	{
		stack->top -= 1;
	}
}

int	peek(t_stack *stack)
{
	return (stack->array[stack->top]);
}

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

void	freeStacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	free(stack_a);
	free(stack_b);
}

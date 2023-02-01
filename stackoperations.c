/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackoperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:29:19 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/01 09:52:27 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *msg)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
		printf("%s\n", msg);
		return ;
	}
	printf("error at swap\n");
}

void	rotate(t_stack *stack, char *msg)
{
	int	tmp;
	int	i;

	tmp = stack->array[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = tmp;
	printf("%s\n", msg);
}

void	reverse_rotate(t_stack *stack, char *msg)
{
	int	tmp;
	int	i;

	tmp = stack->array[0];
	i = 0;
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = tmp;
	printf("%s\n", msg);
}

void	push_other(t_stack *stack_1, t_stack *stack_2, char *msg)
{
	push(stack_2, stack_1->array[stack_1->top]);
	pop(stack_1);
	printf("%s\n", msg);
}

void	do_twice(t_stack *stack_1, t_stack *stack_2, char *msg)
{
	if (!ft_strncmp(msg, "ss", 2))
	{
		swap(stack_1, "\0");
		swap(stack_2, "\0");
	}
	else if (!ft_strncmp(msg, "rrr", 3))
	{
		reverse_rotate(stack_1, "\0");
		reverse_rotate(stack_2, "\0");
	}
	else if (!ft_strncmp(msg, "rr", 2))
	{
		rotate(stack_1, "\0");
		rotate(stack_2, "\0");
	}
	else
	{
		printf("error at do_twice\n");
		return ;
	}
	printf("%s", msg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortExtra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:30:58 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/01 15:19:29 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a, stack_b);
	if (stack_a->size == 3)
		sort_three(stack_a, stack_b);
	if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}

void	sort_two(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, "sa");
}
//returnlar 1 satir kazandiriyor
/*void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array[1] == 0)
	{
		if (peek(stack_a) == 1)
			swap(stack_a, "sa");
		else
			rotate(stack_a, "ra");
		return;
	}
	else if (stack_a->array[0] == 0)
	{
		if (peek(stack_a) != 1)
			swap(stack_a, "sa");
		reverse_rotate(stack_a, "rra");
		return;
	}
	reverse_rotate(stack_a, "rra");
	swap(stack_a, "sa");
}*/

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	if (!check_sorted_stack(stack_a))
		return ;
	if (peek(stack_a) == 0)
	{
		reverse_rotate(stack_a, "rra");
		swap(stack_a, "sa");
	}
	else if (peek(stack_a) == 2)
	{
		rotate(stack_a, "ra");
		if (peek(stack_a) == 1)
			swap(stack_a, "sa");
	}
	else
	{
		if (stack_a->array[0] == 2)
			swap(stack_a, "sa");
		else
			reverse_rotate(stack_a, "rra");
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array[0] == 0)
		reverse_rotate(stack_a, "rra");
	while (peek(stack_a) != 0)
	{
		rotate(stack_a, "ra");
	}
	push_other(stack_a, stack_b, "pb");
	transform(stack_a, 3);
	sort_three(stack_a, stack_b);
	push_other(stack_b, stack_a, "pa");
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array[0] == 0)
		reverse_rotate(stack_a, "rra");
	if (stack_a->array[1] == 0)
	{
		reverse_rotate(stack_a, "rra");
		reverse_rotate(stack_a, "rra");
	}
	while (peek(stack_a) != 0)
	{
		rotate(stack_a, "ra");
	}
	push_other(stack_a, stack_b, "pb");
	transform(stack_a, 4);
	sort_four(stack_a, stack_b);
	push_other(stack_b, stack_a, "pa");
}

void	transform(t_stack *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_a->array[i] -= 1;
		i++;
	}
}



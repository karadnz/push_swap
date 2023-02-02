/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortBinary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:51:20 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/02 17:54:41 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_main(t_stack *stack_a, t_stack *stack_b)
{
	int	iter_count;
	int	i;

	if (stack_a->size < 6)
	{
		small_sort(stack_a, stack_b);
		return ;
	}
	i = 0;
	iter_count = leftmost(get_max(stack_a));
	while (i < iter_count)
	{
		if (!check_sorted_stack(stack_a))
		{
			break ;
		}
		bit_sort(stack_a, stack_b, i);
		i++;
	}
}

void	bit_sort(t_stack *stack_a, t_stack *stack_b, int bit_place)
{
	int	a_size;
	int	b_size;
	int	i;

	i = 0;
	a_size = stack_a->top + 1;
	while (i < a_size)
	{
		if (((peek(stack_a) >> (bit_place)) & 1))
			rotate(stack_a, "ra");
		else
		{
			push_other(stack_a, stack_b, "pb");
		}
		i++;
	}
	b_size = stack_b->top + 1;
	i = 0;
	while (i < b_size)
	{
		push_other(stack_b, stack_a, "pa");
		i++;
	}
}

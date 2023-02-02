/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortBinaryUtils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:29:47 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/02 17:54:29 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit_at_place(int num, int bit_place)
{
	return (num << bit_place);
}

int	leftmost(unsigned int n)
{
	int	pos;

	pos = 31;
	while (!(n >> pos))
	{
		pos--;
	}
	return (pos + 1);
}

int	get_max(t_stack *stack)
{
	int	rt;
	int	*tmp;

	tmp = get_sorted(stack->array, stack->size);
	rt = tmp[stack->top];
	free(tmp);
	return (rt);
}

int	check_sorted_stack(t_stack *stack)
{
	int	*tmp;
	int	i;
	int	rt;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * (stack->size));
	while (i < stack->size)
	{
		tmp[i] = stack->array[i];
		i++;
	}
	bubble_stack_sort(tmp, stack->size);
	rt = compare_arrays(tmp, stack->array, stack->size);
	free(tmp);
	return (rt);
}

void	bubble_stack_sort(int *arr1, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (i + j < size)
		{
			if (arr1[i] < arr1[i + j])
			{
				tmp = arr1[i];
				arr1[i] = arr1[i + j];
				arr1[i + j] = tmp;
			}
			j++;
		}
		i++;
	}
}

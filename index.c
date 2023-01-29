/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:31:30 by mkaraden          #+#    #+#             */
/*   Updated: 2023/01/29 08:37:43 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack *a)
{
	int	*tmp;

	tmp = get_sorted(a->array, a->size);
	for (int i = 0; i < a->size; i++)
	{
		for (int j = 0; j < a->size; j++)
		{
			if (a->array[i] == tmp[j])
			{
				a->array[i] = j;
				break ;
			}
		}
	}
}

int	*get_sorted(int *src, int size)
{
	int	i;
	int	*rt;

	i = 0;
	rt = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		rt[i] = src[i];
		i++;
	}
	bubble_sort(rt, size);
	return (rt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:31:30 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/01 11:11:15 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack *a)
{
	int	*tmp;
	int	i;
	int	j;

	i = 0;
	tmp = get_sorted(a->array, a->size);
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->array[i] == tmp[j])
			{
				a->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(tmp);
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

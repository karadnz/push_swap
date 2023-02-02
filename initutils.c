/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:38:06 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/02 18:02:11 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_arrays(int *arr1, int *arr2, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr1[i] != arr2[i])
			return (1);
		i++;
	}
	return (0);
}

void	bubble_sort(int *arr1, int size)
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
			if (arr1[i] > arr1[i + j])
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

int	*fill_duplicate(int ac, char **av)
{
	int	*rt;
	int	i;

	rt = (int *)malloc(sizeof(int) * (ac - 1));
	i = 1;
	while (i < ac)
	{
		rt[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (rt);
}

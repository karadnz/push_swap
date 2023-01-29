/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:32:47 by mkaraden          #+#    #+#             */
/*   Updated: 2023/01/29 08:36:39 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	if (!check_num(ac, av))
	{
		printf("Error: invalid input(number)\n");
		exit(1);
	}
	if (!check_duplicate(ac, av))
	{
		printf("Error: invalid input(duplicate)\n");
		exit(1);
	}
	if (!check_sorted(ac, av))
	{
		printf("Error: invalid input(sorted)\n");
		exit(1);
	}
	fillstack(ac, av, stack_a, stack_b);
}

void	fillstack(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	init_stack(stack_a, ac - 1);
	init_stack(stack_b, ac - 1);
	ac--;
	while (ac > 0)
	{
		push(stack_a, ft_atoi(av[ac]));
		ac--;
	}
}

int	check_num(int ac, char **av)
{
	int	i;

	while (ac > 1)
	{
		i = 0;
		if (av[ac - 1][i] == '-')
			i++;
		while (av[ac - 1][i] != '\0')
		{
			if (!ft_isdigit(av[ac - 1][i]))
				return (0);
			i++;
		}
		ac--;
	}
	return (1);
}

int	check_duplicate(int ac, char **av)
{
	int	*arr;
	int	i;
	int	j;

	arr = (int *)malloc(sizeof(int) * (ac - 1));
	i = 1;
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i]);
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sorted(int ac, char **av)
{
	int	*arr1;
	int	*arr2;
	int	i;

	arr1 = (int *)malloc(sizeof(int) * (ac - 1));
	arr2 = (int *)malloc(sizeof(int) * (ac - 1));
	i = 0;
	while (++i < ac)
	{
		arr1[i - 1] = ft_atoi(av[i]);
		arr2[i - 1] = ft_atoi(av[i]);
	}
	bubble_sort(arr1, ac - 1);
	return (compare_arrays(arr1, arr2, ac - 1));
}

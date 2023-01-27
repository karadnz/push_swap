#include "push_swap.h"

void init (int ac, char **av, t_stack *stack_a, t_stack *stack_b) //ac gelen sayilarin 1 fazlasi
{
	//check() check sorted

	
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

void fillstack(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	init_stack(stack_a, ac - 1);
	init_stack(stack_b, ac - 1);
	ac--; //ilk index harici sondan eklemek icin
	while (ac > 0)
	{
		//stack_a->array[i - 1] = ft_atoi(av[i]);
		push(stack_a, ft_atoi(av[ac]));
		ac--;
	}

}

int check_num(int ac, char **av)
{
	int i;

	while (ac > 1)
	{
		i = 0;
		while(av[ac - 1][i] != '\0') //null
		{
			if (!ft_isdigit(av[ac - 1][i]))
				return (0);
			i++;
		}
		ac--;
	}
	return (1);
}
int check_duplicate(int ac, char **av)
{
	int *arr;
	int	i;
	int j;

	arr = (int *)malloc(sizeof(int) * (ac - 1));
	i = 1;
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i]);
		printf("iter: %d, arr: %d, av: %s ac:%d\n",i, arr[i - 1], av[i], ac);
		i++;
	}
	i = 0;
	while (i < ac - 1) //**
	{
		j = i + 1;
		while (j < ac - 1) //** address sanitizer
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_sorted(int ac, char **av)
{
	int *arr1;
	int *arr2;
	int	i;
	int j;
	int	tmp;

	arr1 = (int *)malloc(sizeof(int) * (ac - 1));
	arr2 = (int *)malloc(sizeof(int) * (ac - 1));
	i = 0;
	while (++i < ac)
	{
		arr1[i - 1] = ft_atoi(av[i]);
		arr2[i - 1] = ft_atoi(av[i]);
		printf("iter: %d, arr: %d, av: %s\n",i, arr1[i - 1], av[i]);
	}

	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (i + j < ac -1)
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

	/*i = 0;

	while (i < ac - 1)
	{
		printf("%d\n", arr1[i]);
		i++;
	}*/
	i = 0;
	while (i < ac - 1)
	{
		if (arr1[i] != arr2[i])
			return (1);
		i++;
	}

	return (0);

}


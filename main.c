/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:40:21 by mkaraden          #+#    #+#             */
/*   Updated: 2023/01/28 23:24:42 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);

	t_stack *a = (t_stack *)malloc(sizeof(t_stack));
	t_stack *b = (t_stack *)malloc(sizeof(t_stack));

	init(ac, av, a, b);

	//printstack(a,"a");
	get_index(a);
	//printstack(a,"a");

	radix_main(a, b);
	//printstack(a,"a");
	//printstack(b,"b");

	

	return(0);
}


int main7(int ac, char **av)
{
	if (ac < 2)
		return (0);

	t_stack *a = (t_stack *)malloc(sizeof(t_stack));
	t_stack *b = (t_stack *)malloc(sizeof(t_stack));

	init_stack(a,100);

	init(ac, av, a, b);

	printstack(a, "a");
	printf("\n");

	swap(a, "sa");
	printf("\n");
	printstack(a, "a");

	rotate(a, "ra");
	printf("\n");
	printstack(a, "a");

	reverse_rotate(a, "rra");
	printf("\n");
	printstack(a, "a");

	push_other(a, b, "pb");
	printf("\n");
	printstack(a, "a");
	printstack(b, "b");

	push_other(a, b, "pb");
	printf("\n");
	printstack(a, "a");
	printstack(b, "b");


	do_twice(b, a, "rr");
	printf("\n");
	printstack(a, "a");
	printstack(b, "b");



	

	//freeStacks(a, b);
	return (0);

}

int main3(int ac, char **av)
{
	for (int i = 0; i < ac; i++)
	{
		printf("%s\n", av[i]);
	}

	return (0);
}

int main2(int ac, char **av)
{
	if (ac < 2)
		return (0);

	t_stack *a = (t_stack *)malloc(sizeof(t_stack));
	t_stack *b = (t_stack *)malloc(sizeof(t_stack));

	init_stack(a,100);


	push (a,1);
	printstack(a, "a");
	printf("----------------\n");

	push (a,2);
	printstack(a, "a");
	printf("----------------\n");

	push (a,3);
	printstack(a, "a");
	printf("----------------\n");

	pop (a);
	printstack(a, "a");
	printf("----------------\n");

	push (a,4);
	printstack(a, "a");
	printf("----------------\n");

	push (a,5);
	printstack(a, "a");
	printf("----------------\n");

	//freeStacks(a, b);
	return (0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackExtra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:43:45 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/02 18:13:33 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	free(stack_a);
	free(stack_b);
}

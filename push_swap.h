/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:43:35 by mkaraden          #+#    #+#             */
/*   Updated: 2023/01/27 14:44:28 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h> //
# include <unistd.h>
# include <limits.h>

typedef	struct	s_stack
{
	int*	array;
	int		size;
	int		top; //index
}				t_stack;

//stack
void resize(t_stack *stack);
void init_stack (t_stack *stack, int size);
void push (t_stack *stack, int num);
void pop (t_stack *stack);
int peek(t_stack *stack);
void printstack(t_stack *stack, char *msg);
void freeStacks(t_stack *stack_a, t_stack *stack_b);

//stack operations
void swap(t_stack *stack, char *msg); //sa sb
void rotate(t_stack *stack, char *msg); //ra rb
void reverse_rotate(t_stack *stack, char *msg); //rra rrb
void push_other(t_stack *stack_1, t_stack *stack_2, char *msg); //pa pb
void do_twice(t_stack *stack_1, t_stack *stack_2, char *msg);


//libftutils
int	ft_atoi(const char *str);


//init
void init (int ac, char **av, t_stack *stack_a, t_stack *stack_b);
void fillstack(int ac, char **av, t_stack *stack_a, t_stack *stack_b);




#endif
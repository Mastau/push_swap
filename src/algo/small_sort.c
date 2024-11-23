/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:54:45 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/23 16:32:22 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[0] < stack->stack_a[2])
		swap(stack, 'a');
	else if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2])
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] < stack->stack_a[2])
		rrotate(stack, 'a');
	else if (stack->stack_a[0] < stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2]
		&& stack->stack_a[0] < stack->stack_a[2])
	{
		swap(stack, 'a');
		rrotate(stack, 'a');
	}
	else if (stack->stack_a[0] < stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2])
		rotate(stack, 'a');
}

/* void	sort_three(t_stack *stack) */
/* { */
/* 	int	a; */
/* 	int	b; */
/* 	int	c; */
/*  */
/* 	a = stack->stack_a[stack->size_a - 1]; */
/* 	b = stack->stack_a[stack->size_a - 2]; */
/* 	c = stack->stack_a[stack->size_a - 3]; */
/* 	if (a > b && b > c) */
/* 	{ */
/* 		swap(stack, 'a'); */
/* 		rrotate(stack, 'a'); */
/* 		//rotate(stack, 'a'); */
/* 		//rotate(stack, 'a'); */
/* 	} */
/* 	else if (a > c && c > b) */
/* 		rotate(stack, 'a'); */
/* 	else if (b > a && a > c) */
/* 			rrotate(stack, 'a'); */
/* 	else if (b > c && c > a) */
/* 			swap(stack, 'a'); */
/* 	else if (c > a && a > b) */
/* 	{ */
/* 		rrotate(stack, 'a'); */
/* 		swap(stack, 'a'); */
/* 	} */
/* } */

static	void	sort_two(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		rotate(stack, 'a');
	return ;
}

void	small_sort_stack(t_stack *stack)
{
	if (stack->size_a == 2)
		sort_two(stack);
	else if (stack->size_a == 3)
		sort_three(stack);
	else
		return ;
}

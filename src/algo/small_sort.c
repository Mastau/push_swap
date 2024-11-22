/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:54:45 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/22 17:50:15 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] < stack->stack_a[2]
		&& stack->stack_a[0] < stack->stack_a[2])
		swap(stack, 'a');
	else if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2])
	{
		swap(stack, 'a');
		rrotate(stack, 'a');
	}
	else if (stack->stack_a[0] > stack->stack_a[1]
		&& stack->stack_a[1] < stack->stack_a[2])
		rotate(stack, 'a');
	else if (stack->stack_a[0] < stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2]
		&& stack->stack_a[0] < stack->stack_a[2])
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (stack->stack_a[0] < stack->stack_a[1]
		&& stack->stack_a[1] > stack->stack_a[2])
		rrotate(stack, 'a');
}

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

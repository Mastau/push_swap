/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:24:34 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/26 13:33:49 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->value == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

int	ft_get_target(t_stack *a, int stack_b_rank, int closest_rank,
		int target_pos)
{
	t_node	*crt;

	crt = a->top;
	while (crt)
	{
		if (crt->rank > stack_b_rank && crt->rank < closest_rank)
		{
			closest_rank = crt->rank;
			target_pos = crt->index;
		}
		crt = crt->next;
	}
	if (closest_rank != INT_MAX)
		return (target_pos);
	crt = a->top;
	while (crt)
	{
		if (crt->rank < closest_rank)
		{
			closest_rank = crt->rank;
			target_pos = crt->index;
		}
		crt = crt->next;
	}
	return (target_pos);
}

void	ft_set_pos(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = -1;
	current = stack->top;
	while (current)
	{
		current->index = ++i;
		current = current->next;
	}
}

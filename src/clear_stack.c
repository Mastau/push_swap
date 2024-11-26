/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:03:33 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/26 14:03:41 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clear_all_stack(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*next;

	if (!a || !b)
		return (0);
	current = a->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(a);
	current = b->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(b);
	return (0);
}

void	clear_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

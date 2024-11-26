/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:13:15 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/26 13:24:10 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*ft_nodedup(t_node stack)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = stack.value;
	node->index = stack.index;
	node->target_pos = stack.target_pos;
	node->rank = stack.rank;
	node->cost_a = stack.cost_a;
	node->cost_b = stack.cost_b;
	node->next = NULL;
	return (node);
}

t_node	*ft_nodenew(int value)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	return (node);
}

void	push(t_stack *stack, t_node *node)
{
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

void	pop(t_stack *stack)
{
	t_node	*tmp;

	tmp = NULL;
	if (stack->size == 0)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	stack->size--;
	return ;
}

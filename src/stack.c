/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:54:31 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/25 18:10:32 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(void) 
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

t_node	*ft_nodedup(t_node stack)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
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

t_node *ft_nodenew(int	value)
{
	t_node *node;
	 
	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->target_pos = -1;
	node->cost_a= -1;
	node->cost_b = -1;
	return (node);
}

void push(t_stack *stack, t_node *node) 
{
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

void	pop(t_stack *stack)
{
	t_node *tmp;

	tmp = NULL;
    if (stack->size == 0)
        return ;
    tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
    stack->size--;
    return ;
}

int top(t_stack *stack)
{
    if (stack->size == 0)
        return (-1);
    return (stack->top->value);
}

void swap(t_stack *stack, char name)
{
	t_node *first;
	t_node *second;

	first = NULL;
	second = NULL;
    if (stack->size < 2)
        return ;
    first = stack->top;
    second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
	if (name == 'a')
		ft_dprintf(1, "%s\n", "sa");
	else
		ft_dprintf(1, "%s\n", "sb");
}

void push_to(t_stack *src, t_stack *dest, char name)
{
    if (src->size == 0)
        return ;
    push(dest, ft_nodedup(*(src->top)));
	pop(src);
	if (name == 'a')
		ft_dprintf(1, "%s\n", "pa");
	else
		ft_dprintf(1, "%s\n", "pb");

}

void rotate(t_stack *stack, char name)
{
	t_node *first;
	t_node *tmp;

	first = NULL;
	tmp = NULL;
    if (stack->size < 2)
        return ;
    first = stack->top;
    tmp = stack->top;

    while (tmp->next)
        tmp = tmp->next;
    stack->top = first->next;
    tmp->next = first;
    first->next = NULL;
	if (name == 'a')
		ft_dprintf(1, "%s\n", "ra");
	else if (name == 'b')
		ft_dprintf(1, "%s\n", "rb");
}

void rrotate(t_stack *stack, char name) {
	t_node *prev;
	t_node *current;

    prev = NULL;
	current = NULL;
    if (stack->size < 2)
        return ;
    current = stack->top;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    current->next = stack->top;
    stack->top = current;
    prev->next = NULL;
	if (name == 'a')
		ft_dprintf(1, "%s\n", "rra");
	else if (name == 'b')
		ft_dprintf(1, "%s\n", "rrb");
}

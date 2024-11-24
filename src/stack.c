/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:54:31 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/24 14:25:47 by thomarna         ###   ########.fr       */
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

void push(t_stack *stack, int value) 
{
    t_node *node;

	node = malloc(sizeof(t_list));
    if (!node)
        return;
    node->value = value;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int pop(t_stack *stack)
{
	t_node *tmp;
	int	value;

	tmp = NULL;
	value = 0;
    if (stack->size == 0)
        return (-1);
    tmp = stack->top;
	value = tmp->value;
    stack->top = stack->top->next;
    free(tmp);
    stack->size--;
    return (value);
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
	int	value;

	value = 0;
    if (src->size == 0)
        return ;
    value = pop(src);
    push(dest, value);
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
	else
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
	else
		ft_dprintf(1, "%s\n", "rrb");
}

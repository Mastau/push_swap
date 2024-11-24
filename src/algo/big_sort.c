/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:43:48 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/24 14:44:34 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack *stack)
{
    t_node *current;
	int	min;

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

int find_position(t_stack *stack, int value)
{
    t_node *current;
	int pos;

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


void turk_sort(t_stack *a, t_stack *b)
{
	int min_value; 
	int min_pos; 

    while (a->size > 0)
    {
		min_value = find_min(a);
		min_pos = find_position(a, min_value);
        if (min_pos <= a->size / 2)
        {
            while (top(a) != min_value)
                rotate(a, 'a');
        }
        else
        {
            while (top(a) != min_value)
                rrotate(a, 'a');
        }
        push_to(a, b, 'b');
    }
    while (b->size > 0)
        push_to(b, a, 'a');
}




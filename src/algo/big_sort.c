/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:43:48 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/25 01:02:32 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move_min(t_stack *stack)
{
	int value;

	value = find_min(stack);
	while (stack->top->value != value)
		rotate(stack, 'a');
}

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

void	push_to_b(t_stack *a, t_stack *b)
{
	int	nb_push;
	int	i;
	int	size;

	i = -1;
	size = a->size;
	nb_push = 0;
	while (nb_push < (size / 2) && ++i < size)
	{
		if (a->top->rank < (size / 2))
		{
			push_to(a, b, 'b');
			nb_push++;
		}
		else
			rotate(a, 'a');
	}
	while (a->size > 3)
		push_to(a, b, 'b');
	sort_three(a);
}

void turk_sort(t_stack *a, t_stack *b)
{

    while (b->size > 0)
		push_to(b, a, 'a');
}




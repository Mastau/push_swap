/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:34 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/24 14:48:26 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void print_stack(t_stack *stack)
{
    t_node *current;

	current = stack->top;
    while (current) {
        ft_printf("%d ", current->value);
        current = current->next;
    }
    ft_printf("\n");
}




int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (ac < 2)
	{
		ft_dprintf(2, "%s\n", "Error");
		return (0);
	}
	a = init_stack();
	b = init_stack();
	a = parsing(a, av);
	sort_stack(a, b);	
	print_stack(a);
	print_stack(b);
	return (0);
}


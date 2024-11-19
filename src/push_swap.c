/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:34 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/19 16:46:51 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "parsing.h"

void	free_str(void *val)
{
	clear_str(val);
}


int	main(int ac, char **av)
{
	t_list *stack_a;

	if (ac < 2)
	{
		ft_dprintf(2, "%s\n", "Error");
		return (0);
	}
	stack_a = parsing(av);
	while (stack_a)
	{
		ft_printf("%s\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}

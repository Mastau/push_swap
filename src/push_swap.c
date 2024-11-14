/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:34 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/14 16:27:11 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	t_list *stack_a;

	/* if (ac < 2) */
	/* 	return (0); */
	stack_a = parsing(ac, av);
	ft_printf("%d", stack_a->content);
	return (0);
}

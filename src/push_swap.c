/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:34 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/13 15:46:13 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list stack_a;

	if (ac < 2)
		return (0);
	stack_a = parsing(av, ac);
	if (stack_a == NULL)
		return (0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:45:28 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/13 15:56:36 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	verif_arg(char **av)
{
	char **split;
	t_list head;
	int	i;

	head = NULL;
	split = ft_split(ft_strjoin(av, ' '), ' ');
	while (split[i])
	{
		lst_addback(head, lst_new(split[i]));
		i++;
	}
	return (head);
}

t_list	parsing(char **av)
{
	t_list node;

	node = verif_arg(av);
	return (node);
}

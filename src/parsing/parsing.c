/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:45:28 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/14 14:12:51 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	verif_arg(char **av)
{
	char **split;
	t_list head;
	int	i;

	head = NULL;
	split = ft_split(ft_strjoin(*av, ' '), ' ');
	while (split[i])
	{
		ft_lst_addback(head, ft_lst_new(split[i]));
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

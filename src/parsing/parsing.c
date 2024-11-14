/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:45:28 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/14 16:37:45 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

t_list	*parsing(int ac, char **av)
{
	t_list *node;
	char **split;
	int	size;
	char *tmp;
	
	node = NULL;
	if (ac == 2)
		split = ft_split(av[1], ' ');
	else
	{
		size = ft_strlentab(ac - 1, av + 1);
		tmp = ft_strjoinsep(size, av + 1, " ");
		split = ft_split(tmp, ' ');
	}
	return (node);
}

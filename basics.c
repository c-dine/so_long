/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:28:22 by cdine             #+#    #+#             */
/*   Updated: 2022/01/25 23:26:36 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_delete_n(char **map)
{
	int	i;
	int	j;
	int	last_char;

	last_char = ft_strlen(map[0]);
	i = 0;
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	ft_lstadd_back(t_sprite_ref **alst, t_sprite_ref *new)
{
	t_sprite_ref	*last;

	if (*alst)
	{	
		last = ft_lstlast(*alst);
		last->next = new;
	}
	else
	{
		*alst = new;
	}
}

t_sprite_ref	*ft_lstlast(t_sprite_ref *lst)
{
	t_sprite_ref	*end;
	t_sprite_ref	*result;

	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		result = lst;
	else
	{
		end = lst->next;
		while (end != NULL)
		{
			result = end;
			end = end->next;
		}
	}
	return (result);
}

t_sprite_ref	*ft_lstnew(void *content)
{
	t_sprite_ref	*chain;

	chain = malloc(sizeof(t_sprite_ref));
	if (chain == NULL)
		return (NULL);
	chain->next = NULL;
	chain->ref = content;
	return (chain);
}

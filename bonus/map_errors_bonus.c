/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:10:38 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 15:16:07 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_checkextension(char *map)
{
	int	i;

	if (ft_strlen(map) < 5)
		return (0);
	i = ft_strlen(map) - 4;
	if (map[i] == '.' && map[i + 1] == 'b' && map[i + 2] == 'e'
		&& map[i + 3] == 'r' && map[i - 1] != '/')
		return (1);
	else
		return (0);
}

int	ft_checkrectangle(char **map)
{
	int	i;
	int	line_length;

	if (ft_map_lines(map) > 0)
	{
		line_length = ft_strlen(map[0]);
		i = 0;
		while (map[i][0])
		{
			if (ft_strlen(map[i]) != line_length)
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_checkwalls(char **map)
{
	int	i;
	int	lines;

	lines = ft_map_lines(map);
	if (lines < 3)
		return (0);
	i = 0;
	while (map[0][i] && map[lines - 1][i])
	{
		if (map[0][i] != '1' || map[lines - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i][0])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_ecp(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_checkelements(char **map)
{
	if (ft_check_ecp(map, 'E') == 0)
		return (3);
	else if (ft_check_ecp(map, 'C') == 0)
		return (4);
	else if (ft_check_ecp(map, 'P') != 1)
		return (5);
	return (1);
}

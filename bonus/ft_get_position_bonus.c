/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:54:48 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 17:55:11 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_get_position_col(t_program *solong, char c)
{
	int		row;
	int		col;
	char	p;

	row = 0;
	while ((*solong).map[row][0])
	{
		col = 0;
		while ((*solong).map[row][col])
		{
			p = (*solong).map[row][col];
			if (c == 'Z' && (p == 'Z' || p == 'Y'))
				return (col);
			if (c == 'P' && (p == 'P' || p == 'R' || p == 'U'
					|| p == 'L' || p == 'D'))
				return (col);
			col++;
		}
		row++;
	}
	return (-1);
}

int	ft_get_position_row(t_program *solong, char c)
{
	int		row;
	int		col;
	char	p;

	row = 0;
	while ((*solong).map[row][0])
	{
		col = 0;
		while ((*solong).map[row][col])
		{
			p = (*solong).map[row][col];
			if (c == 'Z' && (p == 'Z' || p == 'Y'))
				return (row);
			if (c == 'P' && (p == 'P' || p == 'R' || p == 'U'
					|| p == 'L' || p == 'D'))
				return (row);
			col++;
		}
		row++;
	}
	return (-1);
}

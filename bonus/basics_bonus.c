/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:28:22 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 10:58:07 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int     ft_get_position_col(t_program *solong, char c)
{
    int row;
    int col;

    row = 0;
    while ((*solong).map[row][0])
    {
        col = 0;
        while ((*solong).map[row][col])
        {
            if (c == 'Z' && ((*solong).map[row][col] == 'Z' || (*solong).map[row][col] == 'Y'))
                return (col);
			if (c == 'P' && ((*solong).map[row][col] == 'P' || (*solong).map[row][col] == 'R'
				|| (*solong).map[row][col] == 'U' || (*solong).map[row][col] == 'L'
				|| (*solong).map[row][col] == 'D'))
				return (col);
            col++;
        }
        row++;
    }
    return (-1);
}

int     ft_get_position_row(t_program *solong, char c)
{
    int row;
    int col;

    row = 0;
    while ((*solong).map[row][0])
    {
        col = 0;
        while ((*solong).map[row][col])
        {
            if (c == 'Z' && ((*solong).map[row][col] == 'Z' || (*solong).map[row][col] == 'Y'))
                return (row);
			if (c == 'P' && ((*solong).map[row][col] == 'P' || (*solong).map[row][col] == 'R'
				|| (*solong).map[row][col] == 'U' || (*solong).map[row][col] == 'L'
				|| (*solong).map[row][col] == 'D'))
				return (row);
            col++;
        }
        row++;
    }
    return (-1);
}

// char	*ft_get_string(t_program *solong, int msg)
// {

// 	if (msg == 0)
// 	{

// 	}
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:28:22 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 15:07:34 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_itoa(int nb, t_program *solong)
{
	char	*str;
	int		i;
	int		nb_size;
	int		nbr;

	nbr = nb;
	nb_size = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		nb_size++;
	}
	str = malloc(sizeof(char) * (nb_size + 1));
	if (str == NULL)
		ft_close(solong);
	str[nb_size] = '\0';
	i = nb_size - 1;
	while (i >= 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (str);
}

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

void	ft_delete_n(char **map)
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

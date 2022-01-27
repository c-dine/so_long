/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:28:22 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 18:38:21 by cdine            ###   ########.fr       */
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

int	ft_isline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_map_lines(char **map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map[i][0])
	{
		count++;
		i++;
	}
	return (count);
}

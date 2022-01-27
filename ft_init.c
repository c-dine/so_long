/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:44:54 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 17:22:53 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_redraw_map(t_program *solong)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while ((*solong).map[row][0])
	{
		col = 0;
		while ((*solong).map[row][col])
		{
			c = (*solong).map[row][col];
			if (c == '0' || c == 'P' || c == 'D' || c == 'U'
				|| c == 'R' || c == 'L')
				mlx_put_image_to_window((*solong).mlx, (*solong).win.ref,
					(*solong).spriteref[ft_get_index_ref(c)], col * 32,
					row * 32);
			col++;
		}
		row++;
	}
}

int	ft_get_index_ref(char c)
{
	if (c == '1')
		return (0);
	else if (c == '0')
		return (1);
	else if (c == 'C')
		return (2);
	else if (c == 'E')
		return (3);
	else if (c == 'P' || c == 'D')
		return (4);
	else if (c == 'U')
		return (5);
	else if (c == 'R')
		return (6);
	else if (c == 'L')
		return (7);
	return (-1);
}

void	ft_init_map(t_program *solong)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while ((*solong).map[row][0])
	{
		col = 0;
		while ((*solong).map[row][col])
		{
			c = (*solong).map[row][col];
			if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
				|| c == 'D' || c == 'U' || c == 'R' || c == 'L')
				mlx_put_image_to_window((*solong).mlx, (*solong).win.ref,
					(*solong).spriteref[ft_get_index_ref(c)], col * 32,
					row * 32);
			col++;
		}
		row++;
	}
}

void	ft_init_sprite(t_program *solong)
{
	t_image	sprite;

	(*solong).spriteref = malloc(sizeof(void *) * ft_strlen((*solong).map[0])
			* ft_map_lines((*solong).map));
	if ((*solong).spriteref == NULL)
		ft_close(solong);
	sprite = ft_new_sprite(solong, "./img/wall.xpm");
	(*solong).spriteref[0] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/long_grass.xpm");
	(*solong).spriteref[1] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/fish.xpm");
	(*solong).spriteref[2] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/door.xpm");
	(*solong).spriteref[3] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/front.xpm");
	(*solong).spriteref[4] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/back.xpm");
	(*solong).spriteref[5] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/right.xpm");
	(*solong).spriteref[6] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/left.xpm");
	(*solong).spriteref[7] = sprite.ref;
}

void	ft_init_var(t_program *solong)
{
	int	row;
	int	col;

	(*solong).nb_sprite = 0;
	(*solong).fish_caught = 0;
	(*solong).nb_fish_total = 0;
	(*solong).win_lose = 0;
	ft_init_sprite(solong);
	row = 0;
	while ((*solong).map[row][0])
	{
		col = 0;
		while ((*solong).map[row][col])
		{
			if ((*solong).map[row][col] == 'C')
				(*solong).nb_fish_total += 1;
			col++;
		}
		row++;
	}
}

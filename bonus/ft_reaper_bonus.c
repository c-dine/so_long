/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reaper_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:43:03 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 16:45:28 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_reaper(t_program *solong)
{
	int	row;
	int	col;
	int	placed;

	placed = 0;
	row = ft_map_lines((*solong).map) - 1;
	while (row > 0)
	{
		col = ft_strlen((*solong).map[0]) - 1;
		while (col > 0)
		{
			if (placed == 1)
				break ;
			if ((*solong).map[row][col] == '0')
			{
				(*solong).map[row][col] = 'Z';
				placed = 1;
			}
			col--;
		}
		if (placed == 1)
			break ;
		row--;
	}
}

void	ft_init_sprite_reaper(t_program *solong)
{
	t_image	sprite;

	sprite = ft_new_sprite(solong, "./img/tomb.xpm");
	(*solong).spriteref[8] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/death1.xpm");
	(*solong).spriteref[9] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/death2.xpm");
	(*solong).spriteref[10] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/death3.xpm");
	(*solong).spriteref[11] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/death4.xpm");
	(*solong).spriteref[12] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/death5.xpm");
	(*solong).spriteref[13] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/death6.xpm");
	(*solong).spriteref[14] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/death7.xpm");
	(*solong).spriteref[15] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/death_left.xpm");
	(*solong).spriteref[16] = sprite.ref;
}

int	ft_checkway_reaper(t_program *solong, char dir, int col, int row)
{
	if (dir == 'l')
	{
		if ((*solong).map[row][col - 1] == '1' || (*solong).map[row][col - 1]
			== 'E' || (*solong).map[row][col - 1] == 'C')
			return (0);
	}
	if (dir == 'r')
	{
		if ((*solong).map[row][col + 1] == '1' || (*solong).map[row][col + 1]
			== 'E' || (*solong).map[row][col + 1] == 'C')
			return (0);
	}
	if (dir == 'u')
	{
		if ((*solong).map[row - 1][col] == '1' || (*solong).map[row - 1][col]
			== 'E' || (*solong).map[row - 1][col] == 'C')
			return (0);
	}
	if (dir == 'd')
	{
		if ((*solong).map[row + 1][col] == '1' || (*solong).map[row + 1][col]
			== 'E' || (*solong).map[row + 1][col] == 'C')
			return (0);
	}
	return (1);
}

void	ft_move_reaper_dir(t_program *solong, char dir, int x, int y)
{
	(*solong).map[y][x] = '0';
	if (dir == 'l')
		(*solong).map[y][x - 1] = 'Y';
	else if (dir == 'r')
		(*solong).map[y][x + 1] = 'Z';
	else if (dir == 'u')
		(*solong).map[y - 1][x] = 'Z';
	else if (dir == 'd')
		(*solong).map[y + 1][x] = 'Y';
}

void	ft_move_reaper(t_program *solong, int row, int col)
{
	int		x;
	int		y;
	char	side;

	x = ft_get_position_col(solong, 'Z');
	y = ft_get_position_row(solong, 'Z');
	side = (*solong).map[y][x];
	if (ft_checkway_reaper(solong, 'l', x, y) == 1 && col < x)
		ft_move_reaper_dir(solong, 'l', x, y);
	else if (ft_checkway_reaper(solong, 'u', x, y) == 1 && row < y)
		ft_move_reaper_dir(solong, 'u', x, y);
	else if (ft_checkway_reaper(solong, 'd', x, y) == 1 && row > y)
		ft_move_reaper_dir(solong, 'd', x, y);
	else if (ft_checkway_reaper(solong, 'r', x, y) == 1 && col > x)
		ft_move_reaper_dir(solong, 'r', x, y);
	else if (ft_checkway_reaper(solong, 'l', x, y) == 1)
		ft_move_reaper_dir(solong, 'l', x, y);
	else if (ft_checkway_reaper(solong, 'd', x, y) == 1)
		ft_move_reaper_dir(solong, 'd', x, y);
	else if (ft_checkway_reaper(solong, 'r', x, y) == 1)
		ft_move_reaper_dir(solong, 'r', x, y);
	else if (ft_checkway_reaper(solong, 'u', x, y) == 1)
		ft_move_reaper_dir(solong, 'u', x, y);
	else
		ft_display_msg(solong, 3);
}

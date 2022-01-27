/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_destroy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:25:55 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 17:40:19 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_map(t_program *solong)
{
	int	i;

	i = 0;
	while (i < (*solong).nb_sprite)
	{
		mlx_destroy_image((*solong).mlx, (*solong).spriteref[i]);
		i++;
	}
	if ((*solong).nb_sprite < 17)
		printf("A file is missing.\n");
}

int	ft_close(t_program *solong)
{
	int	i;
	int	map_lines;

	map_lines = ft_map_lines((*solong).map);
	ft_destroy_map(solong);
	free((*solong).spriteref);
	i = 0;
	while (i <= map_lines)
		free((*solong).map[i++]);
	free((*solong).map);
	mlx_destroy_window((*solong).mlx, (*solong).win.ref);
	mlx_destroy_display((*solong).mlx);
	free((*solong).mlx);
	exit(0);
}

void	ft_death(t_program *solong, char side)
{
	int	i;
	int	j;

	if (side == 'Z')
		j = 9;
	else
		j = 9;
	i = 0;
	while (i < 7)
	{
		mlx_put_image_to_window((*solong).mlx, (*solong).win.ref,
			(*solong).spriteref[j], ft_get_position_col(solong, 'Z') * 32,
			ft_get_position_row(solong, 'Z') * 32);
		j++;
		i++;
	}
	mlx_loop((*solong).mlx);
}

void	ft_checkdeath(t_program *solong)
{
	int	x_r;
	int	y_r;
	int	x_p;
	int	y_p;

	x_r = ft_get_position_col(solong, 'Z');
	y_r = ft_get_position_row(solong, 'Z');
	x_p = ft_get_position_col(solong, 'P');
	y_p = ft_get_position_row(solong, 'P');
	if ((y_p == y_r && (x_p == x_r + 1 || x_p == x_r - 1))
		|| (x_p == x_r && (y_p == y_r - 1 || y_p == y_r + 1)))
	{
		ft_display_msg(solong, 1);
		mlx_put_image_to_window((*solong).mlx, (*solong).win.ref,
			(*solong).spriteref[8], x_p * 32, y_p * 32);
		ft_death(solong, (*solong).map[y_r][x_r]);
	}
}

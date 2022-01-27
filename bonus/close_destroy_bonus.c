/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_destroy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:25:55 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 23:12:26 by cdine            ###   ########.fr       */
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
	if ((*solong).nb_sprite < 23)
		printf("A file is missing. %d\n", (*solong).nb_sprite);
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

void	ft_death(t_program *solong)
{
	if (ft_get_position_col(solong, 'P') < ft_get_position_col(solong, 'Z')
		&& (*solong).loop_kill == 9)
		(*solong).loop_kill = 16;
	mlx_put_image_to_window((*solong).mlx, (*solong).win.ref,
		(*solong).spriteref[(*solong).loop_kill],
		ft_get_position_col(solong, 'Z') * 32,
		ft_get_position_row(solong, 'Z') * 32);
	usleep(90000);
	if ((*solong).loop_kill == 15 || (*solong).loop_kill == 22)
	{
		(*solong).win_lose = -2;
		mlx_put_image_to_window((*solong).mlx, (*solong).win.ref,
			(*solong).spriteref[8], ft_get_position_col(solong, 'P') * 32,
			ft_get_position_row(solong, 'P') * 32);
	}
	(*solong).loop_kill++;
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
		(*solong).win_lose = -1;
	}
}

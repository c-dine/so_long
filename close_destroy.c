/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:25:55 by cdine             #+#    #+#             */
/*   Updated: 2022/02/01 12:02:04 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_map(t_program *solong)
{
	int	i;

	i = 0;
	while (i < (*solong).nb_sprite)
	{
		mlx_destroy_image((*solong).mlx, (*solong).spriteref[i]);
		i++;
	}
}

void	ft_display_msg(t_program *solong)
{
	if ((*solong).nb_sprite < 8)
		printf("A file is missing.\n");
	else
	{
		if ((*solong).win_lose == 1)
			printf("\tYOU WON!\n");
		else
			printf("\t   YOU LOST!\n");
		printf("\t-- SCORE --\nMove count: %d\tFish caught: %d/%d\n",
			(*solong).move_count, (*solong).fish_caught,
			(*solong).nb_fish_total);
	}
}

int	ft_close(t_program *solong)
{
	int	i;
	int	map_lines;

	map_lines = ft_map_lines((*solong).map);
	ft_display_msg(solong);
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

void	ft_destroy_error(t_program *solong)
{
	int	i;
	int	map_lines;

	map_lines = ft_map_lines((*solong).map);
	i = 0;
	while (i <= map_lines)
		free((*solong).map[i++]);
	free((*solong).map);
}

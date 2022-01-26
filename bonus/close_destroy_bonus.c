/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:25:55 by cdine             #+#    #+#             */
/*   Updated: 2022/01/26 16:44:53 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_destroy_map(t_program *solong)
{
    int	i;

    i = 0;
    while (i < 8)
    {
        mlx_destroy_image((*solong).mlx, (*solong).spriteref[i]);
		i++;
    }
}

int ft_close (t_program *solong)
{
	int	i;
	int	map_lines;

	map_lines = ft_map_lines((*solong).map);
	if ((*solong).win_lose == 1)
		printf("\tYOU WON!\n");
	else
		printf("\t   YOU LOST!\n");
    printf("\t-- SCORE --\nMove count: %d\tFish caught: %d/%d\n",
		(*solong).move_count, (*solong).fish_caught, (*solong).nb_fish_total);
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
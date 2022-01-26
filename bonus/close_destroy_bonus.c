/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_destroy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:25:55 by cdine             #+#    #+#             */
/*   Updated: 2022/01/26 20:35:10 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    ft_destroy_map(t_program *solong)
{
    int	i;

    i = 0;
    while (i < 10)
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
	else if ((*solong).win_lose == -1)
		printf("\tYOU GOT KILLED BY THE REAPER!\n");
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

void ft_death(t_program *solong, char side, int x, int y)
{
    (void) side;
    (void) x;
    (void) y;
    (*solong).win_lose = -1;
    ft_close(solong);
}

void	ft_checkdeath(t_program *solong, int row, int col)
{
    if ((row == (*solong).reaper.y && (col == (*solong).reaper.x + 1 || col == (*solong).reaper.x - 1)) 
        || (col == (*solong).reaper.x && (row == (*solong).reaper.y - 1 || row == (*solong).reaper.y + 1)))
        ft_death(solong, (*solong).map[(*solong).reaper.y][(*solong).reaper.x], (*solong).reaper.x, (*solong).reaper.y);
}
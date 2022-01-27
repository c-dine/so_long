/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_destroy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:25:55 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 10:58:36 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    ft_destroy_map(t_program *solong)
{
    int	i;

    i = 0;
    while (i < 17)
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
		printf("YOU GOT KILLED BY THE REAPER!\n");
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

void ft_death(t_program *solong, char side)
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
        (*solong).spriteref[j], ft_get_position_col(solong, 'Z') * 32, ft_get_position_row(solong, 'Z') * 32);
		usleep(10000);
		j++;
		i++;
	}

    (*solong).win_lose = -1;
	mlx_loop((*solong).mlx);
	 // ft_close(solong);
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
		mlx_clear_window((*solong).mlx, (*solong).win.ref);
		mlx_string_put((*solong).mlx, (*solong).win.ref, 16, 
    	    ft_map_lines((*solong).map) * 32 + 20, 255255255, "You got killed by the reaper! Press esc to exit.  Move count: ");
		ft_init_map(solong);
		ft_redraw_map(solong);
        mlx_put_image_to_window((*solong).mlx, (*solong).win.ref,
            (*solong).spriteref[8], x_p * 32, y_p * 32);
        ft_death(solong, (*solong).map[y_r][x_r]);
	}
}
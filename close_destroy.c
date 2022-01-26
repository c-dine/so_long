/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:25:55 by cdine             #+#    #+#             */
/*   Updated: 2022/01/26 00:57:29 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void    ft_destroy_map(t_program *solong)
// {
//     t_program   tmp;
//     int         i;

//     i = 0;
//     while (i < ft_map_lines((*solong).map))
//     {
//         mlx_destroy_image((*solong).mlx, (*solong).sprites.ref);
//         (*solong).sprites.ref = (*solong).sprites.next.ref;
//     }
//     tmp = (*solong).sprites;
// 	while (tmp->next)
// 	{
// 		tmp = (*solong).sprites.next;
// 		free((*solong).sprites);
// 		(*solong).sprites = tmp;
// 	}
// 	free((*solong).sprites);
// }

int ft_close (t_program *solong)
{
	int	i;

	if ((*solong).win_lose == 1)
		printf("\tYOU WON!\n");
	else
		printf("\t   YOU LOST!\n");
    ////////////////////////////////////////////////////////////////////
    printf("\t-- SCORE --\nMove count: %d\tFish caught: %d/%d\n", (*solong).move_count, (*solong).fish_caught, (*solong).nb_fish_total);
    ////////////////////////////////////////////////
	// destroy image, window, display, free(mlx)
    // ft_destroy_map(solong); 
	i = 0;
	while (i <= ft_map_lines((*solong).map))
		free((*solong).map[i++]);
	free((*solong).map);

	exit(0);
}
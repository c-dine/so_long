/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:44:54 by cdine             #+#    #+#             */
/*   Updated: 2022/01/25 20:30:00 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_draw(t_program *solong, int row, int col, char *path)
{
    t_image sprite;

    sprite = ft_new_sprite((*solong).mlx, path);
    if (row == 0 && col == 0)
        (*solong).sprites = ft_lstnew(sprite.ref);
    else
        ft_lstadd_back(&(*solong).sprites, ft_lstnew(sprite.ref));
    mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, sprite.ref, col * 32, row * 32);
}

void    ft_init_map(t_program *solong)
{
    int row;
    int col;

    row = 0;
    while ((*solong).map[row][0])
    {
        col = 0;
        while ((*solong).map[row][col])
        {
            if ((*solong).map[row][col] == '1')
                ft_draw(&(*solong), row, col, "./img/wall.xpm");
            else if ((*solong).map[row][col] == '0')
                ft_draw(&(*solong), row, col, "./img/grass.xpm");
            else if ((*solong).map[row][col] == 'C')
                ft_draw(&(*solong), row, col, "./img/fish.xpm");
            else if ((*solong).map[row][col] == 'E')
                ft_draw(&(*solong), row, col, "./img/door.xpm");
            else if ((*solong).map[row][col] == 'P')
                ft_draw(&(*solong), row, col, "./img/front.xpm");
            col++;
        }
        row++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:44:54 by cdine             #+#    #+#             */
/*   Updated: 2022/01/26 12:19:40 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_redraw_map(t_program *solong)
{
    int row;
    int col;

    row = 0;
    while ((*solong).map[row][0])
    {
        col = 0;
        while ((*solong).map[row][col])
        {
           if ((*solong).map[row][col] == '0')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[1], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'P' || (*solong).map[row][col] == 'D')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[4], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'U')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[5], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'R')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[6], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'L')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[7], col * 32, row * 32);
            col++;
        }
        row++;
    }
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
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[0], col * 32, row * 32);
            else if ((*solong).map[row][col] == '0')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[1], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'C')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[2], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'E')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[3], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'P' || (*solong).map[row][col] == 'D')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[4], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'U')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[5], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'R')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[6], col * 32, row * 32);
            else if ((*solong).map[row][col] == 'L')
                mlx_put_image_to_window((*solong).mlx, (*solong).win.ref, (*solong).spriteref[7], col * 32, row * 32);
            col++;
        }
        row++;
    }
}

void    ft_init_sprite(t_program *solong)
{
    t_image sprite;

    (*solong).spriteref = malloc(sizeof(void *) * ft_strlen((*solong).map[0]) * ft_map_lines((*solong).map));
    sprite = ft_new_sprite((*solong).mlx, "./img/wall.xpm");
    (*solong).spriteref[0] = sprite.ref;
    sprite = ft_new_sprite((*solong).mlx, "./img/long_grass.xpm");
    (*solong).spriteref[1] = sprite.ref;
    sprite = ft_new_sprite((*solong).mlx, "./img/fish.xpm");
    (*solong).spriteref[2] = sprite.ref;
    sprite = ft_new_sprite((*solong).mlx, "./img/door.xpm");
    (*solong).spriteref[3] = sprite.ref;
    sprite = ft_new_sprite((*solong).mlx, "./img/front.xpm");
    (*solong).spriteref[4] = sprite.ref;
    sprite = ft_new_sprite((*solong).mlx, "./img/back.xpm");
    (*solong).spriteref[5] = sprite.ref;
    sprite = ft_new_sprite((*solong).mlx, "./img/right.xpm");
    (*solong).spriteref[6] = sprite.ref;
    sprite = ft_new_sprite((*solong).mlx, "./img/left.xpm");
    (*solong).spriteref[7] = sprite.ref;
    
}

void    ft_init_fish(t_program *solong)
{
    int row;
    int col;

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
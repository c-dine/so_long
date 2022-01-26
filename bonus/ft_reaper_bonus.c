/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reaper_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:43:03 by cdine             #+#    #+#             */
/*   Updated: 2022/01/26 20:35:03 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    ft_init_reaper(t_program *solong)
{
    int row;
    int col;
    int placed;

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

void    ft_init_sprite_reaper(t_program *solong)
{
    t_image sprite;

    sprite = ft_new_sprite((*solong).mlx, "./img/death1.xpm");
    (*solong).spriteref[8] = sprite.ref;
   sprite = ft_new_sprite((*solong).mlx, "./img/death_left.xpm");
    (*solong).spriteref[9] = sprite.ref;
}

int     ft_get_reaper_col(t_program *solong)
{
    int row;
    int col;

    row = 0;
    while ((*solong).map[row][0])
    {
        col = 0;
        while ((*solong).map[row][col])
        {
            if ((*solong).map[row][col] == 'Z' || (*solong).map[row][col] == 'Y')
                return (col);
            col++;
        }
        row++;
    }
    return (-1);
}

int     ft_get_reaper_row(t_program *solong)
{
    int row;
    int col;

    row = 0;
    while ((*solong).map[row][0])
    {
        col = 0;
        while ((*solong).map[row][col])
        {
            if ((*solong).map[row][col] == 'Z' || (*solong).map[row][col] == 'Y')
                return (row);
            col++;
        }
        row++;
    }
    return (-1);
}

int ft_checkway_reaper(t_program *solong, char dir, int col, int row)
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

void    ft_move_reaper_dir(t_program *solong, char dir, int x, int y)
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

void    ft_move_reaper(t_program *solong, int row, int col)
{
    int     x;
    int     y;
    char    side;


    x = (*solong).reaper.x;
    y = (*solong).reaper.y;
    printf("%d %d\n", x, y);
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
        printf("RIPPER IS STUCKED! :(");
    (*solong).reaper.x = ft_get_reaper_col(solong);
    (*solong).reaper.y = ft_get_reaper_row(solong);
}
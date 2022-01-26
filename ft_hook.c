/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:25:08 by cdine             #+#    #+#             */
/*   Updated: 2022/01/26 00:51:44 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_checkway(t_program *solong, char dir, int row, int col)
{
    if (dir == 'l')
    {
        if ((*solong).map[row][col - 1] == '1' || ((*solong).map[row][col - 1] == 'E' && (*solong).fish_caught != (*solong).nb_fish_total))
            return (0);
    }
    if (dir == 'r')
    {
        if ((*solong).map[row][col + 1] == '1' || ((*solong).map[row][col + 1] == 'E' && (*solong).fish_caught != (*solong).nb_fish_total))
            return (0);
    }
    if (dir == 'u')
    {
        if ((*solong).map[row - 1][col] == '1' || ((*solong).map[row - 1][col] == 'E' && (*solong).fish_caught != (*solong).nb_fish_total))
            return (0);
    }
    if (dir == 'd')
    {
        if ((*solong).map[row + 1][col] == '1' || ((*solong).map[row + 1][col] == 'E' && (*solong).fish_caught != (*solong).nb_fish_total))
            return (0);
    }
    return (1);
}

void    ft_editmap(t_program *solong, char dir, int row, int col)
{
    if (dir == 'l')
    {
        (*solong).map[row][col] = '0';
        if ((*solong).map[row][col - 1] == 'C')
            (*solong).fish_caught += 1;
        if ((*solong).map[row][col - 1] == 'E')
        {
            (*solong).win_lose = 1;
            ft_close(solong);
        }
        (*solong).map[row][col - 1] = 'P';
    }
    if (dir == 'r')
    {
        (*solong).map[row][col] = '0';
        if ((*solong).map[row][col + 1] == 'C')
            (*solong).fish_caught += 1;
        if ((*solong).map[row][col + 1] == 'E')
        {
            (*solong).win_lose = 1;
            ft_close(solong);
        }
        (*solong).map[row][col + 1] = 'P';
    }
    if (dir == 'd')
    {
        (*solong).map[row][col] = '0';
        if ((*solong).map[row + 1][col] == 'C')
            (*solong).fish_caught += 1;
        if ((*solong).map[row + 1][col] == 'E')
        {
            (*solong).win_lose = 1;
            ft_close(solong);
        }
        (*solong).map[row + 1][col] = 'P';
    }
    if (dir == 'u')
    {
        (*solong).map[row][col] = '0';
        if ((*solong).map[row - 1][col] == 'C')
            (*solong).fish_caught += 1;
        if ((*solong).map[row - 1][col] == 'E')
        {
            (*solong).win_lose = 1;
            ft_close(solong);
        }
        (*solong).map[row - 1][col] = 'P';
    }
    (*solong).move_count += 1;
}

void    ft_move(char dir, t_program *solong)
{
    int row;
    int col;
    int moved;

    moved = 0;
    row = 0;
    while ((*solong).map[row][0])
    {
        col = 0;
        while ((*solong).map[row][col])
        {
            if ((*solong).map[row][col] == 'P')
            {
                if (ft_checkway(solong, dir, row, col) == 1)
                {
                    ft_editmap(solong, dir, row, col);
    ////////////////////////////////////////////////////////////////////
    printf("Move count: %d\tFish caught: %d/%d\n", (*solong).move_count, (*solong).fish_caught, (*solong).nb_fish_total);
    ////////////////////////////////////////////////
                    // ft_destroy_map(solong);
                    ft_init_map(solong);
                    moved = 1;
                }
                else
                    break ;
            }
            if (moved == 1)
                break ;
            col++;
        }
        if (moved == 1)
            break ;
        row++;
    }
}

int ft_keyhook(int keycode, t_program *solong)
{
    (void) solong;
    if (keycode == XK_Escape)
        ft_close(solong);
    if (keycode == XK_q)
        ft_move('l', solong);
    if (keycode == XK_d)
        ft_move('r', solong);
    if (keycode == XK_z)
        ft_move('u', solong);
    if (keycode == XK_s)
        ft_move('d', solong);
    return (0);
}

void    ft_hook(t_program *solong)
{
    mlx_hook((*solong).win.ref, 17, 0, ft_close, solong);
    mlx_key_hook((*solong).win.ref, &ft_keyhook, solong);
}
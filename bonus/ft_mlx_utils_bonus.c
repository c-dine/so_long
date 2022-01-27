/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:32:16 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 17:21:04 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_window	ft_new_window(void *mlx, int width, int height, char *name)
{
	t_window	win;

	win.ref = mlx_new_window(mlx, width, height, name);
	win.size.x = width;
	win.size.y = height;
	return (win);
}

t_image	ft_new_sprite(t_program *solong, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image((*solong).mlx, path, &img.size.x,
			&img.size.y);
	if (img.ref == NULL)
		ft_close(solong);
	(*solong).nb_sprite++;
	img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

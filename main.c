/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:45:06 by cdine             #+#    #+#             */
/*   Updated: 2022/01/24 20:36:59 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	void		*mlx;
	t_window	win;

	map = ft_putmapintab(argv[1]);
	if (argc != 2 || map == NULL || ft_checkmap(argv[1], map) != 1)
	{
		if (map == NULL)
			ft_error(argc, 7);
		else
			ft_error(argc, ft_checkmap(argv[1], map));
		return (0);
	}
	mlx = mlx_init();
	win.ref = mlx_new_window(mlx, 1920, 1080, "so_long");
	mlx_loop(mlx);
	ft_putmap(win.ref, map, mlx)
}
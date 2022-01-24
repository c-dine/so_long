/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:45:06 by cdine             #+#    #+#             */
/*   Updated: 2022/01/24 19:21:22 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	map = ft_putmapintab(argv[1]);
	if (argc != 2 || map == NULL || ft_checkmap(argv[1], map) != 1)
	{
		if (map == NULL)
			ft_error(argc, 7);
		else
			ft_error(argc, ft_checkmap(argv[1], map));
		return (0);
	}
}
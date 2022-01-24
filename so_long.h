/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:42:06 by cdine             #+#    #+#             */
/*   Updated: 2022/01/24 20:31:58 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx/include/mlx.h"

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*ref;
	t_vector	size;
}				t_window;

typedef struct	s_image {
	void		*ref;
	char		*addr;
	t_vector	size;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
int		ft_checkmap(char *map, char **map_lines);
int		ft_map_lines(char **map);
int		ft_checkelements(char **map);
int		ft_checkECP(char **map, char c);
int		ft_checkwalls(char **map);
int		ft_checkrectangle(char **map);
int		ft_checkextension(char *map);
char	**ft_putmapintab(char *map_path);
void	ft_error(int argc, int checkmap);
void	ft_delete_n(char **map);

#endif
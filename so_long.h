/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:42:06 by cdine             #+#    #+#             */
/*   Updated: 2022/01/26 00:42:49 by cdine            ###   ########.fr       */
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
# include <stdio.h>
# include <X11/keysym.h>

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

typedef struct	s_sprite_ref {
	void				*ref;
	struct s_sprite_ref	*next;
}				t_sprite_ref;

typedef struct	s_program {
	void			*mlx;
	t_window		win;
	char			**map;
	t_sprite_ref	*sprites;
	int				move_count;
	int				nb_fish_total;
	int				fish_caught;
	int				win_lose;
}				t_program;

char		*get_next_line(int fd);
int			ft_strlen(const char *s);
int			ft_checkmap(char *map, char **map_lines);
int			ft_map_lines(char **map);
int			ft_checkelements(char **map);
int			ft_checkECP(char **map, char c);
int			ft_checkwalls(char **map);
int			ft_checkrectangle(char **map);
int			ft_checkextension(char *map);
char		**ft_putmapintab(char *map_path);
void		ft_error(int argc, int checkmap);
void		ft_delete_n(char **map);
t_window    ft_new_window(void *mlx, int width, int height, char *name);
void		ft_init_map(t_program *solong);
t_image		ft_new_sprite(void *mlx, char *path);
void		ft_hook(t_program *solong);
int			ft_close (t_program *solong);
void		ft_lstadd_back(t_sprite_ref **alst, t_sprite_ref *new);
t_sprite_ref	*ft_lstlast(t_sprite_ref *lst);
t_sprite_ref	*ft_lstnew(void *content);
void    ft_destroy_map(t_program *solong);
void    ft_init_fish(t_program *solong);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:42:06 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 23:07:36 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx/include/mlx.h"
# include <stdio.h>
# include <X11/keysym.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*ref;
	t_vector	size;
}				t_window;

typedef struct s_image {
	void		*ref;
	char		*addr;
	t_vector	size;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_program {
	void			*mlx;
	t_window		win;
	char			**map;
	char			**spriteref;
	int				nb_sprite;
	int				move_count;
	int				nb_fish_total;
	int				fish_caught;
	int				win_lose;
	int				loop_kill;
}				t_program;

char		*ft_itoa(int nb, t_program *solong);
char		*get_next_line(int fd);
int			ft_strlen(const char *s);
int			ft_checkmap(char *map, char **map_lines);
int			ft_map_lines(char **map);
int			ft_checkelements(char **map);
int			ft_check_ecp(char **map, char c);
int			ft_checkwalls(char **map);
int			ft_checkrectangle(char **map);
int			ft_checkextension(char *map);
char		**ft_putmapintab(char *map_path);
void		ft_error(int argc, int checkmap);
void		ft_delete_n(char **map);
t_window	ft_new_window(void *mlx, int width, int height, char *name);
void		ft_init_map(t_program *solong);
t_image		ft_new_sprite(t_program *solong, char *path);
int			ft_close(t_program *solong);
void		ft_destroy_map(t_program *solong);
void		ft_init_var(t_program *solong);
void		ft_redraw_map(t_program *solong);
int			ft_get_index_ref(char c);
int			ft_keyhook(int keycode, t_program *solong);
void		ft_init_reaper(t_program *solong);
void		ft_init_sprite_reaper(t_program *solong);
void		ft_move_reaper(t_program *solong, int row, int col);
int			ft_get_position_col(t_program *solong, char c);
int			ft_get_position_row(t_program *solong, char c);
void		ft_death(t_program *solong);
void		ft_checkdeath(t_program *solong);
char		*ft_get_string(t_program *solong, int msg);
void		ft_display_msg(t_program *solong, int msg);
void		ft_display_move_count(t_program *solong);
void		ft_display_fish_count(t_program *solong);
void		ft_display_which_msg(t_program *solong, int msg);
int			ft_isline(char *str);
int			ft_hook_death(t_program *solong);
void		ft_init_sprite_reaper_left(t_program *solong);

#endif
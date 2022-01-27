/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:04:48 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 18:38:09 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_nb_lines_gnl(char *map_path)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

char	**ft_fill_map(int fd, int line_count)
{
	char	*line;
	char	**map;
	int		k;

	k = 0;
	map = malloc(sizeof(char **) * (line_count + 1));
	if (map == NULL)
		exit(0);
	line = get_next_line(fd);
	while (line)
	{
		map[k++] = line;
		line = get_next_line(fd);
	}
	map[k] = malloc(sizeof(char));
	if (map[k] == NULL)
		exit(0);
	map[k][0] = '\0';
	ft_delete_n(map);
	return (map);
}

char	**ft_putmapintab(char *map_path)
{
	int		fd;
	int		line_count;

	line_count = ft_nb_lines_gnl(map_path);
	if (line_count == -1)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	return (ft_fill_map(fd, line_count));
}

int	ft_checkmap(char *map, char **map_lines)
{
	int	ret;

	ret = 1;
	if (ft_checkextension(map) == 0)
		ret = 8;
	else if (ft_checkrectangle(map_lines) == 0)
		ret = 6;
	else if (ft_checkwalls(map_lines) == 0)
		ret = 2;
	else if (ft_checkelements(map_lines) != 1)
		ret = ft_checkelements(map_lines);
	return (ret);
}

void	ft_error(int argc, int checkmap)
{
	write(1, "Error\n", 6);
	if (argc != 2)
		write(1, "Wrong number of parameters.\n", 28);
	if (checkmap == 2)
		write(1, "Map not enclosed.\n", 18);
	if (checkmap == 3)
		write(1, "No exit.\n", 9);
	if (checkmap == 4)
		write(1, "No collectible.\n", 16);
	if (checkmap == 5)
		write(1, "None or too many starting points.\n", 34);
	if (checkmap == 6)
		write(1, "Map is not a rectangle.\n", 24);
	if (checkmap == 7)
		write(1, "Map opening error.\n", 19);
	if (checkmap == 8)
		write(1, "Map extension error.\n", 21);
}

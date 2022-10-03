/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:42:45 by ktakada           #+#    #+#             */
/*   Updated: 2022/10/01 17:42:46 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//static char **read_map(int fd);
//
//static bool is_map_rectangular(int fd, char **map);

bool parse_map(char *map)
{
	int		fd;
//	char	**map;
//	bool	ok;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_with_error("");
//	map = read_map(fd);
//	if (map == NULL)
//
//	ok = is_map_rectangular(fd, map)
	if (close(fd) == -1)
		exit_with_error("");
	return true;
}

//char **read_map(int fd)
//{
//	char	**map;
//	char	*line;
//	size_t 	i;
//
//	i = 0;
//	while ((line = get_next_line(fd)) != NULL)
//		i++;
//	map = (char **)malloc(sizeof(char *) * i + 1);
//	if (map == NULL)
//		return (NULL);
//	i = 0;
//
//	return (map);
//}
//
//bool is_map_rectangular(int fd, char **map)
//{
//	char	*line;
//	size_t 	i;
//
//	i = 0;
//	while ()
//	line = get_next_line(fd);
//}

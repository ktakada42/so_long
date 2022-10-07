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

#include "../includes/map.h"

static bool	is_map_ext_ber(char *map);
static bool	is_map_only_dot_ber(char *map);
//static t_list	*read_map_file(int fd);

bool	parse_map(char *map)
{
	int		fd;
//	t_list	*map_line_list;

	errno = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_with_error("error at open()");
	if (!is_map_ext_ber(map))
		exit_with_error("map is not ber file");
//	map_line_list = read_map_file(fd);
//	if (map_line_list == NULL)
//		exit_with_error("Error\nerror at read map");
	if (close(fd) == -1)
		exit_with_error("error at close()");
	return (true);
}

bool	is_map_ext_ber(char *map)
{
	char	**file_name_split_by_dots;
	size_t	i;
	int		diff;

	if (is_map_only_dot_ber(map))
		return (false);
	file_name_split_by_dots = ft_split(map, '.');
	i = 0;
	while (file_name_split_by_dots[i] != NULL)
		i++;
	if (ft_strlen(file_name_split_by_dots[i - 1]) != 3)
		return (false);
	diff = ft_strncmp("ber", file_name_split_by_dots[i - 1], 3);
	i = 0;
	while (file_name_split_by_dots[i] != NULL)
	{
		free(file_name_split_by_dots[i]);
		i++;
	}
	free(file_name_split_by_dots);
	if (diff != 0)
		return (false);
	return (true);
}

bool	is_map_only_dot_ber(char *map)
{
	char	**file_name_split_by_slash;
	size_t	i;
	int		diff;

	file_name_split_by_slash = ft_split(map, '/');
	i = 0;
	while (file_name_split_by_slash[i] != NULL)
		i++;
	if (ft_strlen(file_name_split_by_slash[i - 1]) != 4)
		return (false);
	diff = ft_strncmp(".ber", file_name_split_by_slash[i - 1], 4);
	i = 0;
	while (file_name_split_by_slash[i] != NULL)
	{
		free(file_name_split_by_slash[i]);
		i++;
	}
	free(file_name_split_by_slash);
	if (diff != 0)
		return (false);
	return (true);
}

//t_list	*read_map_file(int fd)
//{
//	char	*one_line;
//	t_list	*map_line_list;
//	t_list	*new_list;
//	size_t	map_width;
//	size_t 	wall_count;
//
//	wall_count = 0;
//	one_line = get_next_line(fd);
//	if (one_line == NULL)
//		return (NULL);
//	map_width = ft_strlen(one_line) - 1;
//	while (*one_line != '\0')
//	{
//		if (*one_line == '1')
//			wall_count++;
//		one_line++;
//	}
//	if (wall_count != map_width)
//	{
//		printf("wall_count: %zu, map_width: %zu\n", wall_count, map_width);
//		exit_with_error("Error\nmap must be surrounded by wall");
//	}
//	map_line_list = ft_lstnew(one_line);
//	while (true)
//	{
//		one_line = get_next_line(fd);
//		if (one_line == NULL)
//			return map_line_list;
//		new_list = ft_lstnew(one_line);
//		if (new_list == NULL)
//		{
//			free(one_line);
//			ft_lstclear(&map_line_list, free);
//		}
//		if (ft_strlen(one_line) - 1 != map_width)
//			exit_with_error("Error\nmap must be rectangular");
//		while (*one_line != '\0')
//		{
//			if (*one_line != '0' && *one_line != '1' && *one_line != 'E' && *one_line != 'C' && *one_line != 'P' && *one_line != '\n')
//				exit_with_error("Error\nmap includes invalid character");
//			one_line++;
//		}
//		ft_lstadd_back(&map_line_list, new_list);
//	}
//}

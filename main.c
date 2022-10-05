/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:59:27 by ktakada           #+#    #+#             */
/*   Updated: 2022/09/28 16:22:11 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	errno = 0;
	if (argc != 2)
		exit_with_error("Need 1 arg as map");
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		exit_with_error("Error at mlx_init()");
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (win_ptr == NULL)
		exit_with_error("Error at mlx_new_window()");
	if (parse_map(argv[1]))
	{
		mlx_key_hook(win_ptr, key_hook, NULL);
		mlx_loop(mlx_ptr);
	}
}

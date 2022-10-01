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

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		ft_putendl_fd("error at mlx_init()", 2);
		exit(1);
	}
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (win_ptr == NULL)
	{
		ft_putendl_fd("error at mlx_new_window()", 2);
		exit(1);
	}
	mlx_loop(mlx_ptr);
}

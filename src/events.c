/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:58:12 by ktakada           #+#    #+#             */
/*   Updated: 2022/10/05 14:58:12 by ktakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/events.h"

int	key_hook(int keycode, void *param)
{
	if (param == NULL && keycode == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

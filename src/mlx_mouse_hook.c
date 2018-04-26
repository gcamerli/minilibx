/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:12:17 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/26 16:12:46 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_mouse_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[ButtonPress].hook = funct;
	win->hooks[ButtonPress].param = param;
	win->hooks[ButtonPress].mask = ButtonPressMask;
	return (0);
}

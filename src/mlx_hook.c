/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:34:17 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/25 21:00:20 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_hook(t_win_list *win, int x_event, int x_mask,
		int (*funct)(), void *param)
{
	win->hooks[x_event].hook = funct;
	win->hooks[x_event].param = param;
	win->hooks[x_event].mask = x_mask;
	return (0);
}

int	mlx_do_key_autorepeatoff(t_xvar *xvar)
{
	XAutoRepeatOff(xvar->display);
	return (0);
}

int	mlx_do_key_autorepeaton(t_xvar *xvar)
{
	XAutoRepeatOn(xvar->display);
	return (0);
}

int	mlx_do_sync(t_xvar *xvar)
{
	XSync(xvar->display, False);
	return (0);
}

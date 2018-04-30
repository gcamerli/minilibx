/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:02:07 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/30 17:28:40 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_string_put(t_xvar *xvar, t_win_list *win,
		int x, int y, int color, char *string)
{
	XGCValues	xgcv;

	xgcv.foreground = mlx_int_get_good_color(xvar, color);
	XChangeGC(xvar->display, win->gc, GCForeground, &xgcv);
	XDrawString(xvar->display, win->window, win->gc, x, y, string,
			strlen(string));
	if (xvar->do_flush)
		XFlush(xvar->display);
	return (0);
}

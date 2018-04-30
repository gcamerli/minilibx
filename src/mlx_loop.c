/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:14:20 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/30 17:18:35 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

extern int	(*(mlx_int_param_event[]))();

int	mlx_loop(t_xvar *xvar)
{
	XEvent		ev;
	t_win_list	*win;

	mlx_int_set_win_event_mask(xvar);
	xvar->do_flush = 0;
	while (42)
	{
		while (!xvar->loop_hook || XPending(xvar->display))
		{
			XNextEvent(xvar->display, &ev);
			win = xvar->win_list;
			while (win && (win->window != ev.xany.window))
				win = win->next;
			if (win && ev.type < MLX_MAX_EVENT)
				if (win->hooks[ev.type].hook)
					mlx_int_param_event[ev.type](xvar, &ev, win);
		}
		xvar->loop_hook(xvar->loop_param);
	}
}

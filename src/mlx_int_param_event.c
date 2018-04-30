/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_param_event.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:27:21 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/30 16:57:40 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int	mlx_int_param_undef(void)
{
	return (0);
}

int	mlx_int_param_KeyPress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[KeyPress].hook(XkbKeycodeToKeysym(xvar->display,
				ev->xkey.keycode, 0, 0),
			win->hooks[KeyPress].param);
}

int	mlx_int_param_KeyRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[KeyRelease].hook(XkbKeycodeToKeysym(xvar->display,
				ev->xkey.keycode, 0, 0),
			win->hooks[KeyRelease].param);
}

int	mlx_int_param_ButtonPress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[ButtonPress].hook(ev->xbutton.button, ev->xbutton.x,
			ev->xbutton.y, win->hooks[ButtonPress].param);
}

int	mlx_int_param_ButtonRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[ButtonRelease].hook(ev->xbutton.button,
			ev->xbutton.x, ev->xbutton.y,
			win->hooks[ButtonRelease].param);
}

int	mlx_int_param_MotionNotify(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[MotionNotify].hook(ev->xbutton.x, ev->xbutton.y,
			win->hooks[MotionNotify].param);
}

int	mlx_int_param_Expose(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	if (!ev->xexpose.count)
		win->hooks[Expose].hook(win->hooks[Expose].param);
}

int	mlx_int_param_generic(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	win->hooks[ev->type].hook(win->hooks[ev->type].param);
}

int	(*(mlx_int_param_event[]))() =
{
	mlx_int_param_undef,
	mlx_int_param_undef,
	mlx_int_param_KeyPress,
	mlx_int_param_KeyRelease,
	mlx_int_param_ButtonPress,
	mlx_int_param_ButtonRelease,
	mlx_int_param_MotionNotify,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_Expose,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic
};

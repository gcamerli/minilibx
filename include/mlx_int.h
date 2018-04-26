/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:32:28 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/25 19:52:06 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	1. Settings for MiniLibX
*/

#ifndef MLX_INT_H
# define MLX_INT_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <X11/XKBlib.h>

/*
** # include <X11/xpm.h>
*/

# define MLX_TYPE_SHM_PIXMAP 3
# define MLX_TYPE_SHM 2
# define MLX_TYPE_XIMAGE 1
# define MLX_MAX_EVENT LASTEvent
# define ENV_DISPLAY "DISPLAY"
# define LOCALHOST "localhost"
# define ERR_NO_TRUECOLOR "MinilibX ERR: No TrueColor Visual available.\n"
# define WARN_SHM_ATTACH "MinilibX ERR: X server can't attach shared memory.\n"

/*
**	2. Structures
*/

typedef	struct	s_xpm_col
{
	int			name;
	int			col;
}				t_xpm_col;

typedef struct	s_col_name
{
	char		*name;
	int			color;
}				t_col_name;

typedef struct	s_event_list
{
	int			mask;
	int			(*hook)();
	void		*param;
}				t_event_list;

typedef struct	s_win_list
{
	Window				window;
	GC					gc;
	struct s_win_list	*next;
	int					(*mouse_hook)();
	int					(*key_hook)();
	int					(*expose_hook)();
	void				*mouse_param;
	void				*key_param;
	void				*expose_param;
	t_event_list		hooks[MLX_MAX_EVENT];
}				t_win_list;

typedef struct	s_img
{
	XImage			*image;
	Pixmap			pix;
	GC				gc;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	XShmSegmentInfo	shm;
}				t_img;

typedef struct	s_xvar
{
	Display		*display;
	Window		root;
	int			screen;
	int			depth;
	Visual		*visual;
	Colormap	cmap;
	int			private_cmap;
	t_win_list	*win_list;
	int			(*loop_hook)();
	void		*loop_param;
	int			use_xshm;
	int			pshm_format;
	int			do_flush;
	int			decrgb[6];
}				t_xvar;

/*
**	3. Functions
*/

int				mlx_int_do_nothing();
int				mlx_int_get_good_color();
int				mlx_int_find_in_pcm();
int				mlx_int_anti_resize_win();
int				mlx_int_wait_first_expose();
int				mlx_int_rgb_conversion();
int				mlx_int_deal_shm();
int				mlx_int_get_visual();
int				mlx_int_set_win_event_mask();
int				mlx_int_str_str();
int				mlx_int_str_str_cote();
void			*mlx_int_new_xshm_image();
char			**mlx_int_str_to_wordtab();
void			*mlx_new_image();
int				shm_att_pb();

#endif

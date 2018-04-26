/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_window.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicamerl <gicamerl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:15:48 by gicamerl          #+#    #+#             */
/*   Updated: 2018/04/26 16:34:05 by gicamerl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <Cocoa/Cocoa.h>
#import "mlx_int.h"

@interface NSWindowEvent : NSWindow
{
	t_func	event_funct[MAX_EVENT];
	void	*(event_param[MAX_EVENT]);
	int		keyrepeat;
	int		keyflag;
	int		size_x;
	int		size_y;
}
- (NSWindowEvent *) initWithContentRect:(NSRect)rect styleMask:(NSUInteger)winstyle backing:(NSBackingStoreType)bck defer:(BOOL) dfr;
- (void) setEvent:(int)event andFunc:(t_func)func andParam:(void *)param;
- (void) setKeyRepeat:(int)mode;
- (void) exposeNotification:(NSNotification *)note;
- (void) closeNotification:(NSNotification *)note;
@end

@interface MlxWin : NSOpenGLView
{
	NSWindowEvent		*win;
	NSOpenGLContext		*ctx;
	t_glsl_info			glsl;
	int					openglwin;
	int					size_x;
	int					size_y;
	int					pixel_nb;
	GLuint				pixel_vbuffer;
	GLuint				pixel_texture;
	unsigned int		*pixtexbuff;
}

- (id) initWithRect: (NSRect)rect andTitle: (NSString *)title pfaAttrs: (NSOpenGLPixelFormatAttribute *)attrs;
- (void) selectGLContext;
- (void) flushGLContext;
- (void) pixelPutColor: (int)color X:(int)x Y:(int)y;
- (void) mlx_gl_draw;
- (void) mlx_gl_draw_img:(t_mlx_img_list *)img andCtx:(t_mlx_img_ctx *)imgctx andX:(int)x andY:(int)y;
- (void) mlx_gl_draw_font:(t_mlx_img_list *)img andCtx:(t_mlx_img_ctx *)imgctx andX:(int)x andY:(int)y andColor:(int)color glyphX:(int)gx glyphY:(int)gy;
- (NSOpenGLContext *) ctx;
- (void) setEvent:(int)event andFunc:(t_func)func andParam:(void *)param;
- (void) setKeyRepeat:(int)mode;
- (void) ctxNeedsUpdate;
@end

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 22:03:28 by lenocka           #+#    #+#             */
/*   Updated: 2020/07/28 18:05:14 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

# define HEIGHT	800
# define WIDTH	800

typedef struct	s_color
{
	int8_t		channel[4];
}				t_color;

typedef	struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			iter;
	int			num_f;
	t_complex	max;
	t_complex	min;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
}				t_fractol;

void			get_fractol(t_fractol *fractol, char *name);
void			image_init(t_fractol *fractol);
t_complex		init_complex(double re, double im);
int				mandelbrot(t_fractol *fractol);
void			draw_mandelbrot(t_fractol *fractol);
t_color			get_color(int i, t_fractol *fractol);
void			put_pixel(t_fractol *fractol, int x, int y, t_color color);
void			draw_julia(t_fractol *fractol);
int				julia(t_fractol *fractol);
void			choose_fractol(t_fractol *fractol);
void			julia_motion(int x, int y, t_fractol *fractol);
void			zoom(int button, int x, int y, t_fractol *fractol);
double			changing(double start, double end, double change);
void			start_init(t_fractol *fractol);
void			draw_celticmandelbrot(t_fractol *fractol);
int				celticmandelbrot(t_fractol *fractol);
void			move(int key, t_fractol *fractol);
int				burningship(t_fractol *fractol);
void			draw_burningship(t_fractol *fractol);
int				mandelbar(t_fractol *fractol);
void			draw_mandelbar(t_fractol *fractol);
int				celticmandelbar(t_fractol *fractol);
void			draw_celticmandelbar(t_fractol *fractol);
void			draw_phoenix(t_fractol *fractol);
int				phoenix(t_fractol *fractol);
#endif

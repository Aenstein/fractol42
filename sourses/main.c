/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 21:33:37 by aenstein          #+#    #+#             */
/*   Updated: 2020/07/26 16:55:31 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_fractol(t_fractol *fractol, char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		fractol->num_f = 1;
	else if (ft_strcmp(name, "julia") == 0)
		fractol->num_f = 2;
	else if (ft_strcmp(name, "celticmandelbrot") == 0)
		fractol->num_f = 3;
	else if (ft_strcmp(name, "burningship") == 0)
		fractol->num_f = 4;
	else if (ft_strcmp(name, "mandelbar") == 0)
		fractol->num_f = 5;
	else if (ft_strcmp(name, "celticmandelbar") == 0)
		fractol->num_f = 6;
	else
	{
		ft_putstr("Usage names fractol: mandelbrot, julia, celticmandelbrot,");
		ft_putendl(" burningship, mandelbar, celticmandelbar, phoenix");
		exit(0);
	}
}

int		key_press(int key, t_fractol *fractol)
{
	if (key == 0 || key == 1 || key == 2 || key == 13)
		move(key, fractol);
	if (key == 53)
		exit(0);
	return (0);
}

int		mouse_move(int x, int y, t_fractol *fractol)
{
	julia_motion(x, y, fractol);
	choose_fractol(fractol);
	return (0);
}

int		mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4 || button == 5)
		zoom(button, x, y, fractol);
	return (0);
}

int		main(int ac, char **av)
{
	t_fractol	fractol[1];

	if (ac == 2)
	{
		get_fractol(fractol, av[1]);
		image_init(fractol);
		start_init(fractol);
		mlx_hook(fractol->win, 2, 0, key_press, fractol);
		mlx_hook(fractol->win, 4, 0, mouse_press, fractol);
		mlx_hook(fractol->win, 6, 0, mouse_move, fractol);
		choose_fractol(fractol);
		mlx_loop(fractol->mlx);
	}
	return (0);
}

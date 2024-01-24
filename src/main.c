/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:58:58 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/21 17:10:38 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	proper_exit(void *d)
{
	mlx_terminate(((t_data *)d)->mlx);
	exit (-1);
}

void	mandelbrot(t_data *d)
{
	t_data	t;

	t.y = -1;
	while (++t.y < HEIGHT)
	{
		t.x = -1;
		while (++t.x < WIDTH)
		{
			t.c_im = d->max_im - t.y * d->factor_im;
			t.c_re = d->min_re + t.x * d->factor_re;
			t.z_re = t.c_re;
			t.z_im = t.c_im;
			t.i = -1;
			while (++t.i < MAX_ITER)
			{
				t.z_re2 = t.z_re * t.z_re;
				t.z_im2 = t.z_im * t.z_im;
				if (t.z_re2 + t.z_im2 > 4)
					break ;
				t.z_im = 2 * t.z_re * t.z_im + t.c_im;
				t.z_re = t.z_re2 - t.z_im2 + t.c_re;
			}
			set_px_col(d->img, t.x, t.y, get_colour((t.i % 16)));
		}
	}
}

void	julia(t_data *d)
{
	t_data	t;

	t.y = -1;
	while (++t.y < HEIGHT)
	{
		t.x = -1;
		while (++t.x < WIDTH)
		{
			t.z_re = d->min_re + t.x * d->factor_re;
			t.z_im = d->max_im - t.y * d->factor_im;
			t.i = -1;
			while (++t.i < MAX_ITER)
			{
				t.z_re2 = t.z_re * t.z_re - t.z_im * t.z_im + d->julia_c_re;
				t.z_im2 = 2 * t.z_re * t.z_im + d->julia_c_im;
				t.z_re = t.z_re2;
				t.z_im = t.z_im2;
				if (t.z_re * t.z_re + t.z_im * t.z_im > 4)
					break ;
			}
			set_px_col(d->img, t.x, t.y, get_colour(t.i % 16));
		}
	}
}

void	draw_fractal(t_data *d)
{
	if (d->fractal == 1)
	{
		d->mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true);
		if (!d->mlx)
			exit (EXIT_FAILURE);
		d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
		if (!d->img)
			proper_exit(d);
		mandelbrot(d);
		mlx_image_to_window(d->mlx, d->img, 0, 0);
	}
	else if (d->fractal == 2)
	{
		d->mlx = mlx_init(WIDTH, HEIGHT, "Julia", true);
		if (!d->mlx)
			exit (EXIT_FAILURE);
		d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
		if (!d->img)
			proper_exit(d);
		julia(d);
		mlx_image_to_window(d->mlx, d->img, 0, 0);
	}
}

int32_t	main(int argc, char **argv)
{
	t_data	d;

	if (argc == 1 || argc > 4)
		print_instructions();
	read_arguments(argv + 1, argc - 1, &d);
	init_viewport(&d);
	draw_fractal(&d);
	mlx_key_hook(d.mlx, &key_operations, &d);
	mlx_scroll_hook(d.mlx, &zoomer, &d);
	mlx_close_hook(d.mlx, &proper_exit, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	return (EXIT_SUCCESS);
}

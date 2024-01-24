/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:02:03 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/21 17:46:01 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	key_operations(mlx_key_data_t k, void *d)
{
	t_data	*dt;

	dt = (t_data *)d;
	if (k.key == MLX_KEY_W && k.action == MLX_PRESS)
		dt->center_im += 0.05 * (dt->max_im - dt->min_im);
	if (k.key == MLX_KEY_S && k.action == MLX_PRESS)
		dt->center_im -= 0.05 * (dt->max_im - dt->min_im);
	if (k.key == MLX_KEY_A && k.action == MLX_PRESS)
		dt->center_re -= 0.05 * (dt->max_re - dt->min_re);
	if (k.key == MLX_KEY_D && k.action == MLX_PRESS)
		dt->center_re += 0.05 * (dt->max_re - dt->min_re);
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
		proper_exit(dt);
	update_viewport(dt);
	if (dt->fractal == 1)
		mandelbrot(dt);
	else
		julia(dt);
}

void	zoomer(double xdelta, double ydelta, void *d)
{
	t_data	*dt;

	(void)xdelta;
	dt = (t_data *)d;
	if (ydelta > 0)
		dt->zoom *= 1.05;
	else if (ydelta < 0)
		dt->zoom *= 0.95;
	update_viewport(dt);
	if (dt->fractal == 1)
		mandelbrot(dt);
	else
		julia(dt);
}

void	init_viewport(t_data *d)
{
	d->zoom = 1.0;
	d->center_re = -0.7;
	d->center_im = 0;
	d->mlx = NULL;
	d->img = NULL;
	update_viewport(d);
}

void	update_viewport(t_data *d)
{
	double	range;

	range = (RE_RANGE / d->zoom);
	d->factor_re = range / (WIDTH - 1);
	d->factor_im = range / (HEIGHT - 1);
	d->min_re = d->center_re - range * 0.5;
	d->max_re = d->center_re + range * 0.5;
	d->min_im = d->center_im - range * 0.5;
	d->max_im = d->center_im + range * 0.5;
}

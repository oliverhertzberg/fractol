/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:31:04 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/24 11:46:11 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 150
# define RE_RANGE 6

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				fractal;
	double			zoom;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			factor_re;
	double			factor_im;
	double			center_re;
	double			center_im;
	double			c_re;
	double			c_im;
	double			z_re;
	double			z_im;
	double			z_re2;
	double			z_im2;
	double			julia_c_re;
	double			julia_c_im;
	int				i;
	int				y;
	int				x;
}	t_data;

unsigned int	get_colour(int n);
void			set_px_col(mlx_image_t *img, int x, int y, unsigned int colour);
void			key_operations(mlx_key_data_t k, void *d);
void			zoomer(double xdelta, double ydelta, void *d);
void			init_viewport(t_data *d);
void			update_viewport(t_data *d);
double			ft_atof(const char *str);
void			check_arguments(char *arg);
void			read_arguments(char **args, int arg_count, t_data *d);
void			print_instructions(void);
void			arg_error(void);
void			proper_exit(void *d);
void			mandelbrot(t_data *d);
void			julia(t_data *d);
void			draw_fractal(t_data *d);

#endif

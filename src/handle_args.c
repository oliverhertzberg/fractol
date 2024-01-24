/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:00:19 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/24 12:22:34 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;
	int		sign;

	sign = 1;
	c = (char *)str;
	if (str[0] == '-')
	{
		sign *= -1;
		c++;
	}
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	return (sign * (res + res2));
}

void	check_arguments(char *arg)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (found == 0 && i > 5)
			arg_error();
		if ((arg[i] != '.' && !ft_isdigit(arg[i])) || found > 1)
			arg_error();
		if (arg [i] == '.')
			found++;
		i++;
	}
}

void	read_arguments(char **args, int arg_count, t_data *d)
{
	ft_striteri((args[0]), &ft_tolower);
	if (ft_strncmp(args[0], "mandelbrot", 11) == 0)
		d->fractal = 1;
	else if (ft_strncmp(args[0], "julia", 6) == 0)
	{
		d->fractal = 2;
		if (arg_count > 2)
		{
			check_arguments(args[1]);
			check_arguments(args[2]);
			d->julia_c_re = ft_atof(args[1]);
			d->julia_c_im = ft_atof(args[2]);
		}
		else
		{
			d->julia_c_re = -0.835;
			d->julia_c_im = -0.2321;
		}
	}
	else
		print_instructions();
}

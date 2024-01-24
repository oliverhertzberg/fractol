/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:58:22 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/24 11:40:07 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_instructions(void)
{
	ft_printf("Fractol Program Instructions:\n"
		"Usage:\n"
		"  - To view the mandelbrot fractal, run: ./fractol mandelbrot\n"
		"  - For the julia set, run: ./fractol julia <double x> <double y>\n"
		"(Default values will be used if no arguments(or only one) provided)\n"
		"\nControls:\n"
		"  - Use 'W' and 'S' keys to move the center point up and down.\n"
		"  - Use 'A' and 'D' keys to move the center point left and right.\n"
		"  - Scroll up with your mouse to zoom out.\n"
		"  - Scroll down with your mouse to zoom in.\n"
		"  - Press the 'Esc' key to close the window and exit the program.\n");
	exit(-1);
}

void	arg_error(void)
{
	ft_printf("Argument error\n"
		"Run ./fractol for instructions\n");
	exit (-1);
}

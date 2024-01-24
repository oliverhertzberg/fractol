/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:01:15 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/21 17:32:59 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

unsigned int	get_colour(int n)
{
	static unsigned int	colours[16] = {
		0x421e0FFF, 0x19071AFF, 0x09012FFF,
		0x040449FF, 0x000764FF, 0x0C2C8AFF,
		0x1852B1FF, 0x397DD1FF, 0x86B5E5FF,
		0xD3ECF8FF, 0xF1E9BFFF, 0xF8C95FFF,
		0xFFAA00FF, 0xCC8000FF, 0x995700FF,
		0x6A3403FF};

	return (colours[n]);
}

void	set_px_col(mlx_image_t *img, int x, int y, unsigned int colour)
{
	int	index;

	index = (y * (int)img->width + x) * 4;
	if (x < (int)img->width && y < (int)img->height)
	{
		img->pixels[index] = (colour >> 24) & 0xFF;
		img->pixels[index + 1] = (colour >> 16) & 0xFF;
		img->pixels[index + 2] = (colour >> 8) & 0xFF;
		img->pixels[index + 3] = colour & 0xFF;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:54:44 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/24 11:29:57 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_tolower(unsigned int i, char *s)
{
	(void)i;
	if (*s >= 'A' && *s <= 'Z')
		*s += 32;
}

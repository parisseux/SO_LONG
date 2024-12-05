/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:05:30 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/05 17:17:36 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    ft_add_shade(double distance, int color)
{
     if (distance < 0.0)
        distance = 0.0; // Prevent overshading
    if (distance > 1.0)
        distance = 1.0; // Prevent overshading

    unsigned char t = get_t(color); // Transparency remains the same
    unsigned char r = get_r(color) * (1.0 - distance);
    unsigned char g = get_g(color) * (1.0 - distance);
    unsigned char b = get_b(color) * (1.0 - distance);

    return create_trgb(t, r, g, b);
}

int ft_get_opposite(int color)
{
    unsigned char t = get_t(color); // Keep transparency the same
    unsigned char r = 255 - get_r(color); // Invert red
    unsigned char g = 255 - get_g(color); // Invert green
    unsigned char b = 255 - get_b(color); // Invert blue

    return create_trgb(t, r, g, b);
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
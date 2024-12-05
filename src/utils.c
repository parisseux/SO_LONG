/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:54:47 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/05 19:57:02 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_clear_image(t_data *data, int color)
{
    int x, y;

    y = 0;
    while (y < 1080)  // Assuming your image height is 1080
    {
        x = 0;
        while (x < 1920)  // Assuming your image width is 1920
        {
            ft_put_pixel(data, x, y, color);  // Set the pixel to the background color
            x++;
        }
        y++;
    }
}
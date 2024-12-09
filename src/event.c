/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:50:40 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/06 11:32:13 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close_window_escp(int key, t_data *data)
{
    if (key == 53)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

int ft_close_window_cross(void)
{
    exit(0);
}

int ft_move(int key, t_data *data)
{
    if (key == 0) // a
        data->x -= 10;
    else if (key == 1) // s
        data->y += 10;
    else if (key == 2) // d
        data->x += 10;
    else if (key == 13) // w
        data->y -= 10;

    ft_clear_image(data); // Clear image with background color
    ft_draw_rectangle(data, data->x, data->y, 30, 40, data->color); // Redraw rectangle
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return(0);
}
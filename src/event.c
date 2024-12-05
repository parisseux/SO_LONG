/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:50:40 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/05 19:56:14 by pchatagn         ###   ########.fr       */
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

	printf("x: %d\n", data->x);
	printf("y: %d\n", data->y);
    if (key == 0 ) //a
        data->x = data->x - 5;
    else if (key == 1) //s
        data->y = data->y + 5;
    else if (key == 2) //d
        data->x = data->x + 5;
    else if (key == 13) //w
        data->y = data->y - 5;
	printf("x: %d\n", data->x);
	printf("y: %d\n", data->y);
    ft_clear_image(data, data->color);
	ft_draw_rectangle(data, data->x, data->y, 30, 40, data->color);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}
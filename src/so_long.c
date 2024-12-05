/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:30:33 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/05 19:59:28 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

//	printf("Setting pixel at (%d, %d) to color %d\n", x, y, color);

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    ft_draw_rectangle(t_data *data, int x, int y, int width, int height, int color)
{
    int i;
    int j;
    
    i = 0;
   
    while (i < width)
    { 
        j = 0;
        while (j < height)
        {
            ft_put_pixel(data, x + i, y + j, color);
            j++;
        }
        i++;
    }
}


int	main(void)
{
	t_data	data;
    data.color = create_trgb(145, 134, 0, 234);
   // int shaded_color = ft_get_opposite(data.color);
   data.x = 40;
   data.y = 60;
   data.height = 1080;
data.width = 1000;	

	data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.width, data.height, "Kitty Cat!");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
   	mlx_hook(data.win, 17, 0, &ft_close_window_cross, &data);
    mlx_key_hook(data.win, &ft_move, &data);
	ft_draw_rectangle(&data, data.x, data.y, 30, 40, data.color);
   // ft_put_pixel(&data, 40, 60, data.color);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
  //  mlx_key_hook(data.win, &ft_close_window_escp, &data);
    mlx_hook(data.win, 17, 0, &ft_close_window_cross, &data);
    mlx_key_hook(data.win, &ft_move, &data);
    mlx_loop(data.mlx);
}
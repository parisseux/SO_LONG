/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:30:33 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/09 12:33:13 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

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
int ft_track_mouse_move(int x, int y, t_data *data)
{
    // Clear the window before drawing the cursor
    mlx_clear_window(data->mlx, data->win);

    // Put the cursor image at the mouse's position
    mlx_put_image_to_window(data->mlx, data->win, data->cursor_img, x - data->cursor_width / 2, y - data->cursor_height / 2);

    return (0);
}
int ft_mouse_move(int x, int y, t_data *data)
{
    ft_track_mouse_move(x, y, data);
    return (0);
}


// int	main(void)
// {
// 	t_data	data;
//     data.color = create_trgb(145, 134, 0, 234);
//     char	*relative_path = "./test.xpm";
//     data.x = 40;
//     data.y = 60;
//     data.height = 700;
//     data.width = 900;	

//     //init
// 	data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, data.width, data.height, "Kitty Cat!");
// 	data.img = mlx_new_image(data.mlx, data.width, data.height);
//     data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    
//     data.cursor_img = mlx_xpm_file_to_image(data.mlx, "./cursor.xpm", &data.cursor_width, &data.cursor_height);
//     mlx_mouse_hide();
//    // mlx_hook(data.win, MotionNotify, PointerMotionMask, ft_mouse_move, &data);
    
//     //event
//     mlx_hook(data.win,2, 0, &ft_close_window_escp, &data);
//     mlx_hook(data.win, 17, 0, &ft_close_window_cross, &data);
//     mlx_key_hook(data.win, &ft_move, &data);
   
//    //backgrounf
//     data.img = mlx_xpm_file_to_image(data.mlx, relative_path, &data.width, &data.height);
//     mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

//     //ft_draw_rectangle(&data, data.x, data.y, 30, 40, data.color);
//    // mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
//     mlx_loop(data.mlx);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:29:12 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/09 15:26:18 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"


typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *cursor_img;
    int     cursor_width;
    int     cursor_height;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     x;
    int     y;
    int     height;
    int     width;
    int color;
} t_data;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//map checker
int ft_check_map(char av);

//so_long
void	ft_put_pixel(t_data *data, int x, int y, int color);
void	ft_draw_circle(t_data *data, int center_x, int center_y, int radius, int color);
void    ft_draw_rectangle(t_data *data, int x, int y, int width, int height, int color);

//colors
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
int    ft_add_shade(double distance, int color);
int ft_get_opposite(int color);

//event
int ft_close_window_escp(int key, t_data *data);
int ft_close_window_cross(void);
int ft_move(int key, t_data *data);
void ft_clear_image(t_data *data);

//GNL
char	*get_trash(char *temp);
char	*fill_use_buffer(int fd, char *temp, int i, char *buffer);
char	*get_newline(char *temp);
char	*get_next_line(int fd);
int		ft_strchr_gnl(char *s);
char	*ft_strjoin_gnl(char *temp, char *buff);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin2_gnl(char *s, char *temp, char *buff);

#endif
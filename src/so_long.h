/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:29:12 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/05 18:43:57 by parissachat      ###   ########.fr       */
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

typedef struct s_sprites
{
    void *player;
    void *wall;
    void *collectible;
    void *exit;
    void *empty;
    void *ennemies;
    void *background;
} t_sprites;

typedef struct s_int {
    int i;
    int j;
    int p;
    int e;
    int c;
    int x;
    int y;
}   t_int;

typedef struct s_data {
    void        *mlx;
    void        *win;
    char       **map;
    int		    heightmap;
	int		    widthmap;
	int		    fd;
    int         player_x;
    int         player_y;  
    t_sprites   sprites;
    int         n_collectibles;
    int         n_object_collected;
    int         n_object_path;
    int         moves;
    char        *moves_str;
    char        *obj_str;
    
} t_data;

//map
char    **ft_get_map(char *file_path, t_data *game);
char    *ft_read_and_join(int fd);
void    ft_free_map(char **map);
int     ft_check_map(t_data *game, char *file_name);
int     ft_check_object(t_data *game);
int     ft_check_wall_up_down(t_data *game);
int     ft_check_wall_left_right(t_data *game);
int     ft_check_rectangle(t_data *game);
int     ft_check_format_ber(char *file_name);
int     ft_check_tiles(t_data *game);
int     ft_check_valid_path(t_data *game);
void    ft_free_grid(char **grid, int n);
void    ft_dfs_algo(int x, int y, t_data *game, char **grid);

//so_long
void    ft_initiate_game(t_data *game);
void    ft_load_sprites(t_data *game);
void    ft_free_sprites(t_data *game);
void    ft_draw_game(t_data *game);
void    ft_draw_background(t_data *game);
int     ft_loop_hook(t_data *game);
void    ft_find_position_player_init(t_data *game);
int     ft_finish_game(t_data *game);
int     ft_killed_by_ennemies(t_data *game);
void    ft_count_move(int key, t_data *game);
void    ft_count_obj_collected(t_data *game, int new_x, int new_y);
void    ft_put_str_to_win(t_data *game);
void    ft_cleanup_game(t_data *game);


//event
int     ft_close_window_escp(int key, t_data *game);
int     ft_close_window_cross(t_data *game);
int     ft_move(int key, t_data *data);
void    ft_new_position_player(int key, int old_x, int old_y, t_data *game);

#endif
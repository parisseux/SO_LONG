/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:30:33 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/03 18:29:38 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_draw_background(t_data *game)
{
    int x;
    int y;
   
   y = 0;
   while (y < (game->heightmap + 2) * 32 )
   {
        x = 0;
        while (x < game->widthmap * 32)
        {
            mlx_put_image_to_window(game->mlx, game->win, game->sprites.background, x, y);
            x += 32;
        }
        y += 32;
   }
}
void ft_draw_game(t_data *game)
{
    t_int m;
    char tile;

    m.y = 0;
    while (game->map[m.y] != NULL)
   {
        m.x = 0;
        while (game->map[m.y][m.x])
        {
            tile = game->map[m.y][m.x];
            if (tile == '1')
                 mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall, m.x * 32, m.y * 32);
            else if (tile == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->sprites.player, m.x * 32 , m.y * 32);
            else if (tile == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit, m.x * 32, m.y * 32);
            else if (tile == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->sprites.collectible, m.x * 32, m.y * 32);
            else if (tile == 'X')
                 mlx_put_image_to_window(game->mlx, game->win, game->sprites.ennemies, m.x * 32, m.y * 32);
            m.x++;
        }
        m.y++;
    } 
}

void ft_find_position_player_init(t_data *game)
{
    t_int m;
    
    m.y = 0;
    while (game->map[m.y])
    {
        m.x = 0;
        while (game->map[m.y][m.x])
        {
            if (game->map[m.y][m.x] == 'P')
            {
                game->player_x = m.x * 32;
                game->player_y = m.y * 32;
            }
            m.x++;
        }
        m.y++;
    }
}
void    ft_load_sprites(t_data *game)
{
    int width;
    int height;
    
    width = 32;
    height = 32;
    game->sprites.player = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", &width, &height);
    game->sprites.collectible = mlx_xpm_file_to_image(game->mlx, "./sprites/collectibles.xpm", &width, &height);
    game->sprites.wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &width, &height);
    game->sprites.exit = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", &width, &height);
    game->sprites.ennemies = mlx_xpm_file_to_image(game->mlx, "./sprites/ennemies.xpm", &width, &height);
    game->sprites.background = mlx_xpm_file_to_image(game->mlx, "./sprites/background.xpm", &width, &height);
    ft_find_position_player_init(game);
}
void ft_initiate_game(t_data *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->widthmap * 32 , (game->heightmap + 1 + 1) * 32, "Mermaid World! <3");
   
    ft_load_sprites(game);
    ft_draw_background(game);
    mlx_hook(game->win, 2, 1L << 0, &ft_close_window_escp, game);
    mlx_hook(game->win, 17, 0, &ft_close_window_cross, game);
    mlx_key_hook(game->win, &ft_move, game);
    mlx_loop_hook(game->mlx, ft_loop_hook, game);
    mlx_loop(game->mlx);
}

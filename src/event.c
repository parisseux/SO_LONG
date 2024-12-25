/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:50:40 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/22 21:36:46 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int ft_close_window_escp(int key, t_data *game)
{
    if (key == 53)
    {
        mlx_destroy_window(game->mlx, game->win);
        ft_free_map(game->map);
        ft_free_sprites(game);
        free(game);
        exit(0);
    }
    return (0);
}

int ft_close_window_cross(t_data *game)
{
    mlx_destroy_window(game->mlx, game->win);
    ft_free_map(game->map);
    ft_free_sprites(game);
    free(game);
    exit(0);
}

int ft_move(int key, t_data *game)
{
    if (key == 0)
        game->player_x -= 50;
    else if (key == 1)
        game->player_y += 50;
    else if (key == 2)
        game->player_x += 50;
    else if (key == 13)
        game->player_y -= 50;
    ft_draw_game(game);
    return(0);
}

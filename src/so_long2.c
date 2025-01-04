/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:24:51 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/04 13:12:58 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_loop_hook(t_data *game)
{
    ft_draw_game(game);
    return (0);
}
int ft_finish_game(t_data *game)
{  
    mlx_destroy_window(game->mlx, game->win);
    ft_free_map(game->map);
    ft_free_sprites(game);
    free(game);
    ft_printf("Woohoo! The mermaid made it to her castle! All thanks to YOU!.\n");
    exit (0);
}

int ft_killed_by_ennemies(t_data *game)
{
    mlx_destroy_window(game->mlx, game->win);
    ft_free_map(game->map);
    ft_free_sprites(game);
    free(game);
    ft_printf("GAME OVER! The shark got a tasty mermaid snack...\nBetter luck next time. The ocean cries for vengeance.\n");
    exit (0);
}

void ft_count_move(int key, t_data *game)
{
    char *num;

    if (key == 0 || key == 1 || key == 2 || key == 13)
    {   
        game->moves++;
        num = ft_itoa(game->moves);
        mlx_put_image_to_window(game->mlx, game->win, game->sprites.background, (game->widthmap / 2) * 32, (game->heightmap + 1) * 32);
        mlx_string_put(game->mlx, game->win, (game->widthmap / 2) * 32, (game->heightmap + 1.5) * 32 , 0x000000, num);
        free(num);
    }   
}

void ft_count_obj_collected(t_data *game, int new_x, int new_y)
{
    char *obj_c;
    char *obj_t;
    char *str;
    
    game->n_object_collected++;
    if (game->n_object_collected == game->n_collectibles)
        mlx_string_put(game->mlx, game->win, 1, (game->heightmap + 1.5) * 32 , 0x000000, "Go Home, Mermaid!");
    game->map[new_y][new_x] = 'P';
    obj_c = ft_itoa(game->n_object_collected);
    obj_t = ft_itoa(game->n_collectibles);
    str = ft_strdup(obj_c);
    str = ft_strjoin(str, " / ");
    str = ft_strjoin(str, obj_t);
    free(obj_c);
    free(obj_t);
    mlx_put_image_to_window(game->mlx, game->win, game->sprites.background, (game->widthmap - 2) * 32, (game->heightmap + 1) * 32);
    mlx_string_put(game->mlx, game->win, (game->widthmap - 2) * 32, (game->heightmap + 1.5) * 32 , 0x000000, str);
    free(str);
}

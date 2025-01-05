/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:24:51 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/05 18:58:29 by parissachat      ###   ########.fr       */
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
    ft_cleanup_game(game);
    ft_printf("Woohoo! The mermaid made it to her castle! All thanks to YOU!\n");
    exit(0);
}

int ft_killed_by_ennemies(t_data *game)
{
    ft_cleanup_game(game);
    ft_printf("GAME OVER! The shark got a tasty mermaid snack...\n");
    ft_printf("Better luck next time. The ocean cries for vengeance.\n");
    exit(0);
}

void ft_count_move(int key, t_data *game)
{
    if (key == 0 || key == 1 || key == 2 || key == 13)
    {   
        game->moves++;
        game->moves_str = ft_itoa(game->moves);
    }
}

void ft_count_obj_collected(t_data *game, int new_x, int new_y)
{
    char *obj_c;
    char *obj_t;
    char *temp;
    
    game->n_object_collected++;
    game->map[new_y][new_x] = 'P';
    obj_c = ft_itoa(game->n_object_collected);
    obj_t = ft_itoa(game->n_collectibles);
    temp = ft_strjoin(obj_c, " / ");
    free(obj_c);
    game->obj_str = ft_strjoin(temp, obj_t);
    free(temp);
    free(obj_t);
}

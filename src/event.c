/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:50:40 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/06 17:13:58 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window_escp(int key, t_data *game)
{
	if (key == 53)
	{
		ft_cleanup_game(game);
		ft_printf("Wow, you quit?\n");
		ft_printf("Guess you'll never know what happens next... looser.\n");
		exit(0);
	}
	return (0);
}

int	ft_close_window_cross(t_data *game)
{
	ft_cleanup_game(game);
	ft_printf("Wow, you quit?\n");
	ft_printf("Guess you'll never know what happens next... looser.\n");
	exit (0);
}

void	ft_new_position_player(int key, int old_x, int old_y, t_data *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x / 32;
	new_y = game->player_y / 32;
	ft_count_move(key, game);
	game->map[old_y][old_x] = '0';
	if (game->map[new_y][new_x] == '0')
		game->map[new_y][new_x] = 'P';
	else if (game->map[new_y][new_x] == 'C')
		ft_count_obj_collected(game, new_x, new_y);
	else if (game->map[new_y][new_x] == 'E'
			&& game->n_collectibles == game->n_object_collected)
		ft_finish_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.background,
		old_x * 32, old_y * 32);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.player,
		game->player_x, game->player_y);
	ft_put_str_to_win(game);
}

int	ft_move(int key, t_data *game)
{
	int	old_x;
	int	old_y;

	old_x = game->player_x / 32;
	old_y = game->player_y / 32;
	if (key == 0)
		game->player_x -= 32;
	else if (key == 1)
		game->player_y += 32;
	else if (key == 2)
		game->player_x += 32;
	else if (key == 13)
		game->player_y -= 32;
	else 
		return (0);
	if (game->map[game->player_y / 32][game->player_x / 32] == '1'
			|| (game->map[game->player_y / 32][game->player_x / 32] == 'E'
			&& game->n_collectibles != game->n_object_collected))
	{
		game->player_x = old_x * 32;
		game->player_y = old_y * 32;
		return (0);
	}
	else if (game->map[game->player_y / 32][game->player_x / 32] == 'X')
		ft_killed_by_ennemies(game);
	ft_new_position_player(key, old_x, old_y, game);
	return (0);
}

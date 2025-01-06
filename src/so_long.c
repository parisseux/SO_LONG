/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:30:33 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/06 15:06:24 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_background(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (game->heightmap + 2) * 32)
	{
		x = 0;
		while (x < game->widthmap * 32)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->sprites.background, x, y);
			x += 32;
		}
		y += 32;
	}
}

void	ft_draw_game(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_draw_tiles(game, x, y);
			x++;
		}
		y++;
	}
}

void	ft_find_position_player_init(t_data *game)
{
	t_int	m;

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
				return ;
			}
			m.x++;
		}
		m.y++;
	}
}

void	ft_load_sprites(t_data *game)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	game->sprites.player = mlx_xpm_file_to_image(game->mlx, "./sp/player.xpm",
			&width, &height);
	game->sprites.collectible = mlx_xpm_file_to_image(game->mlx, "./sp/col.xpm",
			&width, &height);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, "./sp/wall.xpm",
			&width, &height);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, "./sp/exit.xpm",
			&width, &height);
	game->sprites.ennemies = mlx_xpm_file_to_image(game->mlx, "./sp/en.xpm",
			&width, &height);
	game->sprites.background = mlx_xpm_file_to_image(game->mlx, "./sp/bg.xpm",
			&width, &height);
}

void	ft_initiate_game(t_data *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->widthmap * 32,
			(game->heightmap + 1 + 1) * 32, "Mermaid World! <3");
	ft_load_sprites(game);
	ft_draw_background(game);
	mlx_hook(game->win, 2, 1L << 0, &ft_close_window_escp, game);
	mlx_hook(game->win, 17, 0, &ft_close_window_cross, game);
	mlx_key_hook(game->win, &ft_move, game);
	mlx_loop_hook(game->mlx, ft_loop_hook, game);
	mlx_loop(game->mlx);
}

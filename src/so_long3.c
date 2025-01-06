/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:56:56 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/06 15:10:52 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_str_to_win(t_data *game)
{
	int		i;
	char	*obj_t;

	i = 0;
	while (i < game->widthmap * 32)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.background, i, (game->heightmap + 1) * 32);
		i += 32;
	}
	if (game->n_object_collected == game->n_collectibles)
		mlx_string_put(game->mlx, game->win, 1, (game->heightmap + 1.5) * 32,
			0x000000, "Go Home!");
	else
		mlx_string_put(game->mlx, game->win, 1, (game->heightmap + 1.5) * 32,
			0x000000, "Collect the shell!");
	obj_t = ft_itoa(game->n_collectibles);
	if (game->n_object_collected == 0)
	{
		if (game->obj_str)
			free(game->obj_str);
		game->obj_str = ft_strjoin("0 / ", obj_t);
		free(obj_t);
	}
	ft_put_str_to_win2(game);
}

void	ft_put_str_to_win2(t_data *game)
{
	mlx_string_put(game->mlx, game->win, (game->widthmap - 2) * 32,
		(game->heightmap + 1.5) * 32, 0x000000, game->obj_str);
	mlx_string_put(game->mlx, game->win, (game->widthmap / 2) * 32,
		(game->heightmap + 1.5) * 32, 0x000000, game->moves_str);
}

void	ft_draw_tiles(t_data *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.wall, x * 32, y * 32);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.player, x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.exit, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.collectible, x * 32, y * 32);
	else if (game->map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.ennemies, x * 32, y * 32);
}

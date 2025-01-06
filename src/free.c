/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:44:59 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/06 14:24:59 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_sprites(t_data *game)
{
	if (game->sprites.player)
		mlx_destroy_image(game->mlx, game->sprites.player);
	if (game->sprites.collectible)
		mlx_destroy_image(game->mlx, game->sprites.collectible);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->sprites.ennemies)
		mlx_destroy_image(game->mlx, game->sprites.ennemies);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_grid(char **grid, int n)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < n)
	{
		if (grid[i])
			free(grid[i]);
		i++;
	}
	free(grid);
}

void	ft_cleanup_game(t_data *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		ft_free_map(game->map);
	ft_free_sprites(game);
	free(game);
}

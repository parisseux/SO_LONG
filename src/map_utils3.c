/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:21:40 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/03 18:29:07 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **create_checker_grid(t_data *game)
{
    char **grid;
    int i;
    int j;

    grid = malloc(game->heightmap * sizeof(char *));
    if (!grid)
        return (NULL);
    i = 0;
    while (i < game->heightmap) 
    {
        grid[i] = malloc(game->widthmap * sizeof(char));
        if (!grid[i])
        {
            ft_free_grid(grid, i);
            return (NULL);
        }
        j = 0;
        while (j < game->widthmap)
        {
            grid[i][j] = 'F';
            j++;
        }
        i++;
    }
    return (grid);
}
void ft_dfs_algo(int x, int y, t_data *game, char **grid)
{
    if (x < 0 || x >= game->widthmap || y < 0 || y >= game->heightmap) 
        return ;
    if (game->n_object_collected == (game->n_collectibles + 1))
        return ;
    if (game->map[y][x] == '1' || grid[y][x] == 'T')
        return ;
    grid[y][x] = 'T';
    if (game->map[y][x] == 'C' || game->map[y][x] == 'E')
        game->n_object_path++;
        
    ft_dfs_algo(x - 1, y, game, grid);
    ft_dfs_algo(x + 1, y, game, grid);
    ft_dfs_algo(x, y - 1, game, grid);
    ft_dfs_algo(x, y + 1, game, grid);
}
int ft_check_valid_path(t_data *game)
{
    char **grid;
    int x;
    int y;

    ft_find_position_player_init(game);
    x = game->player_x;
    y = game->player_y;
    grid = create_checker_grid(game);
    if (!grid)
    {
        return (0);
    }
    ft_dfs_algo(x / 32, y / 32, game, grid);
    ft_free_grid(grid, game->heightmap);
    if (game->n_object_path == (game->n_collectibles + 1))
        return (1);
    else
        return (0);
}

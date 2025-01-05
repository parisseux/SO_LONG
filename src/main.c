/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:16:39 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/05 18:45:03 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_data *game;

    if (ac != 2)
    {
        ft_printf("Usage: ./so_long ./map_path/map.ber\n");
        return (1);
    }
    game = malloc(sizeof(t_data));
    if (!game)
        return(1);
    ft_bzero(game, sizeof(t_data));
    game->map = ft_get_map(av[1], game);
    if (ft_check_map(game, av[1]) == 0)
    {
        ft_printf("Error: Invalid map.\n");
        ft_cleanup_game(game);
        return (1);
    }
    ft_initiate_game(game);
    ft_cleanup_game(game);
    return (0);
}

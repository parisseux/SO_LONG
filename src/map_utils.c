/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:26:16 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/03 18:28:47 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_rectangle(t_data *game)
{
    t_int x;

    x.i = 0;
    while (x.i <= game->heightmap)
    {
        if (ft_strlen(game->map[x.i]) != game->widthmap)
            return (0);
        x.i++;
    }
    return (1);
}

int ft_check_map(t_data *game, char *file_name)
{
    t_int x;

    x.i = 0;
    while (game->map[x.i])
        x.i++;
    game->heightmap = x.i - 1;
    game->widthmap = ft_strlen(game->map[0]);
    if (ft_check_format_ber(file_name) == 0)
        return (0);
    if (ft_check_object(game) == 0)
        return (0);
    if (ft_check_wall_up_down(game) == 0)
        return (0);
    if (ft_check_wall_left_right(game) == 0)
        return (0);
    if (ft_check_rectangle(game) == 0)
        return (0);
    if (ft_check_tiles(game) == 0)
        return (0);
    if (ft_check_valid_path(game) == 0)
        return (0);
    return (1);
}
char *ft_read_and_join(int fd)
{
    char *line;
    char *map_temp;
    char *temp;
    
    map_temp = NULL;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (map_temp == NULL)
            map_temp = ft_strdup(line);
        else
        {
            temp = map_temp;
            map_temp = ft_strjoin(map_temp, line);
            free(temp);
        } 
        free(line);
    }
    return (map_temp);
}

char **ft_get_map(char *file_path, t_data *game)
{
    char *map_temp;

    game->fd = open(file_path, O_RDONLY);
    if (game->fd < 0)
        exit (1);
    map_temp = ft_read_and_join(game->fd);
    close(game->fd);
    game->map = ft_split(map_temp, '\n');
    free(map_temp);
    return (game->map);
}


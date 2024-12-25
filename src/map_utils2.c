/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:27:18 by parissachat       #+#    #+#             */
/*   Updated: 2024/12/18 15:51:24 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_object(t_data *game)
{
   t_int x;
    
    x.i = 0;
    x.p = 0;
    x.e = 0;
    x.c = 0;
    while (game->map[x.i])
    {
        x.j = 0;
        while (game->map[x.i][x.j])
        {
            if (game->map[x.i][x.j] == 'P')
                x.p++;
            else if (game->map[x.i][x.j] == 'E')
                x.e++;
            else if (game->map[x.i][x.j] == 'C')
                x.c++;
            x.j++;
        }
        x.i++;
    }
    if (x.c >= 1 && x.e == 1 && x.p == 1)
        return (1);
    return (0);
}

int ft_check_wall_up_down(t_data *game)
{
    int j;
    
    j = 0;
    while (game->map[0][j] )
    {
        if (game->map[0][j] != '1')
            return (0);
        j++;
    }
    j = 0;
    while (game->map[game->heightmap][j])
    {
        if (game->map[game->heightmap][j] != '1')
            return (0);
        j++;
    }
   return (1); 
}

int ft_check_wall_left_right(t_data *game)
{
    int i;

    i = 1;
    while (i < game->heightmap)
    {
        if (game->map[i][0] != '1')
            return (0);
        if (game->map[i][game->widthmap -1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int ft_check_format_ber(char *file_name)
{
    char *ext;

    ext = ft_strrchr(file_name, '.');
    if (!ext || ext == file_name)
        return (0);
    if (ft_strncmp(ext, ".ber", 5) != 0)
        return (0);
    return (1);
}

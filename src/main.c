/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:16:39 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/09 14:28:06 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_printf("Usage: ./so_long ./map_path/map.ber\n");
        return (1);
    }
    if (ft_check_map(av[1] == 0))
    {
        ft_printf("Error: Invalid map.\n");
        return (1);
    }
    int fd = open(av[1], O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line: %s \n", line);
        free(line);
    }
    close(fd);
    // if (ft_check_map(av[1] == 0))
    // {
    //     ft_printf("Error: Invalid map.\n");
    //     return (1);
    // }
}
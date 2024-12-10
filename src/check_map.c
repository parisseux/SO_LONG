/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:26:16 by pchatagn          #+#    #+#             */
/*   Updated: 2024/12/09 16:01:34 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_count_lines(char *av)
{
    int fd;
    int n_lines;
    char c;
    int r;
    
    fd = open(av, 0_RDONLY);
    if (!fd)
        return (-1);
    n_lines = 1;
    while (1)
    {
        r = read(fd, &c, 1);
        if (r == 0)
            break ;
        if (r < 0)
            break ;
        if (c == '\n')
            n_lines++;
    }
    close(fd);
    return (n_lines);
}

char    **ft_alloc_map(char *av)
{
    char **map;
    int n_lines;

    n_lines = ft_count_lines(av);
    if (n_lines < 1)
        return (NULL);
    map = (char **)malloc(sizeof(char *) * (n_lines + 1));
    if (!map)
        return (NULL);
    return (map);
}
int ft_check_map(char av)
{
    int fd;
    int i;
    char **map;

    map = ft_alloc_map(av);
    if (!map)
        return (NULL);
    fd = open(&av, O_RDONLY);
    i = 0;
    while (get_next_line(fd) != NULL)
    {
        map = split()
    }
    close(fd);
    if (ft_check_len_map() == 0)
        return (0); 

    if (ft_check_E_P_C() == 0)
        return (0);

    if (ft_check_walls() == 0)
        return (0);

    return (1);
}


{
    fd = open(&av, O_RDONLY);
    while (1)
    {
        r = read(fd, &c, 1);
        if (r < 1)
            
    }

    
}
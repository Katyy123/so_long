/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:35:56 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/01 17:53:17 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int valid_file(int argc, char *file)
{
    if (argc == 1)
        return (error("there is no map file"));
    if (argc > 2)
        print_warning("only the first file will be used");
    if (!ft_strend_cmp(file, ".ber"))
        return (error("map should be a .ber file"));
    return (1);
}

int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;	

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 0;
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
            break;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
    if (linecount != 0)
        linecount++;
	close(fd);
	return (linecount);
}

char	**read_map(char *file)
{
	char	**map;
	int		line_count;
    int     fd;
    int     i;

	line_count = file_linecount(file);
    if (line_count <= 0)
		return (null_error("the file may not exist.\n\nChoose one of theese map files:\n maps/map1.ber  maps/map2.ber"));
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (null_error("malloc failure on read_map()"));
    fd = open(file, O_RDONLY);
    i = 0;
    while (i < line_count)
	{
        get_next_line(fd, &map[i]);//ogni stringa map[i] viene allocata in gnl
        i++;
	}
    map[i] = NULL;
    close(fd);
	return (map);
}

char  **map_parse(char *file)//poi rimettere t_tile, se lo userò, e game come parametro
{
    char    **map;
    //t_tile  **tile_map;
    
    map = read_map(file);
    if (!map)
        return (NULL);
    if (valid_map(map) == FALSE)
    {
        ft_free_chartable(map);
        return (NULL);
    }
    //tile_map = gen_tilemap(map, game);
    //ft_free_chartable(map);
    //if (!tile_map)
        //return(NULL);
    //return (tile_map);
    return (map);
}

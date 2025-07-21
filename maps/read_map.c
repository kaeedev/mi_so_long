/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:01:49 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/21 17:31:29 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//funcion para calcular el numero de filas del mapa
int	game_width(char *line, t_game *game)
{
	int	len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len --;
	if (game->map_width == 0)
		game->map_width = len;
	else if (game->map_width != len)
		return (0);
	return (1);
}

//funcion para leer las lineas del archivo
t_list	*read_lines(int fd, t_game *game)
{
	char	*line;
	t_list	*map_list;

	map_list = NULL;
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!game_width(line, game))
		{
			free(line);
			ft_lstclear(&map_list, free);
			ft_error(4);
		}
		ft_lstadd_back(&map_list, ft_lstnew(line));
		game->map_height++;
	}
	return (map_list);
}
//funcion que convierte de lista a array de strings y elimina saltos de linea de cada linea
void	convert_list_to_array(t_list *map_list, t_game *game)
{
	int	i;
	t_list	*current;

	game->map = (char **)ft_calloc(game->map_height + 1, sizeof(char *));
	if (!game->map)
		ft_error(6);
	i = 0;
	current = map_list;
	while (current)
	{
		game->map[i] = ft_strtrim(current->content, "\n");
		if (!game->map[i])
		{
			while (i > 0)
				free(game->map[--i]);
			free(game->map);
			ft_error(6);
		}
		current = current->next;
		i ++;
	}
}

//funcion para leer y procesar el mapa
void	read_map_file(const char *filepath, t_game *game)
{
	int	fd;
	t_list	*map_list;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	map_list = read_lines(fd, game);
	close(fd);
	if (!map_list)
		ft_error(5);
	convert_list_to_array(map_list, game);
	ft_lstclear(&map_list, free);
}

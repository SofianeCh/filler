/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 04:32:12 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/19 15:09:01 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

void			ft_free_maps(t_maps *map)
{
	int i;

	i = 0;
	while (map->plateau[i] != '\0')
	{
		ft_strdel(&map->plateau[i]);
		i++;
	}
	free(map->plateau);
	i = 0;
	while (map->piece[i] != '\0')
	{
		ft_strdel(&map->piece[i]);
		i++;
	}
	i = 0;
	while (map->piece_r[i])
	{
		ft_strdel(&map->piece_r[i]);
		i++;
	}
	free(map->piece);
	free(map->piece_r);
}

int				ft_floodfill(t_maps *map, t_fix *fix, int x, int y)
{
	if (map->plateau[x][y] == 'F' || map->plateau[x][y] == fix->me - 32 ||
	map->plateau[x][y] == fix->me)
	{
		map->plateau[x][y] = 'F';
		if (map->plateau[x][y + 1] && (map->plateau[x][y + 1] == fix->me ||
			map->plateau[x][y + 1] == fix->me - 32))
			ft_floodfill(map, fix, x, y + 1);
		if (map->plateau[x + 1] && map->plateau[x + 1][y] &&
			(map->plateau[x + 1][y] == fix->me || map->plateau[x + 1][y] ==
				fix->me - 32))
			ft_floodfill(map, fix, x + 1, y);
		if (map->plateau[x][y - 1] && (map->plateau[x][y - 1] == fix->me ||
			map->plateau[x][y - 1] == fix->me - 32))
			ft_floodfill(map, fix, x, y - 1);
		if (map->plateau[x + 1] && map->plateau[x - 1][y] &&
			(map->plateau[x - 1][y] == fix->me ||
				map->plateau[x - 1][y] == fix->me - 32))
			ft_floodfill(map, fix, x - 1, y);
	}
	return (0);
}

int				read_tab(t_coord *crd, t_fix *fix)
{
	t_filler	filler;
	t_maps		map;

	ft_bzero(&filler, sizeof(filler));
	ft_bzero(&map, sizeof(map));
	ft_creates_maps(&filler, &map);
	map.piece ? filler.stars = ft_count_stars(map.piece) : 0;
	map.piece ? ft_fixmin(&map, &filler) : 0;
	!fix->stop ? check_pos(map.plateau, crd, fix) : 0;
	!fix->x_beg ? ft_initdata(fix, crd, &filler) : 0;
	if (!pos_valid(crd, &map, &filler, fix))
	{
		crd->x = 0;
		crd->y = 0;
	}
	fix->me == 'x' ? ft_strategy(&map, crd, &filler, fix) :
	ft_strategy2(&map, crd, &filler, fix);
	if (!pos_valid(crd, &map, &filler, fix))
	{
		ft_printf("%d %d\n", 0, 0);
		exit(1);
	}
	ft_printf("%d %d\n", crd->x - filler.min_y, crd->y - filler.min_x);
	ft_free_maps(&map);
	return (0);
}

int				main(void)
{
	static t_fix	fix;
	t_coord			crd;
	char			*line;

	line = NULL;
	ft_bzero(&crd, sizeof(crd));
	get_next_line(0, &line);
	fix.me = line[10] == '1' ? 'o' : 'x';
	fix.challenger = line[10] == '1' ? 'x' : 'o';
	while (1)
		read_tab(&crd, &fix);
	return (0);
}

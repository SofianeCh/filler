/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creamap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:22:29 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/18 18:46:35 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_creates_maps(t_filler *filler, t_maps *map)
{
	while ((get_next_line(0, &filler->line)) > 0)
	{
		filler->line[0] == 'P' && filler->line[1] == 'l' ?
		ft_beg_opt(map, filler, filler->line) : 0;
		if (filler->end)
		{
			map->plateau[filler->i] = filler->line;
			filler->i++;
			filler->end--;
		}
		filler->i && !filler->end ? map->plateau[filler->i] = 0 : 0;
		ft_beg_opp(map, filler, filler->line);
		if (filler->piece_x)
		{
			map->piece[filler->i_piece] = filler->line;
			filler->i_piece++;
			if (!filler->param)
				break ;
			filler->param--;
		}
		if (!filler->line)
			break ;
	}
	map->piece ? map->piece[filler->i_piece] = 0 : 0;
}

void			ft_get_minx(t_maps *map, t_filler *filler)
{
	int i;
	int k;

	i = 0;
	k = -1;
	if (map->piece)
		while (map->piece[i][++k] != '\0')
		{
			while (map->piece[++i] != '\0')
			{
				if (map->piece[i][k] != '.')
					break ;
			}
			if (i == filler->piece_x + 1)
				filler->min_x++;
			else
				break ;
			i = 0;
		}
}

void			ft_get_miny(t_maps *map, t_filler *filler)
{
	int i;
	int k;

	i = 0;
	k = -1;
	while (map->piece[++i] != '\0')
	{
		while (map->piece[i][++k] != '\0')
		{
			if (map->piece[i][k] != '.')
				break ;
		}
		if (k == filler->piece_y)
			filler->min_y++;
		else
			break ;
		k = -1;
	}
}

void			ft_cut_piece(t_maps *map, t_filler *f)
{
	int x;
	int y;
	int i;

	x = f->min_x;
	y = f->min_y + 1;
	i = 0;
	map->piece_r = malloc(sizeof(char*) * (f->piece_x + 1 - f->min_y));
	if (map->piece_r)
		while (i < f->piece_x - f->min_y)
		{
			map->piece_r[i] = ft_strdup(map->piece[y] + x);
			y++;
			i++;
		}
	if (map->piece_r)
		map->piece_r[i] = 0;
}

void			ft_fixmin(t_maps *map, t_filler *filler)
{
	ft_get_minx(map, filler);
	ft_get_miny(map, filler);
	ft_cut_piece(map, filler);
}

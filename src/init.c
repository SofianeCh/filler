/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:36:03 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/05 19:47:23 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_count_stars(char **piece)
{
	int stars;
	int i;
	int k;

	i = -1;
	stars = 0;
	while (piece[++i])
	{
		k = 0;
		while (piece[i][k])
		{
			if (piece[i][k] == '*')
				stars++;
			k++;
		}
	}
	return (stars);
}

void			ft_beg_opt(t_maps *map, t_filler *filler, char *line)
{
	filler->plateaux_x = ft_atoi(line + 8);
	filler->plateaux_y = ft_atoi(line + ft_intlen(filler->plateaux_x) + 8);
	map->plateau = malloc(sizeof(char*) * (filler->plateaux_x + 3));
	filler->end = filler->plateaux_x + 2;
}

void			ft_beg_opp(t_maps *map, t_filler *filler, char *line)
{
	if (line[0] == 'P' && line[1] == 'i')
	{
		filler->piece_x = ft_atoi(line + 6);
		filler->param = filler->piece_x;
		filler->piece_y = ft_atoi(line + 6 + ft_intlen(filler->piece_x));
	}
	if (filler->piece_x)
	{
		if (!map->piece)
			map->piece = malloc(sizeof(char*) * (filler->piece_x + 2));
	}
}

void			check_pos(char **plateau, t_coord *crd, t_fix *fix)
{
	int i;
	int k;

	i = 1;
	if (plateau)
		while (plateau[++i])
		{
			k = 3;
			while (plateau[i][k])
			{
				if (plateau[i][k] == fix->me - 32)
				{
					crd->x = i - 2;
					crd->y = k - 4;
					break ;
				}
				k++;
			}
		}
	fix->stop = 1;
}

void			ft_initdata(t_fix *fix, t_coord *crd, t_filler *filler)
{
	fix->x_beg = crd->x;
	fix->y_beg = crd->y;
	fix->middle_x = filler->plateaux_x / 2;
	fix->middle_y = filler->plateaux_y / 2;
}

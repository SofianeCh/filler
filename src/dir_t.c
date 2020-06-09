/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:48:17 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/15 02:53:09 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_dir_tl(t_maps *map, t_coord *crd, t_filler *filler, t_fix *fix)
{
	if (!pos_valid(crd, map, filler, fix))
	{
		crd->x = 0;
		crd->y = 0;
	}
	while (map->plateau && pos_valid(crd, map, filler, fix) == 0)
	{
		crd->x += 1;
		if (crd->x == filler->plateaux_x)
		{
			crd->x = 0;
			crd->y += 1;
		}
		if (crd->y == filler->plateaux_y && crd->x == filler->plateaux_x - 1)
			break ;
	}
}

void	ft_dir_tl2(t_maps *map, t_coord *crd, t_filler *filler, t_fix *fix)
{
	if (!pos_valid(crd, map, filler, fix))
	{
		crd->x = filler->plateaux_x / 2;
		crd->y = 0;
	}
	while (map->plateau && pos_valid(crd, map, filler, fix) == 0)
	{
		crd->x += 1;
		if (crd->x == filler->plateaux_x)
		{
			crd->x = filler->plateaux_x / 2;
			crd->y += 1;
		}
		if (crd->y == filler->plateaux_y && crd->x == filler->plateaux_x - 1)
			break ;
	}
}

void	ft_dir_tr(t_maps *map, t_coord *crd, t_filler *filler, t_fix *fix)
{
	if (!pos_valid(crd, map, filler, fix))
	{
		crd->x = 0;
		crd->y = filler->plateaux_y - 1;
	}
	while (map->plateau && pos_valid(crd, map, filler, fix) == 0)
	{
		crd->x += 1;
		if (crd->x == filler->plateaux_x)
		{
			crd->x = 0;
			crd->y -= 1;
		}
		if (crd->y == filler->plateaux_y && crd->x == filler->plateaux_x - 1)
			break ;
	}
}

void	ft_dir_tr2(t_maps *map, t_coord *crd, t_filler *filler, t_fix *fix)
{
	if (!pos_valid(crd, map, filler, fix))
	{
		crd->x = 0;
		crd->y = filler->plateaux_y - 1;
	}
	while (map->plateau && pos_valid(crd, map, filler, fix) == 0)
	{
		crd->x += 1;
		if (crd->x == filler->plateaux_x / 2)
		{
			crd->x = 0;
			crd->y -= 1;
		}
		if (crd->y == 0 && crd->x - filler->min_x >= 0)
			break ;
	}
}

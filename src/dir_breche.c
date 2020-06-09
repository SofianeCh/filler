/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_breche.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 20:33:56 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/05 20:37:58 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_dir_tl_breche(t_maps *map, t_coord *crd, t_filler *f, t_fix *fix)
{
	crd->x = 0;
	crd->y = 0;
	while (map->plateau && ft_breche_ok(crd, map, f, fix) == 0)
	{
		crd->x += 1;
		if (crd->x == f->plateaux_x)
		{
			crd->x = 0;
			crd->y += 1;
		}
		if (crd->y == f->plateaux_y && crd->x == f->plateaux_x - 1)
			break ;
	}
}

void	ft_dir_tr_breche(t_maps *map, t_coord *crd, t_filler *f, t_fix *fix)
{
	crd->x = 0;
	crd->y = f->plateaux_y - 1;
	while (map->plateau && ft_breche_ok(crd, map, f, fix) == 0)
	{
		crd->x += 1;
		if (crd->x == f->plateaux_x)
		{
			crd->x = 0;
			crd->y -= 1;
		}
		if (crd->y == 0 && crd->x - f->min_x >= 0)
			break ;
	}
}

void	ft_dir_ll_breche(t_maps *map, t_coord *crd, t_filler *f, t_fix *fix)
{
	crd->x = 0;
	crd->y = f->plateaux_y - 1;
	while (map->plateau && ft_breche_ok(crd, map, f, fix) == 0)
	{
		crd->x += 1;
		if (crd->x == f->plateaux_x)
		{
			crd->x = 0;
			crd->y -= 1;
		}
		if (crd->y == 0 && crd->x == f->plateaux_x - 1)
			break ;
	}
}

void	ft_dir_lr_breche(t_maps *map, t_coord *crd, t_filler *f, t_fix *fix)
{
	crd->x = f->plateaux_x - 1;
	crd->y = f->plateaux_y;
	while (map->plateau && ft_breche_ok(crd, map, f, fix) == 0)
	{
		crd->x -= 1;
		if (crd->x == 0)
		{
			crd->x = f->plateaux_x - 1;
			crd->y -= 1;
		}
		if (crd->y == 0 && crd->x == f->plateaux_x - 1)
			break ;
	}
}

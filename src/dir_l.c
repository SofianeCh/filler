/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:53:27 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/15 03:09:17 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_dir_ll2_breche(t_maps *map, t_coord *crd, t_filler *f, t_fix *fix)
{
	crd->x = f->plateaux_x - 1;
	crd->y = 0;
	while (map->plateau && ft_breche_ok(crd, map, f, fix) == 0)
	{
		crd->x -= 1;
		if (crd->x == 0)
		{
			crd->x = f->plateaux_x - 1;
			crd->y += 1;
		}
		if (crd->y == f->plateaux_y - 1 && crd->x == f->plateaux_x - 1)
			break ;
	}
}

void	ft_dir_ll2(t_maps *map, t_coord *crd, t_filler *f, t_fix *fix)
{
	crd->x = f->plateaux_x - 1;
	crd->y = 0;
	while (map->plateau && pos_valid(crd, map, f, fix) == 0)
	{
		crd->x -= 1;
		if (crd->x == f->plateaux_x / 2 - 2)
		{
			crd->x = f->plateaux_x - 1;
			crd->y += 1;
		}
		if (crd->y == f->plateaux_y - 1 && crd->x == f->plateaux_x - 1)
			break ;
	}
}

/*
**void	ft_dir_lr(t_maps *map, t_coord *crd, t_filler *filler, t_fix *fix)
**{
**	if (!pos_valid(crd, map, filler, fix))
**	{
**		crd->x = filler->plateaux_x - 1;
**		crd->y = filler->plateaux_y;
**	}
**	while (map->plateau && pos_valid(crd, map, filler, fix) == 0)
**	{
**		crd->x -= 1;
**		if (crd->x == 0)
**		{
**			crd->x = filler->plateaux_x - 1;
**			crd->y -= 1;
**		}
**		if (crd->y == 0 && crd->x == filler->plateaux_x - 1)
**			break ;
**	}
**}
*/

/*
**void	ft_dir_ll(t_maps *map, t_coord *crd, t_filler *filler, t_fix *fix)
**{
**	if (!pos_valid(crd, map, filler, fix))
**	{
**		crd->x = 0;
**		crd->y = filler->plateaux_y - 1;
**	}
**	while (map->plateau && pos_valid(crd, map, filler, fix) == 0)
**	{
**		crd->x += 1;
**		if (crd->x == filler->plateaux_x)
**		{
**			crd->x = 0;
**			crd->y -= 1;
**		}
**		if (crd->y == 0 && crd->x == filler->plateaux_x - 1)
**			break ;
**	}
**}
*/

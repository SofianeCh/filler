/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:11:05 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/15 02:55:55 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_strategy2(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix)
{
	if (!fix->phase1)
	{
		ft_floodfill(map, fix, fix->x_beg + 2, fix->y_beg + 4);
		ft_dir_lr_breche(map, crd, filler, fix);
		fix->border = check_border(map, filler, fix);
		if (fix->border)
			fix->phase1 = 1;
	}
	else if (!fix->phase2)
	{
		ft_floodfill(map, fix, fix->x_beg + 2, fix->y_beg + 4);
		ft_dir_ll2_breche(map, crd, filler, fix);
		if (check_border(map, filler, fix))
			fix->phase2 = 1;
	}
	else
		ft_dir_ll2(map, crd, filler, fix);
	if (!pos_valid(crd, map, filler, fix))
		ft_dir_tl(map, crd, filler, fix);
}

void			ft_strategy(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix)
{
	if (!fix->phase1)
	{
		ft_floodfill(map, fix, fix->x_beg + 2, fix->y_beg + 4);
		ft_dir_tl_breche(map, crd, filler, fix);
		fix->border = check_border(map, filler, fix);
		if (fix->border)
			fix->phase1 = 1;
	}
	else if (!fix->phase2)
	{
		ft_floodfill(map, fix, fix->x_beg + 2, fix->y_beg + 4);
		ft_dir_tr_breche(map, crd, filler, fix);
		if (check_border(map, filler, fix))
			fix->phase2 = 1;
	}
	else
		ft_dir_tr2(map, crd, filler, fix);
	if (!pos_valid(crd, map, filler, fix))
		ft_dir_tl(map, crd, filler, fix);
}

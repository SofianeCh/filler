/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:30:26 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/15 02:16:46 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_border(t_maps *map,
	t_filler *filler, t_fix *fix)
{
	int k;
	int i;

	i = -1;
	while (map->plateau[++i])
	{
		k = -1;
		while (map->plateau[i][++k])
		{
			if (i == 2)
				if (map->plateau[i][k] == 'F' && fix->border != 1)
					return (1);
			if (k == 4)
				if (map->plateau[i][k] == 'F' && fix->border != 2)
					return (2);
			if (k == filler->plateaux_y + 3)
				if (map->plateau[i][k] == 'F' && fix->border != 3)
					return (3);
			if (i == filler->plateaux_x + 1)
				if (map->plateau[i][k] == 'F' && fix->border != 4)
					return (4);
		}
	}
	return (0);
}

int	ft_isgoodb(t_maps *m, t_var *c, t_coord *crd, t_fix *fix)
{
	if (m->piece_r[c->i][c->k] && m->piece_r[c->i][c->k] == '*' &&
	m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == 'F')
		c->breche = 1;
	if (m->piece_r[c->i][c->k] && m->piece_r[c->i][c->k] == '*' &&
	m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] &&
	(m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == 'F' ||
	m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == fix->me ||
	m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == fix->me - 32))
		c->ok++;
	if ((c->ok > 1) || (m->piece_r[c->i][c->k] && m->piece_r[c->i][c->k] == '*'
	&& m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] &&
		(m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == fix->challenger ||
			m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] ==
			fix->challenger - 32)))
		return (1);
	if (m->piece_r[c->i][c->k] == '*')
		c->stars++;
	return (0);
}

int	ft_breche_ok(t_coord *crd, t_maps *m, t_filler *filler, t_fix *fix)
{
	t_var c;

	ft_bzero(&c, sizeof(c));
	if (m->piece_r && *m->piece_r)
		while (m->piece_r[c.i] &&
			m->plateau[crd->x + c.i + 2])
		{
			c.k = -1;
			while (m->piece_r[c.i][++c.k] &&
				m->plateau[crd->x + c.i + 2][crd->y + c.k + 4])
			{
				if (ft_isgoodb(m, &c, crd, fix))
					return (0);
				if (c.stars == filler->stars && c.breche == 1)
					return (1);
			}
			c.i++;
		}
	if (filler->piece_x + crd->x + 2 > filler->plateaux_x ||
		filler->piece_y + crd->y + 4 > filler->plateaux_y)
		return (0);
	return (c.breche ? 1 : 0);
}

int	ft_isgood(t_maps *m, t_var *c, t_coord *crd, t_fix *fix)
{
	if (m->piece_r[c->i][c->k] && m->piece_r[c->i][c->k] == '*' &&
	m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] &&
	(m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == fix->me ||
		m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == fix->me - 32 ||
		m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == 'F'))
		c->ok++;
	if ((c->ok > 1) || (m->piece_r[c->i][c->k] && m->piece_r[c->i][c->k] == '*'
	&& m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] &&
		(m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] == fix->challenger ||
			m->plateau[crd->x + c->i + 2][crd->y + c->k + 4] ==
			fix->challenger - 32)))
		return (1);
	return (0);
}

int	pos_valid(t_coord *crd, t_maps *m, t_filler *filler, t_fix *fix)
{
	t_var c;

	ft_bzero(&c, sizeof(c));
	if (m->piece_r && *m->piece_r)
		while (m->piece_r[c.i] && m->plateau[crd->x + c.i + 2] && (c.k = -1))
		{
			while (m->piece_r[c.i][++c.k] &&
				m->plateau[crd->x + c.i + 2][crd->y + c.k + 4])
			{
				if (ft_isgood(m, &c, crd, fix))
					return (0);
				(m->piece_r[c.i][c.k] == '*') && c.stars++;
				if (c.stars == filler->stars && c.ok == 1)
					return (1);
			}
			c.i++;
		}
	if (filler->piece_x + crd->x + 2 > filler->plateaux_x ||
		filler->piece_y + crd->y + 4 > filler->plateaux_y)
		return (0);
	return (c.ok ? 1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:21:23 by sofchami          #+#    #+#             */
/*   Updated: 2019/03/15 03:01:05 by sofchami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <fcntl.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_var
{
	int				i;
	int				k;
	int				ok;
	int				stars;
	int				breche;
}					t_var;

typedef struct		s_maps
{
	char			**plateau;
	char			**piece;
	char			**piece_r;
	int				x;
	int				y;
}					t_maps;

typedef struct		s_fix
{
	char			me;
	char			challenger;
	int				x_beg;
	int				y_beg;
	int				middle_x;
	int				middle_y;
	int				phase1;
	int				phase2;
	int				phase3;
	int				stop;
	int				border;
}					t_fix;

typedef struct		s_filler
{
	int				piece_x;
	int				piece_y;
	int				plateaux_x;
	int				plateaux_y;
	int				min_x;
	int				min_y;
	int				long_tab;
	int				param;
	int				i;
	int				end;
	int				stars;
	int				i_piece;
	char			*line;
}					t_filler;

void				ft_strategy2(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_strategy(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_cut_piece(t_maps *map, t_filler *filler);
void				ft_get_miny(t_maps *map, t_filler *filler);
void				ft_get_minx(t_maps *map, t_filler *filler);
void				ft_creates_maps(t_filler *filler, t_maps *map);
void				ft_beg_opt(t_maps *map, t_filler *filler, char *line);
void				ft_beg_opp(t_maps *map, t_filler *filler,
	char *line);
void				ft_fixmin(t_maps *map, t_filler *filler);

void				ft_dir_ll2_breche(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_tr_breche(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_tl_breche(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_lr_breche(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_ll_breche(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);

void				ft_dir_tl(t_maps *map, t_coord *crd, t_filler *filler,
	t_fix *fix);
void				ft_dir_tl2(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_tr2(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_tr(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_ll(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_lr(t_maps *map, t_coord *crd,
	t_filler *filler, t_fix *fix);
void				ft_dir_ll2(t_maps *map, t_coord *crd,
	t_filler *f, t_fix *fix);

void				ft_initdata(t_fix *fix, t_coord *crd, t_filler *filler);
void				check_pos(char **plateau, t_coord *crd,
	t_fix *fix);
int					ft_count_stars(char **piece);
int					ft_breche_ok(t_coord *crd,
	t_maps *m, t_filler *filler, t_fix *fix);
int					pos_valid(t_coord *crd, t_maps *m,
	t_filler *filler, t_fix *fix);
int					ft_floodfill(t_maps *map, t_fix *fix, int x, int y);
int					check_border(t_maps *map,
	t_filler *filler, t_fix *fix);
#endif

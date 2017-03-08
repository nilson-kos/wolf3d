/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:54:08 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/08 15:25:08 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "../libft/libft.h"

typedef struct		s_menu
{
	int				i;
	int				j;
	void			*img;
}					t_menu;

typedef struct		s_flag_menu
{
	int				pos;
}					t_flag_menu;

typedef struct		s_flag
{
	int				menu;
}					t_flag;

typedef struct	s_wf
{
	char				**lvl1;
	char				**lvl2;
	void				*mlx;
	void				*win;
	void				*img;
	int					w_size_x;
	int					w_size_y;
	struct s_menu		*menu;
	struct s_flag		flag;
	struct s_flag_menu	flmenu;
}				t_wf;

char	**ft_readfile(void);
t_wf	*ft_init_wf(void);
void	ft_menu(t_wf *wf);
t_wf	*download_image(t_wf *wf);
int		ft_zaloop_hook(t_wf *wf);

#endif

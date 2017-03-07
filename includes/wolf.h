/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:54:08 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/06 18:06:35 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

#include <math.h>
#include "mlx.h"
#include "../libft/libft.h"

typedef struct	s_wf
{
	void			*mlx;
	void			*win;
	void			*img;
	int			w_size_x;
	int			w_size_y;
}				t_wf;

char	**ft_readfile(void);
t_wf	*ft_init_wf(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_wf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:41:00 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/06 18:08:39 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wf		*ft_init_wf(void)
{
	t_wf	*wf;

	wf = (t_wf *)malloc(sizeof(t_wf));
	wf->w_size_x = 800;
	wf->w_size_y = 800;
	wf->mlx = mlx_init();
	wf->win = mlx_new_window(wf->mlx, wf->w_size_x, wf->w_size_y, "wolf by LC");
	return (wf);
}

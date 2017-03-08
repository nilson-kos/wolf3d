/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_wf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:41:00 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/07 20:33:52 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wf		*ft_init_flag_menu(t_wf *wf)
{
	wf->flmenu.pos = 0;
	return (wf);
}

t_wf		*ft_init_flag(t_wf *wf)
{
	wf->flag.menu = 0;
	return (wf);
}

t_wf		*ft_init_wf(void)
{
	t_wf	*wf;

	wf = (t_wf *)malloc(sizeof(t_wf));
	wf->w_size_x = 800;
	wf->w_size_y = 800;
	wf->mlx = mlx_init();
	wf->win = mlx_new_window(wf->mlx, wf->w_size_x, wf->w_size_y, "wolf by LC");
	wf->img = mlx_new_image(wf->mlx, wf->w_size_x, wf->w_size_y);
	wf = ft_init_flag(wf);
	wf = ft_init_flag_menu(wf);
	wf = download_image(wf);
	return (wf);
}

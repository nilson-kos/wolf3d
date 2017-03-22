/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:17:26 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/22 20:54:01 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_menu(t_wf *wf)
{
	if (wf->flmenu.pos == 0)
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[0].img, 0, 0);
	if (wf->flmenu.pos == 1)
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[1].img, 0, 0);
	if (wf->flmenu.pos == 2)
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[2].img, 0, 0);
}

void	ft_menu2(t_wf *wf)
{
	if (wf->flmenu.pos == 0)
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[3].img, 0, 0);
	if (wf->flmenu.pos == 1)
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[4].img, 0, 0);
	if (wf->flmenu.pos == 2)
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[5].img, 0, 0);
	if (wf->flmenu.pos == 3)
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[6].img, 0, 0);
}

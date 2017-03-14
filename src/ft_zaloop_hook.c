/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zaloop_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:28:20 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/14 18:58:40 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		button_release_menu(int kcode, t_wf *wf)
{
	if (kcode == 36 && wf->flmenu.pos == 1)
		exit(0);
	if (kcode == 36 && wf->flmenu.pos == 0)
		wf->flag.menu = 1;
	if (kcode == 125)
		wf->flmenu.pos += 1;
	if (kcode == 126)
		wf->flmenu.pos -= 1;
	if (wf->flmenu.pos == -1)
		wf->flmenu.pos = 1;
	if (wf->flmenu.pos == 2)
		wf->flmenu.pos = 0;
	return (0);
}

int		button_press_game(int kcode, t_wf *wf)
{
	if (kcode == 53)
	{
		wf->flag.menu = 0;
		ft_menu(wf);
	}
	return (0);
}

int		ft_zaloop_hook(t_wf *wf)
{
	if (wf->flag.menu == 0)
	{
		ft_menu(wf);
		mlx_hook(wf->win, 3, 2, button_release_menu, wf);
	}
	else
	{
		printf("GO?\n");
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[2].img, 0, 0);
		mlx_hook(wf->win, 2, 1, button_press_game, wf);
		raycasting(wf);
	}
	return (0);
}

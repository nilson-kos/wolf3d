/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:05:51 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/22 20:47:35 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		button_release_menu2(int kcode, t_wf *wf)
{
	if (kcode == 36 && wf->flmenu.pos == 3)
		exit(0);
	if (kcode == 36 && wf->flmenu.pos == 0)
	{
		wf = ft_init_flag(wf);
		wf->flmenu.menu = 1;
	}
	(kcode == 125) ? wf->flmenu.pos += 1 : 666;
	(kcode == 126) ? wf->flmenu.pos -= 1 : 666;
	(wf->flmenu.pos == -1) ? wf->flmenu.pos = 3 : 666;
	(wf->flmenu.pos == 4) ? wf->flmenu.pos = 0 : 666;
	return (0);
}

int		button_press_game(int kcode, t_wf *wf)
{
	(kcode == 53) ? wf->flmenu.menu = 2 : 777;
	(kcode == 14) ? action(wf) : 666;
	(kcode == 13) ? wf->flag.fl_frw = 1 : 999;
	(kcode == 1) ? wf->flag.fl_back = 1 : 888;
	(kcode == 0) ? wf->flag.fl_left = 1 : 888;
	(kcode == 2) ? wf->flag.fl_rght = 1 : 888;

	return (0);
}

int		button_release_game(int kcode, t_wf *wf)
{
	(kcode == 13) ? wf->flag.fl_frw = 0 : 999;
	(kcode == 1) ? wf->flag.fl_back = 0 : 888;
	(kcode == 0) ? wf->flag.fl_left = 0 : 888;
	(kcode == 2) ? wf->flag.fl_rght = 0 : 888;
	return (0);
}

int		button_release_menu(int kcode, t_wf *wf)
{
	if (kcode == 36 && wf->flmenu.pos == 2)
		exit(0);
	if (kcode == 36 && wf->flmenu.pos == 0)
	{
		wf = ft_init_flag(wf);
		wf->flmenu.menu = 1;
	}
	(kcode == 125) ? wf->flmenu.pos += 1 : 666;
	(kcode == 126) ? wf->flmenu.pos -= 1 : 666;
	(wf->flmenu.pos == -1) ? wf->flmenu.pos = 2 : 666;
	(wf->flmenu.pos == 3) ? wf->flmenu.pos = 0 : 666;
	return (0);
}

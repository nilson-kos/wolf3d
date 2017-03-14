/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:12:29 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/13 14:21:20 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wf	*download_menu(t_wf *wf)
{
	//dva a ne tri
	wf->menu = (t_menu *)malloc(sizeof(t_menu) * 3);
	wf->menu[0].img = mlx_xpm_file_to_image(wf->mlx,
		"img/menu1/newgamemenu.XPM", &wf->menu[0].i, &wf->menu[0].j);
	if (wf->menu[0].img == 0)
		perror("img/menu1/newgamemenu.XPM");
	wf->menu[1].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu1/quitmenu.XPM", &wf->menu[1].i, &wf->menu[1].j);
	if (wf->menu[0].img == 0)
		perror("img/menu1/newgamemenu.XPM");
	if (wf->menu[1].img == 0)
		perror("img/menu1/quitmenu.XPM");
	return (wf);
}

t_wf	*download_test(t_wf *wf)
{
	wf->menu[2].img = mlx_xpm_file_to_image(wf->mlx,
		"img/tset.XPM", &wf->menu[2].i, &wf->menu[2].j);
	if (wf->menu[2].img == 0)
			perror("img/tset.XPM");
	return (wf);
}

t_wf	*download_image(t_wf *wf)
{
	wf = download_menu(wf);
	wf = download_test(wf);
	return (wf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_norme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:13:41 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/25 16:19:15 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	for_norm(char *buf, char **line, t_lion *lst)
{
	char	*n;
	char	*zap;

	n = ft_strchr(buf, '\n');
	zap = ft_strsub(buf, 0, n - buf);
	*line = join_free(*line, zap);
	ft_strdel(&(lst->s));
	lst->s = ft_strdup(buf + (n - buf) + 1);
	ft_strdel(&zap);
	ft_strdel(&buf);
}

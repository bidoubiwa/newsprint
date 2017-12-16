/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:48:13 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 16:31:16 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

char		*ft_plus(t_chain *elem)
{
	char	*show;
	char	*new;
	size_t	len_src;

	show = elem->show;
	len_src = ft_strlen(show);
	if (ft_is_decimal(elem->conv))
	{
		if (show[0] != '-')
		{
			if (!(new = ft_strnew(len_src + 1)))
				return (show);
			new[0] = '+';
			new = ft_strncat(new, show, len_src);
			free(show);
			return (new);
		}
	}
	return (show);
}

static char	*ft_0x_hexa(char *show)
{
	int		y;
	int		i;
	char	*new;

	i = 0;
	y = 0;
	if (!(new = ft_strnew(ft_strlen(show) + 2)))
		return (NULL);
	new[i++] = '0';
	new[i++] = 'x';
	while (show[y])
		new[i++] = show[y++];
	free(show);
	return (new);
}

static char	*ft_0_octal(char *show)
{
	char	*new;
	int		y;
	int		i;

	i = 0;
	y = 0;
	if (!(new = ft_strnew(ft_strlen(show) + 1)))
		return (NULL);
	new[i++] = '0';
	while (show[y])
		new[i++] = show[y++];
	free(show);
	return (new);
}

char		*ft_hash(t_chain *elem)
{
	char	c;

	c = elem->conv;
	if (ft_tolower(c) == 'x' || elem->conv == 'p')
		return (ft_0x_hexa(elem->show));
	else if (c == 'o')
		return (ft_0_octal(elem->show));
	return (elem->show);
}

char		*ft_maj(t_chain *elem)
{
	int		i;
	char	*show;

	show = elem->show;
	i = 0;
	if (ft_need_toupper(elem->conv))
	{
		while (show[i])
		{
			show[i] = ft_toupper(show[i]);
			i++;
		}
	}
	return (show);
}

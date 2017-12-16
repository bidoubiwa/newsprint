/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:28:03 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 17:01:52 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

static char	*ft_prec_on_str(t_chain *elem)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (elem->prec < ft_strlen(elem->show))
	{
		i = 0;
		len = elem->prec;
		if (!(new = ft_strnew(len)))
			return (NULL);
		while (i < len)
		{
			new[i] = elem->show[i];
			i++;
		}
		return (new);
	}
	return (elem->show);
}

static char	*ft_prec_on_integer(t_chain *elem)
{
	char	*tmp;
	char	*new;
	long	i;
	long	y;
	size_t	len_src;

	i = 0;
	y = 0;
	tmp = ft_start_digit(elem->show);
	len_src = ft_strlen(tmp);
	if (elem->prec > len_src)
	{
		if (!(new = ft_strnew(elem->prec + (tmp - elem->show))))
			return (elem->show);
		while (i < (tmp - elem->show))
			new[i++] = elem->show[y++];
		while ((unsigned long)i < elem->prec - len_src + (tmp - elem->show))
			new[i++] = '0';
		while ((unsigned long)i < elem->prec + (tmp - elem->show))
			new[i++] = elem->show[y++];
		free(elem->show);
		return (new);
	}
	return (elem->show);
}

char		*ft_precision(t_chain *elem)
{
	if (ft_is_integer(elem->conv))
		return (ft_prec_on_integer(elem));
	if (elem->conv == 's')
		return (ft_prec_on_str(elem));
	return (elem->show);
}

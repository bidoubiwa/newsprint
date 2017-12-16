/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_w_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:10:45 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 18:07:08 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

///static char		*ft_3_bytes(wchar_t wc, )

static char		*ft_w_char_handler(wchar_t wc)
{
	char			*bin;
	unsigned long	x;
	int				i;
	char			*(*f)(unsigned long long, unsigned int);

	bin = NULL;
	if (!(wc <= 0x10ffff && wc >= 0 && (wc <= 0xd7ff || wc >= 0xe000)))
		return (NULL);
	f = &ft_itoa_base_ll;
	i = 0;
	if (wc <= 127 && MB_CUR_MAX > 0)
		bin = ft_itoa_base(wc, 2);
	else if (wc <= 2047 && MB_CUR_MAX > 1)
		bin = ft_strjoin_clr(ft_itoa_base((wc >> 6) + 0xC0, 2),
				ft_itoa_base((wc & 0x3F) + 0x80, 2));
	else if (wc <= 65535 && MB_CUR_MAX > 2)
	{
		bin = ft_strjoin_clr(f((wc >> 12) + 0xE0, 2), f(((wc >> 6) & 0x3F) + 0x80, 2));
		x = (wc & 0x3F) + 0x80;
		bin = ft_strjoin_clr(bin, f(x, 2));
	}
	else if (wc <= 1114111 && MB_CUR_MAX > 3)
	{
		bin = ft_strjoin_clr(f((wc >> 18) + 0xF0, 2), f(((wc >> 12) & 0x3f) + 0x80, 2));
		bin = ft_strjoin_clr(bin, f(((wc >> 6) & 0x3f) + 0x80, 2));
		bin = ft_strjoin_clr(bin, f((wc & 0x3F) + 0x80, 2));
	}
	return (bin);
}

int				ft_str_w_handler(t_chain *elem, va_list ap)
{
	wchar_t		*sw;

	if (elem->conv == 'C' || (elem->conv == 'c' && elem->len == 'l'))
	{
		if (!(elem->show = ft_w_char_handler(va_arg(ap, wchar_t))))
			return (-1);
		elem->nbr_carac = ft_strlen(elem->show) / 8;
	}
	else if (elem->conv == 'S')
	{
		sw = va_arg(ap, wchar_t *);
		elem->show = ft_strnew(0);
		while (*sw)
		{
			if (!(elem->show = ft_strjoin_clr(elem->show,
							ft_w_char_handler(*sw))))
				return (-1);
			elem->nbr_carac = ft_strlen(elem->show) / 8;
			sw++;
		}
	}
	return (ft_str_modifier(elem, elem->flag));
}

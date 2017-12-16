/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:49:08 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 17:00:39 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

int				ft_find_flag(char c, t_chain *elem)
{
	if (c == '-' || c == '0' || c == '+' || c == ' ' || c == 39 || c == '#' ||
			c == '*')
	{
		if (c == '-')
			(elem->flag)->left = 1;
		else if (c == '0')
			(elem->flag)->zero = 1;
		else if (c == '+')
			(elem->flag)->plus = 1;
		else if (c == ' ')
			(elem->flag)->blank = 1;
		else if (c == 39)
			(elem->flag)->apos = 1;
		else if (c == '#')
			(elem->flag)->hash = 1;
		else if (c == '*')
			(elem->flag)->star = 1;
		return (1);
	}
	else
		return (0);
}

const char		*ft_find_width(const char *format, t_chain *elem)
{
	int	y;

	y = 0;
	while (ft_isdigit(format[y]))
		y++;
	if (format[y] == '$')
	{
		(elem->flag)->wdol = ft_atoi(format);
		g_dollar = 1;
		return (&format[y + 1]);
	}
	else
		elem->width = ft_atoi(format);
	return (&format[y]);
}

const char		*ft_find_precision(const char *format, t_chain *elem)
{
	int	y;

	y = 1;
	while (ft_isdigit(format[y]))
		y++;
	if (format[y] == '$')
	{
		elem->pdol = ft_atoi(&format[1]);
		g_dollar = 1;
		return (&format[y + 1]);
	}
	else
	{
		elem->give_p = 1;
		elem->prec = ft_atoi(&format[1]);
	}
	return (&format[y]);
}

const char		*ft_find_length(const char *format, t_chain *elem)
{
	int		y;

	y = 0;
	while (g_len[y].len)
	{
		if (ft_match(format, g_len[y].len))
		{
			elem->len = g_len[y].c;
			return (&format[g_len[y].i]);
		}
		y++;
	}
	return (NULL);
}

int				ft_is_conv(char c, t_chain *elem)
{
	int		i;

	i = 0;
	elem->maj = (c >= 65 && c <= 90) ? 1 : 0;
	while (g_conv[i].conv)
	{
		if (g_conv[i].conv == c)
		{
			elem->conv = c;
			elem->f = g_conv[i].f;
			return (1);
		}
		i++;
	}
	elem->conv = c;
	elem->f = &ft_error_handler;
	return (0);
}

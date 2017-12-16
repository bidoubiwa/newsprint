/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:41:18 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 18:37:24 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

/*void	show_maillon(t_chain *tmp)
{
	t_flag	*flag;

		flag = tmp->flag;
		printf("--------------------------\n");
		printf("FLAGS :\n");
		printf("- : %d\n  : %d\n+ : %d\n0 : %d\n' : %d\n# : %d\n* : %d\n$ : %d\n", flag->left, flag->blank, flag->plus,  flag->zero, flag->apos, flag->hash, flag->star, flag->wdol);
		printf("INFO : \n");
		printf("width : %zu\nprec : %zu\nlen : %c\nconv : %c\nmaj : %d\ndollar : %d\njust_show : %d\nnbr_carac : %zu\nshow : %s\n",
				tmp->width, tmp->prec, tmp->len, tmp->conv, tmp->maj, tmp->pdol,tmp->just_show, tmp->nbr_carac, tmp->show);	
}*/

static void		ft_putchar_w(char *begin, int len)
{
	int		i;
	int		nbr;
	char	*byte;

	i = 0;
	while (i < len)
	{
		byte = ft_strsub(begin, i, 8);
		nbr = ft_atoi_base(byte, 2);
		ft_strdel(&byte);
		write(1, &(nbr), 1);
		i = i + 8;
	}
}

static int		ft_show_char_w(t_chain *elem)
{
	char			*space;
	int				i;

	i = 0;
	while (elem->show[i] == ' ')
		i++;
	if ((elem->flag)->left)
	{
		ft_putchar_w(elem->show, ft_strlen(elem->show));
		if ((space = ft_strchr(elem->show, ' ')))
			write(1, space, ft_strlen(space));
	}
	else
	{
		if (i)
		{
			space = ft_strsub(elem->show, 0, i);
			write(1, space, i);
			ft_strdel(&space);
		}
		ft_putchar_w(&elem->show[i], ft_strlen(&elem->show[i]));
	}
	return (1);
}

int				ft_show_all(t_chain *elem)
{
	int			len;
	int			total;

	len = 0;
	total = 0;
	while (elem)
	{
		if ((elem->conv == 'C' || elem->conv == 'S') && elem->show)
			ft_show_char_w(elem);
		else if (!elem->show)
		{
			write(1, "(null)", 6);
			elem->nbr_carac = 6;
		}
		else if (elem->show)
		{
			elem->nbr_carac = ft_strlen(elem->show);
			write(1, elem->show, elem->nbr_carac);
		}
		total += elem->nbr_carac;
		elem = elem->next;
	}
	return (total);
}

int				ft_handler(va_list ap, t_chain *chain)
{
	t_chain		*begin;
	t_chain		*test;
	int			total;

	test = chain;
	begin = chain;
	//while (test)
	//{
//		show_maillon(test);
//		test = test->next;
//	}
	while (chain)
	{
		if (!chain->just_show)
		{
			if (chain->f(chain, ap) == -1)
				return (-1);
		}
		chain = chain->next;
	}

	total = ft_show_all(begin);
	va_end(ap);
	return (total);
}

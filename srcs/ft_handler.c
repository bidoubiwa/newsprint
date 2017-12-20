/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:41:18 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 00:20:23 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

void	show_maillon(t_chain *tmp)
{
		t_flag	*flag;

		flag = tmp->flag;
		printf("--------------------------\n");
		printf("FLAGS :\n");
		printf("- : %d\n  : %d\n+ : %d\n0 : %d\n' : %d\n# : %d\n", flag->left, flag->blank, flag->plus,  flag->zero, flag->apos, flag->hash);
		printf("INFO : \n");
		printf("width : %zu\nprec : %zu\nlen : %c\nconv : %c\nmaj : %d\njust_show : %d\nnbr_carac : %zu\nshow : %s\n",
				tmp->width, tmp->prec, tmp->len, tmp->conv, tmp->maj, tmp->just_show, tmp->nbr_carac, tmp->show);	
}

static int		ft_putchar_w(char *begin, int len)
{
	int		i;
	int		nbr;
	char	*byte;

	i = 0;
	byte = NULL;
	while (i < len && begin)
	{
		byte = ft_strsub(begin, i, 8);
		nbr = ft_atoi_base(byte, 2);
			ft_strdel(&byte);
		write(1, &(nbr), 1);
		i = i + 8;
	}
	return (0);
}

static int		ft_show_char_w(t_chain *elem)
{
	char			*space;
	int				i;
	char			c;

	i = 0;
	c = ((elem->flag)->zero) ? '0' : ' '; 
	while (elem->show[i] == ' ')
		i++;
	if ((elem->flag)->left)
	{
		ft_putchar_w(elem->show, elem->nbr_byte * 8);
		space = &elem->show[elem->nbr_byte * 8];
		write(1, space, ft_strlen(space));
	}
	else
	{
		if (i)
		{
			write(1, ft_memset(elem->show, c, i), i);
		}
		ft_putchar_w(&elem->show[i], ft_strlen(&elem->show[i]));
	}
	return (1);
}

static int		ft_show_char_null(t_chain *elem)
{
	if (!elem->cnull && elem->conv == 'c' && elem->conv != 'l')
	{
		elem->nbr_carac = (elem->width > 0) ? elem->width : 1;
		if (!(elem->flag)->left)
		{
			write(1,elem->show,elem->nbr_carac - 1);
			write(1,"\0",1);
			return (1);
		}
		else if ((elem->flag)->left)
		{
			write(1,"\0",1);
			write(1,elem->show,	elem->nbr_carac - 1);
			return (1);
		}
	}
	return (0);
}

int				ft_show_all(t_chain *elem)
{
	int			len;
	int			total;

	len = 0;
	total = 0;
	while (elem)
	{
		/*if (!elem->show)
		{
			write(1, "(null)", 6);
			elem->nbr_carac = 6;
		}*/
		if (ft_show_char_null(elem) || ft_null_w_char(elem))
			;
		else if (elem->show && ft_is_w_char(elem))
			ft_show_char_w(elem);
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
	/*while (test)
	{
		show_maillon(test);
		test = test->next;
	}*/
	begin = chain;
	while (chain)
	{
		if (!chain->just_show)
		{
			if (chain->f(chain, ap) == -1)
			{
				dprintf(2,"JE PASSE PAR LA ?\n");
				total = ft_show_error(chain, begin);
				dprintf(2,"APRES RET\n");
				return (total);
			}
			dprintf(2,"APRES RET 222`\n");
		}
		chain = chain->next;
	}
	total = ft_show_all(begin);
	va_end(ap);
	return (total);
}

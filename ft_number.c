/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:40:23 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/25 20:27:00 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlnbr(int num, t_ind *lst)
{
	if (num == -2147483648)
	{
		ft_putlstr("-2147483648", lst);
		return ;
	}
	else if (num < 0)
	{
		ft_putlchar('-', lst);
		ft_putlnbr(-num, lst);
	}
	else if (num > 9)
	{
		ft_putlnbr(num / 10, lst);
		ft_putlnbr(num % 10, lst);
	}
	else
	{
		num = num + '0';
		ft_putlchar(num, lst);
	}
}

void	ft_putlptr(size_t ptr, t_ind *lst)
{
	char	*base;

	base = "0123456789abcdef";
	if (!ptr)
		ft_putlstr("(nil)", lst);
	else
	{
		if (ptr < 16)
		{
			ft_putlstr("0x", lst);
			ft_putlchar(base[ptr % 16], lst);
			return ;
		}
		ft_putlptr(ptr / 16, lst);
		ft_putlchar(base[ptr % 16], lst);
	}
}

void	ft_putlhex(unsigned int x, char c, t_ind *lst)
{
	char	*str;
	char	*base;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (!x)
	{
		ft_putlchar('0', lst);
		return ;
	}
	while (x)
	{
		*str = base[x % 16];
		x /= 16;
		str++;
	}
	while (*str)
		ft_putlchar(*(str)--, lst);
}

void	ft_putluint(unsigned int u, t_ind *lst)
{
	if (u > 9)
		ft_putluint(u / 10, lst);
	else
	{
		u %= 10;
		u += '0';
		ft_putlchar(u, lst);
	}
}

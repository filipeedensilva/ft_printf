/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:21:46 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/26 18:51:31 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct ran
{
	int	len;
	int	width;
}			t_ind;

int		ft_printf(const char *format, ...);
void	ft_putlstr(char *str, t_ind *lst);
void	ft_putlchar(char c, t_ind *lst);
void	ft_putlnbr(long num, t_ind *lst);
void	ft_putlptr(size_t ptr, t_ind *lst);
void	ft_putlhex(unsigned int x, char c, t_ind *lst);

#endif

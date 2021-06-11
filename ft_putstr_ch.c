/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:48:49 by ddelena           #+#    #+#             */
/*   Updated: 2021/06/11 16:47:10 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr_ch(char *s, int j, int fd)
{
	int	count;

	count = 0;
	if (s)
	{
		if (j > 0)
		{
			while (*s && count < j)
			{
				write(fd, s, 1);
				count++;
				s++;
			}
		}
		else
		{
			while (*s)
			{
				write(fd, s, 1);
				count++;
				s++;
			}
		}
	}
	return (count);
}

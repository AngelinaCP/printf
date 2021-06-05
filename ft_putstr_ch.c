/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:48:49 by ddelena           #+#    #+#             */
/*   Updated: 2021/06/01 16:39:54 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

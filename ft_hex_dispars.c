#include "libft.h"

int	num_hed(long long j)
{
	int num;
	int i;

	num = 0;
	i = j;
	if (i >= 0 && i <= 9)
		num = 1;
	else
	{
		while (i > 0)
		{
			i /= 16;
			num++;
		}
	}
	return (num);
}

int treat_hex(t_list *flags, char *list, int i)
{
	int num;

	num = num_hed(flags->hex);
	if (flags->dot > 0 && flags->minus == 0)
	{
		if (flags->precision > 0)
		{
			if (flags->dot > num)
				put_zero_and_space(flags, flags->dot);
			else
				put_zero_and_space(flags, num);
		}
		if (flags->precision == 0)
			flags->precision = flags->dot;
		flags->minus = 1;
		put_zero_and_space(flags, num);
		num = putnb_hed(list, i, flags);
	}
	else if (flags->minus > 0 && flags->precision > 0 && flags->dot == 0)
	{
		putnb_hed(list, i, flags);
		flags->minus = 0;
		put_zero_and_space(flags, num);
	}
	else
	{
		num = putnb_hed(list, i, flags);
		(put_zero_and_space(flags, num));
	}
//	if (flags->precision > 0 && flags->dot > 0)
//	{
//		put_zero_and_space(flags, flags->precision - num);
//		putnb_hed(list, i, flags);
//	}
//	else if (flags->dot > 0)
//	{
//		flags->precision = flags->dot;
//		flags->minus = 0;
//		put_zero_and_space(flags, num);
//	}
	return (num);
}

int putnb_hed(char *list, int i, t_list *flags)
{
	if (list[i] == 'x')
		return (putnb_short_base(flags->hex, 16, flags->low_hex));
	else
		return (putnb_short_base(flags->hex, 16, flags->up_hex));
}

int putnb_short_base(long long n, size_t base_len, char *base)
{
	if (n < base_len)
		return (ft_putchar_fd(base[n], 1));
	return (putnb_short_base(n / base_len, base_len, base) + //
		ft_putchar_fd(base[n % base_len], 1));
}


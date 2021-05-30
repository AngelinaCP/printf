#include "libft.h"

void	put_zero_and_space(t_list *flags, int num)
{
	while (flags->precision - num - flags->negative > 0)
	{
		if (flags->minus > 0)
			flags->count += ft_putchar_fd('0', 1);
		else
			flags->count += ft_putchar_fd(' ', 1);
		flags->precision--;
	}
}

void	put_zero(t_list *flags, int num)
{
	int i;

	i = flags->dot;
	while (i - num > 0)
	{
		flags->count += ft_putchar_fd('0', 1);
		i--;
	}
}

int putnb_hed(char *list, int i, t_list *flags, int num)
{
	if (list[i] == 'p')
		return (treat_pointer(flags, num, list, i));
	else if (list[i] == 'x')
		return (putnb_short_base(flags->num, flags->base, flags->low_hex, flags));
	else
		return (putnb_short_base(flags->num, flags->base, flags->up_hex, flags));
}

int putnb_short_base(long long n, size_t base_len, char *base, t_list *flags)
{
	if (n < base_len)
		return (ft_putchar_fd(base[n], 1));
	return (putnb_short_base(n / base_len, base_len, base, flags) + //
			ft_putchar_fd(base[n % base_len], 1));
}

int	num_div(long long j, int base)
{
	int num;
	long long i;

	num = 0;
	i = j;
	if (i < 0)
		i *= -1;
	if (i >= 0 && i <= 9)
		num = 1;
	else
	{
		while (i > 0)
		{
			i /= base;
			num++;
		}
	}
	return (num);
}

int int_disp(char *list, int i, t_list *flags, int num)
{
	int j;

	j = 0;
	if (flags->base == 16)
		return (putnb_hed(list, i, flags, num));
	else if (flags->base == 10)
	{
		if (list[i] == 'u')
			putnb_short_base(flags->num, flags->base, "0123456789", flags);
		else if (flags->num == 4294967295)
			flags->count = ft_putstr_fd("4294967295",0,  1);
		else
			j = ft_putnbr_fd(flags->num, 1);
		return (num + j);
	}
	return (0);
}

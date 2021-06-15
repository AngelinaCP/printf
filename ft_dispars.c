#include "libftprintf.h"

void	put_zero(t_list *flags, int num)
{
	int	i;

	i = flags->dot;
	while (i - num > 0)
	{
		flags->count += ft_putchar_fd('0', 1);
		i--;
	}
}

int	putnb_hed(char *format, int i, t_list *flags)
{
	if (format[i] == 'p')
		return (treat_pointer(flags));
	else if (format[i] == 'x')
		return (ft_putnb_short_base(flags->num, flags->base,
				flags->low_hex, flags));
	else
		return (ft_putnb_short_base(flags->num, flags->base,
				flags->up_hex, flags));
}

int	ft_putnb_short_base(long long n, size_t base_len, char *base, t_list *flags)
{
	if (n < (long long)base_len)
		return (ft_putchar_fd(base[n], 1));
	return (ft_putnb_short_base(n / base_len, base_len, base, flags)
		+ ft_putchar_fd(base[n % base_len], 1));
}

int	num_div(long long j, int base)
{
	int			num;
	long long	i;

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

int	int_disp(char *format, int i, t_list *flags, int num)
{
	int	j;

	j = 0;
	if (flags->base == 16)
		return (putnb_hed(format, i, flags));
	else if (flags->base == 10)
	{
		if (format[i] == 'u')
			ft_putnb_short_base(flags->num, flags->base, "0123456789", flags);
		else if (flags->num == 4294967295)
			flags->count = ft_putstr_ch("4294967295", 0, 1);
		else
			j = ft_putnbr_fd(flags->num, 1);
		return (num + j);
	}
	return (0);
}

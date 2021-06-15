#include "libftprintf.h"

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

int	get_null(t_list *flags)
{
	if ((flags->dot_p > 0 && flags->precision == 0 && flags->star == 0
			&& !flags->num) || (flags->dot_p > 0
			&& flags->width == flags->precision
			&& flags->star == 0 && !flags->num))
	{
		flags->minus = 0;
		put_zero(flags, 0);
		return (0);
	}
	return (-1);
}

int	dispars_string(t_list *flags, va_list argc)
{
	int		len;
	char	*ar;

	len = 0;
	ar = va_arg(argc, char *);
	if (ar == NULL)
	{
		ar = "(null)";
		if (get_null(flags) == 0)
			return (0);
	}
	if (flags->dot_e == 1)
	{
		flags->minus = 0;
		put_zero_and_space(flags, 0);
		return (0);
	}
	len = string_neg(flags, ar, len);
	return (len);
}

int	string_neg(t_list *flags, char *ar, int len)
{
	if (flags->minus == 0)
	{
		if (flags->zero == 1)
			flags->minus = 1;
		if (flags->precision > 0)
		{
			if (flags->dot_p && flags->dot < (int)ft_strlen(ar))
				put_zero_and_space(flags, flags->dot);
			else
				put_zero_and_space(flags, ft_strlen(ar));
		}
		len = ft_putstr_ch(ar, flags->dot, 1);
	}
	else
		len = dispars_neg_string(flags, ar, len);
	return (len);
}

int	dispars_neg_string(t_list *flags, char *ar, int len)
{
	len += ft_putstr_ch(ar, flags->dot, 1);
	if (flags->precision > 0)
	{
		flags->minus = 0;
		if (flags->dot_p && flags->dot < (int)ft_strlen(ar))
			put_zero_and_space(flags, flags->dot);
		else
			put_zero_and_space(flags, (int)ft_strlen(ar));
	}
	return (len);
}

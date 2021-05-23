#include "libft.h"

int get_null(t_list *flags)
{
	if ((flags->dot == 1 && flags->precision == 0) || (flags->dot == 1 && flags->width == flags->precision))
	{
		flags->minus = 0;
		put_zero_and_space(flags, flags->dot - 1);
		return (-1);
	}
	return (0);
}

int dispars_string(t_list *flags, va_list argc, char *list, int i)
{
	int		len;
	char	*ar;

	len = 0;
	ar = va_arg(argc, char *);
	if (ar == NULL)
		ar = "(null)";
	if (get_null(flags))
		return (0);
	if (flags->minus == 0)
	{
		if (flags->precision > 0)
		{
			if (flags->dot && flags->dot < ft_strlen(ar))
				put_zero_and_space(flags, flags->dot);
			else
				put_zero_and_space(flags, ft_strlen(ar));
		}
		len = ft_putstr_fd(ar, flags->dot, 1);
	}
	else
		len = dispars_neg_string(flags, ar, len);
	return (len);
}

int dispars_neg_string(t_list *flags, char *ar, int len)
{
	len += ft_putstr_fd(ar, flags->dot, 1);
	if (flags->precision > 0)
	{
		if (flags->zero == 0)
			flags->minus = 0;
		if (flags->dot && flags->dot < ft_strlen(ar))
			put_zero_and_space(flags, flags->dot);
		else
			put_zero_and_space(flags, ft_strlen(ar));
	}
	return (len);
}

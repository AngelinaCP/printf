#include "libft.h"

int	treat_int(t_list *flags, char *format, int i)
{
	int	num;

	num = num_div(flags->num, flags->base);
	num = int_condition(flags, num, format, i);
	if (get_null(flags) == 0 && format[i] != 'p')
		return (0);
	if (flags->dot == 0 && flags->num == 0 && flags->dot_p == 1
		&& format[i] != 'p')
	{
		flags->minus = 0;
		put_zero_and_space(flags, 0);
		return (0);
	}
	if ((flags->dot > 0 && flags->sym) || flags->num < 0)
		flags->negative = 1;
	if (flags->minus == 0)
		return (dispars_int(flags, num, format, i));
	else
		return (dispars_neg(flags, num, format, i));
}

int	dispars_int(t_list *flags, int num, char *format, int i)
{
	if (flags->dot_p == 0 && flags->zero == 1)
		flags->minus = 1;
	if ((flags->zero == 1 && flags->precision > 0 && flags->dot_p == 0)
		|| (flags->zero == 1 && flags->precision > 0 && flags->dot < 0))
	{
		flags->minus = 1;
		ft_putstr_ch(flags->sym, 0, 1);
		flags->sym = 0;
	}
	if (flags->precision > flags->dot)
	{
		if (flags->dot > num)
			put_zero_and_space(flags, flags->dot);
		else
			put_zero_and_space(flags, num);
	}
	ft_putstr_ch(flags->sym, 0, 1);
	if (flags->dot > 0)
		put_zero(flags, num);
	num = int_disp(format, i, flags, num);
	return (num);
}

int	dispars_neg(t_list *flags, int num, char *format, int i)
{
	if (flags->sym)
		ft_putstr_ch(flags->sym, 0, 1);
	flags->minus = 0;
	if (flags->dot != 0)
		put_zero(flags, num);
	i = int_disp(format, i, flags, num);
	if (flags->precision > flags->dot)
	{
		if (flags->dot > num)
			put_zero_and_space(flags, flags->dot);
		else
			put_zero_and_space(flags, num);
	}
	return (i);
}

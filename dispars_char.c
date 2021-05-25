#include "libft.h"

void	dispars_char(t_list *flags, va_list argc, char *list, int i)
{
	int	ar;

	ar = va_arg(argc, int);
	if (flags->width > 0 || flags->precision > 0)
	{
		if (flags->minus == 0)
		{
			flags->minus = 0;
			put_zero_and_space(flags, 1);
			flags->count += ft_putchar_fd(ar, 1);
		}
		else if (flags->minus == 1)
			char_minus(flags, argc, ar);
//		{
//			put_zero_and_space(flags, 1);
//			flags->count += ft_putchar_fd(ar, 1);
//		}
		return ;
	}
	flags->count += ft_putchar_fd(ar, 1);
}
//	int	ar;
//
//	ar = va_arg(argc, int);
//	if (ar == 0)
//		ft_putstr_fd("(null)",0, 1);
//	if (flags->star == 1)
//	{
//		ft_putchar_fd(ar, 1);
//		flags->minus = 0;
//	}
//	else if (flags->minus == 1)
//		char_minus(flags, argc, ar);
//	else
//		ft_putchar_fd(ar, 1);
//	return (1);
//}
//
void	char_minus(t_list *flags, va_list argc, int ar)
{
		flags->minus = 0;
		flags->count += ft_putchar_fd(ar, 1);
		put_zero_and_space(flags, 1);
}

void    print_percent(t_list *flags)
{
	if (flags->width > 0)
	{
		if (flags->minus > 0)
		{
			flags->minus = 0;
			flags->count += ft_putchar_fd('%', 1);
			put_zero_and_space(flags, 1);
		}
		else
		{
			if (flags->zero == 1)
				flags->minus = 1;
			put_zero_and_space(flags, 1);
			flags->count += ft_putchar_fd('%', 1);
		}
		return ;
	}
	flags->count += ft_putchar_fd('%', 1);
}
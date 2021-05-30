#include "libft.h"

void	ft_flags_s(t_list *flags)
{
	flags->width = 0;
	flags->minus = 0;
	flags->dot = 0;
	flags->star = 0;
	flags->zero = 0;
	flags->sym = 0;
	flags->precision = 0;
//	flags->num = 0;
	flags->negative = 0;
	flags->dot_e = 0;
	flags->hex = 0;
	flags->base = 0;
	flags->dot_p = 0;
	flags->low_hex = "0123456789abcdef";
	flags->up_hex = "0123456789ABCDEF";
}

int	ft_flags(char c)
{
	if (c == 'c' || c == 'i' || c == 'p' || c == 'd' || c == 's'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return(1);
	return(0);
}

int	ft_conversion (char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	return (0);
}

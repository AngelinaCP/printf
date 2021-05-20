#include "libft.h"

int	ft_flag_pars(char *list, int i, t_list *flags, va_list argc)
{
	int count;

	count = 0;
	if (list[i] == 'c')
		count = dispars_char(*flags, argc, list, i);
	else if (list[i] == 'i' || list[i] == 'd')
		count = dispars_num(flags, argc, list, i);
	else if (list[i] == 'u')
	    count = dispars_num(flags, argc, list, i);
	else if (list[i] == 's')
		count = dispars_string(flags, argc, list, i);
	else if (list[i] == 'x')
	    putnb_short_base()

	return (count);
}

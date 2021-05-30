#include "libft.h"

int	ft_flag_pars(char *list, int i, t_list *flags, va_list argc)
{
	int count;

	count = 0;
	if (list[i] == 'c')
		 dispars_char(flags, argc, list, i);
	else if (list[i] == 'i' || list[i] == 'd')
		count = dispars_num(flags, argc, list, i);
	else if (list[i] == 'u')
	    count = dispars_num(flags, argc, list, i);
	else if (list[i] == 's')
	{
		if (flags->dot_p == 1 && flags->dot == 0)
			flags->dot_e = 1;
		count = dispars_string(flags, argc, list, i);
	}
	else if (list[i] == 'x' || list[i] == 'X')
	    count = dispars_num(flags, argc, list, i);
	else if (list[i] == 'p')
		count = dispars_num(flags, argc, list, i);
//	printf("+%d+", count);
	return (count);
}

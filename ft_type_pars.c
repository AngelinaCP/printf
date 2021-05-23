#include "libft.h"

int	ft_type_pars(char *list, int i, t_list *flags, va_list argc)
{
  	while (ft_isdigit(list[i]) || ft_conversion(list[i]) || ft_flags(list[i]))
	{
	    if (list[i] == '%')
        {
            print_percent(flags);
	        i++;
        }
		else if (list[i] == '*')
		{
			ft_flag_star(list, i, flags, argc);
			i++;
		}
		else if (list[i] == '.')
		{
			flags->dot = 1;
			i++;
		}
		else if (list[i] == '0')
		{
			ft_flag_zero(list, i, flags, argc);
			i++;
		}
		else if (list[i] == '-')
		{
			ft_flag_minus(flags);
			i++;
		}
        else if (ft_isdigit(list[i]))
        {
            ft_digit_pars(list, i, flags, argc);
            while (ft_isdigit(list[i]))
                i++;
        }
        else if (ft_flags(list[i]))
        {
            flags->count += ft_is_flag(list, i, flags, argc);
            i++;
            break;
        }
		else
			return (-1);
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelena <ddelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:47:33 by ddelena           #+#    #+#             */
/*   Updated: 2021/06/11 16:53:27 by ddelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int			width;
	int			dot;
	int			minus;
	int			star;
	int			zero;
	char		*sym;
	int			count;
	int			precision;
	int			negative;
	long long	num;
	int			dot_e;
	int			dot_p;
	long long	hex;
	char		*up_hex;
	char		*low_hex;
	int			base;
}	t_list;

void	put_zero(t_list *flags, int num);
int		ft_putchar_fd(char s, int fd);
int		ft_flags(char c);
int		ft_conversion(char c);
int		ft_isdigit(int s);
int		ft_putchar_fd(char s, int fd);
int		ft_putstr_ch(char *s, int j, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *format, ...);
int		ft_flags_count(t_list *flags, char *format, int i);
int		ft_atoi(const char *str);
int		ft_flag_star(t_list *flags, va_list argc);
int		ft_flag_pars(char *format, int i, t_list *flags, va_list argc);
size_t	ft_strlen(const char *str);
int		ft_type_pars(char *format, int i, t_list *flags, va_list argc);
int		ft_is_flag(char *format, int i, t_list *flags, va_list argc);
int		ft_digit_pars(char *format, int i, t_list *flags, va_list argc);
void	ft_flags_s(t_list *flags);
int		ft_flags(char c);
int		ft_conversion (char c);
void	treat_width(t_list *flags, int num);
void	dispars_char(t_list *flags, va_list argc, char *format, int i);
int		ft_check_flags(va_list argc, char *format, t_list *flags);
void	char_minus(t_list *flags, va_list argc, int ar);
void	put_zero_and_space(t_list *flags, int num);
int		dispars_string(t_list *flags, va_list argc, char *format, int i);
int		check_space(int i, char *format, va_list argc, t_list *flags);
void	print_percent(t_list *flags);
int		ft_putnb_short_base(long long n, size_t base_len, char *base,
			t_list *flags);
int		num_div(long long j, int base);
int		putnb_hed(char *format, int i, t_list *flags, int num);
int		int_disp(char *format, int i, t_list *flags, int num);
int		treat_int(t_list *flags, char *format, int i);
int		dispars_int(t_list *flags, int num, char *format, int i);
int		dispars_neg(t_list *flags, int num, char *format, int i);
int		get_null(t_list *flags);
int		dispars_neg_string(t_list *flags, char *ar, int len);
int		treat_pointer(t_list *flags);
int		format_pars_flags(char *format, int i, t_list *flags, va_list argc);
int		string_neg(t_list *flags, char *ar, int len);
int		int_condition(t_list *flags, int num, char *format, int i);
int		treat_int(t_list *flags, char *format, int i);
int		dispars_num(t_list *flags, va_list argc, char *format, int i);
int		format_pars_digit(char *format, int i, t_list *flags, va_list argc);

#endif

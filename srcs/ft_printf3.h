/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:15:21 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 13:48:41 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

# define TYPES "sSpdDioOuUxXcC%"
# define FLAGS "#0-+ "
# define LENGTH "hljzL"

# define ERROR "Error Error Error"

/*
** Flags:
** 0 - (#) alternate form
** 1 - (0) fill with 0 if width
** 2 - (-) left align output
** 3 - (+) positive sign
** 4 - ( ) space sign if plus
*/

/*
** Length:
** h  -> h
** hh -> H
** l  -> l
** ll -> L
** L  -> m
** j  -> j
** z  -> z
*/

typedef struct	s_output
{
	int			size;
	char		*output;
}				t_output;

typedef struct	s_conversion
{
	char		flags[5];
	int			min_width;
	int			precision;
	int			precision_isset;
	char		length;
	char		type;
	void		*value;
	char		*output;
	int			size;
}				t_conversion;

/*
** debug.c
*/
void			debug(t_conversion *test);
/*
** ft_itoa_base.c
*/
char			*ft_itoa_base(long long n, int base);
char			*ft_uitoa_base(unsigned long long n, int base);
/*
** ft_printf_output.c
*/
void			ft_printf_output_align(t_conversion *a);
void			ft_printf_output_sign(t_conversion *a, int neg);
void			ft_printf_output_precision(t_conversion *a, int neg);
void			ft_printf_output_precision_hex(t_conversion *a, int zero);
/*
** ft_printf_parsing.c
*/
void			parse_flags(const char **nav, t_conversion *result);
void			parse_minwidth(const char **nav, t_conversion *result);
void			parse_precision(const char **nav, t_conversion *result);
void			parse_length(const char **nav, t_conversion *result);
void			parse_type(const char **nav, t_conversion *result);
/*
** ft_printf_print.c
*/
char			*ft_printf_hex(t_conversion *actual);
char			*ft_printf_oct(t_conversion *actual);
char			*ft_printf_int(t_conversion *actual);
char			*ft_printf_uint(t_conversion *actual);
/*
** ft_printf_process.c
*/
void			ft_nbchar_bef(char c, int i, t_conversion *actual);
void			ft_nbchar_aft(char c, int i, t_conversion *actual);
void			printf_process_decimal(t_conversion *a);
void			printf_process_u_decimal(t_conversion *a);
void			printf_process_modulo(t_conversion *actual);
void			printf_process_hex(t_conversion *actual);
void			printf_process_oct(t_conversion *actual);
void			printf_process_char(t_conversion *actual);
void			printf_process_string(t_conversion *actual);
void			printf_process_wstring(t_conversion *actual);
void			printf_process_wstring(t_conversion *actual);
void			printf_process_pointer(t_conversion *actual);
void			printf_process_unknown(t_conversion *actual);
/*
** ft_printf_struct.c
*/
void			struct_blank(t_conversion *ret);
int				parse_false(t_conversion *result);
t_conversion	*printf_parsing(const char **nav, va_list ap);
/*
** ft_printf.c
*/
void			printf_process_type(t_conversion *actual);
int				ft_printf(const char *format, ...);
/*
** ft_putwchar.c
*/
int				ft_wputchar(wchar_t c);
void			ft_wputstr(wchar_t *s);
int				ft_wcharlen(wchar_t c);
char			*ft_strjoinchar(char const *s1, char const c);

wchar_t			*ft_wstrconvert(const char *s);
wchar_t			*ft_wstrnew(size_t size);

int				ft_wchartostr(wchar_t c, char *str);

size_t			ft_wstrlen(wchar_t *s);


#endif
#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int					ft_printf(const char *format, ...);
void				putin_list(void);
int					check_alloc(char *fmt);
int					parser(char *fmt);
void				printer(void);
int					set_flag(char *fmt);
int					set_width(char *fmt);
int					set_prec(char *fmt);
int					set_spec(char *fmt);
void				print_char(void);
void				print_string(void);
void				print_pointer(void);
void				print_nbr(void);
void				print_unsigned(void);
void				print_hex(void);
int					compatible(void);
void				print_eof(char *fmt);
char				*prefiller(char *fmt, char c, size_t n);
char				*addfiller(char *fmt, char c, size_t n);
char				*widthfiller(char *fmt);
char				*nbr_precison(char *fmt);
void				putfmt(char *fmt);
char				*check_hex(unsigned long nb);
char				check_char(char *base, int n);
void				rebase(unsigned long nb, char *dst, int i);
int					hex_len(unsigned long nb);
char				*unsigned_itoa(unsigned n);
typedef struct		s_ptf
{
	va_list			ar;
	char			*fmt;
	char			*specs;
	char			spec;
	int				error;
	int				zero;
	int				minus;
	int				dot;
	int				width;
	int				precisn;
	int				len;
}					t_ptf;
extern t_ptf		*list;
#endif

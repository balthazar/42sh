/*
** Laule don't have header generator Gne
*/

#include "42sh.h"

int		treat_key_up(void)
{
	t_ctx	*ctx;
	char	*res;
	int		i;

	ctx = CTX;
	res = ft_get_string(UP);
	if (res)
	{
		i = 0;
		while (ctx->i > 0)
		{
			tputs(tgetstr("kl", NULL), 1, ft_putput);
			--ctx->i;
		}
		tputs(tgetstr("ce", NULL), 1, ft_putput);
		ft_bzero(ctx->line, LINE_LEN);
		while (res[i] != '\0')
		{
			ctx->line[i] = res[i];
			++i;
		}
		ctx->i = i;
		ctx->len = i;
		ft_putstr(res);
	}
	return (OK);
}

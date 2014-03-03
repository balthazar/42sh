/*
** Same
*/

#include "42sh.h"

int		treat_key_down(void)
{
	t_ctx	*ctx;
	char	*res;

	ctx = CTX;
	res = ft_get_string(DOWN);
	return (OK);
}

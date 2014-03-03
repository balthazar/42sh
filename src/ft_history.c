/*
** Laule don't have the header generator
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

char	*ft_get_string(int key)
{
	t_ctx	*ctx;

	ctx = CTX;
	if (ctx->history)
	{
		if (key == UP && ctx->current)
		{
			ctx->current = ctx->current->prev;
			if (ctx->current)
				return (ctx->current->content);
		}
		else if (key == DOWN)
		{
			ctx->current = ctx->current->next;
			if (ctx->current)
				return (ctx->current->content);
		}
	}
	return (NULL);
}

void	ft_add_history(char *str)
{
	int		fd;
	char	*tmp;
	t_ctx	*ctx;
	t_dlist	*new;

	ctx = CTX;
	new = ft_dlstnew(str, sizeof(char) * (ft_strlen(str) + 1));
	ft_dlstpush(&ctx->history, new);
	/*if (ctx->current)
	{
	  free(ctx->current);
	  ctx->current = NULL;
	}*/
	ctx->current = new;
	tmp = ft_getvar_env("HOME", ctx->env);
	if (tmp)
	{
		tmp = ft_strjoin(tmp, "/.yolosh_history");
		fd = open(tmp, O_CREAT | O_WRONLY | O_APPEND, 0604);
		free(tmp);
		if (fd == -1)
		{
			//err
		}
		else
		{
			ft_putendl_fd(str, fd);
			close(fd);
		}
	}
	else
	{
		//err
	}
	//	if(ctx->current->prev)
	//		printf("\n\ncurr %s\n", ctx->current->prev->content);
}

void	ft_load_history(t_ctx *ctx)
{
	int		fd;
	char	*tmp;
	t_dlist	*new;

	tmp = ft_getvar_env("HOME", ctx->env);
	if (tmp)
	{
		tmp = ft_strjoin(tmp, "/.yolosh_history");
		fd = open(tmp, O_RDONLY);
		free(tmp);
		if (fd != -1)
		{
			while (get_next_line(fd, &tmp))
			{
				new = ft_dlstnew(tmp, sizeof(char) * (ft_strlen(tmp) + 1));
				ft_dlstpush(&ctx->history, new);
				free(tmp);
			}
			ctx->current = new;
			free(tmp);
			close(fd);
		}
	}
}

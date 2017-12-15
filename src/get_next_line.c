/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:31:00 by geargenc          #+#    #+#             */
/*   Updated: 2017/11/28 17:13:23 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char			**ft_get_fd(t_gnllst **list, const int fd)
{
	int				i;

	if (!*list)
	{
		if (!(*list = (t_gnllst *)malloc(10 * sizeof(t_gnllst))))
			return (NULL);
		i = 0;
		while (i < 10)
		{
			(*list)[i].content = NULL;
			(*list)[i].next = NULL;
			i++;
		}
	}
	if (fd >= 10)
		return (ft_get_fd(&((*list)[fd % 10].next), fd / 10));
	else
		return (&((*list)[fd].content));
}

static int			ft_gnlret(char *chr, char **content, char **line)
{
	char			*tmp;

	if (chr && !(*line = ft_strsub(*content, 0, chr - *content)))
		return (-1);
	else if (!chr && *content && !(*line = ft_strdup(*content)))
		return (-1);
	if (chr && chr[1])
	{
		tmp = *content;
		if (!(*content = ft_strdup(chr + 1)))
			return (-1);
		free(tmp);
		return (1);
	}
	else if (*content)
	{
		free(*content);
		*content = NULL;
		return (1);
	}
	else
		return (0);
}

static int			ft_free_fd(t_gnllst **list, const int fd)
{
	int				i;

	if (fd < 10 || ft_free_fd(&((*list)[fd % 10].next), fd / 10))
	{
		i = 0;
		while (i < 10 && !(*list)[i].content && !(*list)[i].next)
			i++;
		if (i == 10)
		{
			free(*list);
			*list = NULL;
			return (1);
		}
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnllst	*list = NULL;
	char			**content;
	char			buf[BUFF_SIZE + 1];
	char			*chr;
	int				ret;

	if (fd < 0 || !(content = ft_get_fd(&list, fd)))
		return (-1);
	chr = NULL;
	ret = 0;
	while ((!(*content) || !(chr = ft_strchr(*content, '\n'))) &&
		(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((*content) ? !(*content = ft_strjoinfree(*content, buf, 1)) :
			!(*content = ft_strdup(buf)))
			return (-1);
	}
	if (ret < 0 || (ret = ft_gnlret(chr, content, line)) < 0)
		return (-1);
	if (!*content)
		ft_free_fd(&list, fd);
	return (ret);
}

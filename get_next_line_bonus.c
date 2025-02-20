/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:38:32 by radaoudi          #+#    #+#             */
/*   Updated: 2022/01/31 11:57:53 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_ligne(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	tmp = ft_substr(s, 0, i + 1);
	return (tmp);
}

char	*ft_sauvegarde(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	tmp = ft_substr(s, i + 1, ft_strlen(s));
	free(s);
	return (tmp);
}

char	*ft_lire_fd(int fd, char *s)
{
	char	*buff;
	int		ret;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ret = 1;
	while (!ft_strchr(s, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*l;
	static char	*s[200];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 200)
		return (0);
	s[fd] = ft_lire_fd(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	l = ft_ligne(s[fd]);
	s[fd] = ft_sauvegarde(s[fd]);
	return (l);
}

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marihovh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/20 02:22:18 by marihovh		  #+#	#+#			 */
/*   Updated: 2023/02/02 19:43:07 by marihovh		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_word_cnt(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*ned;
	int		i;
	int		wordcnt;

	i = 0;
	wordcnt = ft_word_cnt(s, c);
	split = (char **)malloc((wordcnt + 1) * sizeof(char *));
	while (i < wordcnt)
	{
		while (*s && *s == c)
			s++;
		ned = ft_strchr(s, c);
		if (ned == NULL)
			split[i++] = ft_substr(s, 0, ft_strlen(s));
		else
			split[i++] = ft_substr(s, 0, ned - s);
		s = ned;
	}
	split[i] = NULL;
	return (split);
}

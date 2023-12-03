/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strtrim.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marihovh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/20 02:21:47 by marihovh		  #+#	#+#			 */
/*   Updated: 2023/02/02 21:07:00 by marihovh		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*nstr;
	int		i;
	int		j;

	i = 0;
	if (!set)
		return (NULL);
	if (!s1)
		return (NULL);
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[j - 1]) && j > i)
		j--;
	nstr = ft_substr(s1, i, (j - i));
	return (nstr);
}

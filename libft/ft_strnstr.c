/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strnstr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marihovh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/22 03:08:21 by marihovh		  #+#	#+#			 */
/*   Updated: 2023/02/02 18:14:29 by marihovh		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*str;
	char	*ned;
	size_t	i;
	size_t	len;

	i = 0;
	str = (char *)haystack;
	ned = (char *)needle;
	len = ft_strlen(ned);
	if (*ned == '\0')
		return (str);
	while (str[i] != '\0' && i + len <= n)
	{
		if (ft_strncmp((str + i), ned, len) == 0)
			return (str + i);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memmove.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marihovh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/20 05:01:57 by marihovh		  #+#	#+#			 */
/*   Updated: 2023/02/03 21:36:26 by marihovh		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)str1;
	b = (unsigned char *)str2;
	if (b < a)
	{
		while (n-- > 0)
			*(a + n) = *(b + n);
	}
	else
	{
		while (i < n)
		{
			*(a + i) = *(b + i);
			i++;
		}
	}
	return (str1);
}

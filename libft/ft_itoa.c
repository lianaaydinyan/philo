/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marihovh <marihovh@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/20 02:22:42 by marihovh		  #+#	#+#			 */
/*   Updated: 2023/09/19 13:21:19 by marihovh		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	leng(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len = 1;
		n *= (-1);
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*iszero(char *str)
{
	str[0] = '0';
	str [1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long int	nb;

	count = leng(n);
	nb = n;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (nb == 0)
		return (iszero(str));
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[--count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

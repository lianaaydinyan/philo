/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_calloc.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marihovh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/23 15:23:26 by marihovh		  #+#	#+#			 */
/*   Updated: 2023/01/29 06:36:47 by marihovh		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	if (size >= SIZE_MAX)
		return (0);
	ptr = (void *)malloc(number * size);
	ft_bzero(ptr, number * size);
	return (ptr);
}

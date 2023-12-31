/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isalpha.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marihovh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/19 15:28:56 by marihovh		  #+#	#+#			 */
/*   Updated: 2023/01/21 22:29:03 by marihovh		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (((c >= 'a' ) && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')));
}

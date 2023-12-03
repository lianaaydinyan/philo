/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstclear.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marihovh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/01 05:53:26 by marihovh		  #+#	#+#			 */
/*   Updated: 2023/02/03 22:05:37 by marihovh		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*j;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		j = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = j;
	}
	lst = 0;
}

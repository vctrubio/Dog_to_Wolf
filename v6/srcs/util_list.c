#include "../include/header.h"

int	ft_lstsize(t_list *lst)
{
	int	index;

	index = 0;
	while (lst)
	{
		// printf("%s--\n", (char*)lst->content);
		lst = lst->next;
		index++;
	}
	// printf("return %d\n", index);
	return (index);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else if (*lst && new)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	del(void *content)
{
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	current = *lst;
		printf("############%s\n", (char*)current->content);
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*lst = NULL;
}
#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

/*#include <stdio.h>
 void display(t_list* n)
{
  while(n != NULL)
  {
    printf("%d",*(int *)n->data);
    n = n->next;
  }
}

int main() 
{
  t_list *Node;
  int a = 1337;
  void *ptr = &a;
  Node = ft_create_elem(ptr);
  display(Node);
  return 0;
}*/
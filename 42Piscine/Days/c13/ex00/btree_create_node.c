#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*tree;

	tree = malloc (sizeof(t_btree));
	if (!tree)
		return (0);
	tree->right = 0;
	tree->left = 0;
	tree->item = item;
}

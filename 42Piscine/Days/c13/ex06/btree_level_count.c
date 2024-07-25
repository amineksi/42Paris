#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	if (!root)
        return 0;
    if (root)
    {
        if (!root->left && !root->right)
            return 1;
        if (btree_level_count(root->left) > btree_level_count(root->right))
            return 1 + btree_level_count(root->left);
        else
            return 1 + btree_level_count(root->right);
    }
}

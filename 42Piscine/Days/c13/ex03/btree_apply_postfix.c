#include "ft_btree.h"

void	btree_apply_postfix(t_btree *root, void (*applyf)(void *))
{
    if (root)
    {
        if (root->left)
            btree_apply_postfix(root->left, applyf);
        if (root->right)
            btree_apply_postfix(root->right, applyf);
        applyf(root->item);
    }
}

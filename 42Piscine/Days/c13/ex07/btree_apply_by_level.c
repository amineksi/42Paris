#include "ft_btree.h"

int btree_level_count(t_btree *root)
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

void btree_apply_current_level(t_btree *root, int *t, int level, void (*applyf)(void *item, int current_level, int isfirst))
{
	if (!root)
		return;
	if (level == 0)
	{
		applyf(root->item, t[0], t[1]);
		t[1] = 0;
	}
	else if (level > 0)
	{
		btree_apply_current_level(root->left, t, level - 1, applyf);
		btree_apply_current_level(root->right, t, level - 1, applyf);
	}
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int isfirst))
{
	int i;
	int length;
	int t[2];

	if (!root)
		return;
	length = btree_level_count(root);
	i = 0;
	while (i < length)
	{
		t[0] = i;
		t[1] = 1;
		btree_apply_current_level(root, t, i++, applyf);
	}
}

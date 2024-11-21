#include <unistd.h>

typedef struct s_tree
{
	int value;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

int tree_add(t_tree *tree)
{
	if (!tree)
		return (0);
	return (tree->value + tree_add(tree->left) + tree_add(tree->right));
}

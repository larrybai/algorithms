#include "bstree.h"

BinTree *binTreeCreate()
{
	BinTree *t;
	
	if ((t = malloc(sizeof(BinTree))) == NULL)
		return NULL;

	t->size = 0;
	t->root = NULL;

	return t; 
}

TreeNode *binTreeAddNode(BinTree *tree, void *value)
{
	TreeNode *node;
	TreeNode *child = tree->root;
	TreeNode *parent = NULL;

	if ((node = malloc(sizeof(TreeNode))) == NULL)
		return NULL;
	node->value = value;
	node->lchild = node->rchild = NULL;

	while (child) {
		parent = child;
		if (treeCompareVal(tree, value, parent->value) == TREE_LTE)
			child = parent->lchild;
		else
			child = parent->rchild;
	}
	
	if (parent == NULL) {
		tree->root = malloc(sizeof(TreeNode));
		tree->root->value = value;
		tree->root->lchild = tree->root->rchild = NULL;
	} else {
		if (treeCompareVal(tree, value, parent->value) == TREE_LTE)
			parent->lchild = node;
		else
			parent->rchild = node;
	}
	tree->size++;

	return node;
}

void binTreeInOrderTraverse(BinTree *tree, TreeNode *node)
{
	if (node == NULL)
		return;
	binTreeInOrderTraverse(tree, node->lchild);
	nodeVisit(tree, node);
	binTreeInOrderTraverse(tree, node->rchild);
}

static int count = 0;
void binTreeVisitKthNode(BinTree *tree, TreeNode *node, int k)
{
	if (node == NULL)
		return;
	binTreeVisitKthNode(tree, node->rchild, k);
	count++;
	if (count == k)
		nodeVisit(tree, node);
	binTreeVisitKthNode(tree, node->lchild, k);
}

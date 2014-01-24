#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <stdio.h>
#include <stdlib.h>

/*
 * 比较返回状态
 */
#define TREE_LTE 0
#define TREE_GT  1

typedef struct TreeFuncType {
	int (*valCompare)(const void *val1, const void *val2);
	void *(*valDup)(const void *val);
	void (*nodeVisit)(const void *val);
} TreeFuncType;

typedef struct treenode {
	void   *value;
	struct treenode *lchild;
	struct treenode *rchild;
} TreeNode;

typedef struct bintree {
	TreeFuncType *type;
	TreeNode *root;
	unsigned int size;
} BinTree;

#define treeCompareVal(tree, val1, val2) \
	(((tree)->type->valCompare) ? \
		(tree)->type->valCompare(val1, val2) : \
		(val1) == (val2))

#define treeSetVal(tree, node, val) do { \
	if (tree->type->valDup) \
		node->val = tree->type->valDup(val); \
	else \
		node->val = val; \
} while (0)

#define nodeVisit(tree, node) do { \
	if (tree->type->nodeVisit) \
		tree->type->nodeVisit(node->value); \
} while (0)

#define binTreeInit(tree, type) do { \
	tree->type = type; \
} while (0)

BinTree *binTreeCreate();
TreeNode *binTreeAddNode(BinTree *, void *);
void binTreeInOrderTraverse(BinTree *, TreeNode *);
void binTreeVisitKthNode(BinTree *, TreeNode *, int);

#endif

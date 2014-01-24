#include "bstree.h"

int intCompare(const void *, const void *);
void intPrint(const void *);

int main(int argc, char *argv[])
{
	int val1, val2, val3;
	TreeFuncType *type = malloc(sizeof(TreeFuncType));
	type->valCompare = intCompare;
	type->valDup = NULL;
	type->nodeVisit = intPrint;

	val1 = 3;
	val2 = 12;
	val3 = 8;

	BinTree *tree = binTreeCreate();
	binTreeInit(tree, type);
	binTreeAddNode(tree, &val1);
	binTreeAddNode(tree, &val2);
	binTreeAddNode(tree, &val3);
	binTreeInOrderTraverse(tree, tree->root);

	return 0;
}

int intCompare(const void *val1, const void *val2)
{
	return (*(int *)val1 > *(int *)val2 ? 1 : 0);
}

void intPrint(const void *val)
{
	printf("%d\n", *(int *)val);
}

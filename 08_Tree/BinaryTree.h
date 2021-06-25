#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/* Binary Tree �� ������ */
typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *pLeft; // left child node
	struct _bTreeNode *pRight; // right child node
} BTreeNode;


/* Binary Tree �� ���� */
// Ʈ�� ��� ����
BTreeNode* btree_make_node(void);

// ��� ������ �б�
BTData btree_get_data(BTreeNode *bt);

// ��� ������ ����
void btree_set_data(BTreeNode *bt, BTData data);

// ����� left sub tree 
BTreeNode* btree_get_left(BTreeNode *bt);

// ����� right sub tree
BTreeNode* btree_get_right(BTreeNode *bt);

// bt�� left �� sub tree ����
void btree_make_left(BTreeNode *bt, BTreeNode *sub);

// bt�� right �� sub tree ����
void btree_make_right(BTreeNode *bt, BTreeNode *sub);

// ���� ������ ����
void btree_delete(BTreeNode *bt);

// Traversing-----------------------------------
// ��带 visit �Ͽ� ����� �����Ϳ� ���� ������ �Լ� (�Լ�������) Ÿ�� ����
typedef void fnVisitNode(BTData data);

// �־��� ��� bt ���� �����Ͽ� traversing �ϸ鼭 
// node �� visit �Ҷ����� action() ����
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action);
void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action);
void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action);

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action);

#endif
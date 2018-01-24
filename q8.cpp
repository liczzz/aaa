#include <iostream>
using namespace std;

struct BiTreeNode {
	int v;
	BiTreeNode* pparent;
	BiTreeNode* pleft;
	BiTreeNode* pright;
};

BiTreeNode* GetNext(BiTreeNode* pNode) {
	if (pNode == nullptr)
		return nullptr;

	BiTreeNode* pnext = nullptr;
	if (pNode->pright != nullptr) {
		BiTreeNode* pright = pNode->pright;
		while (pright->pleft != nullptr)
			pright = pright->pleft;
		pnext = pright;
	}
	else {
		BiTreeNode* pCurrent = pNode;
		BiTreeNode* pParent = pNode->pparent;
		while (pParent != nullptr && pCurrent == pParent->pright) {
			pCurrent = pParent;
			pParent = pParent->pparent;
		}
		pnext = pParent;
	}
	return pnext;
}

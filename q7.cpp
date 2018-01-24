#include <iostream>
using namespace std;

struct BiTreeNode {
	int v;
	BiTreeNode* pleft;
	BiTreeNode* pright;
};

BiTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
	int rootV = startPreorder[0];
	BiTreeNode* root = new BiTreeNode();
	root->v = rootV;
	root->pleft = nullptr;
	root->pright = nullptr;
	if (startPreorder == endPreorder) {
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
/*		else
			throw std::exception("Invalid input!");*/
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootV)
		++rootInorder;

/*	if (rootInorder == endInorder && *rootInorder != rootV) {
		throw std::exception("Invalid input!");
	}*/

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0) {
		root->pleft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder) {
		root->pright = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

BiTreeNode* Construct(int* preorder, int* inorder, int length) {
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length -1);
}

void postorder(BiTreeNode* tree){
	if (tree == nullptr)
		return;
	postorder(tree->pleft);
	postorder(tree->pright);
	cout << tree->v << ", ";

}

int main(void) {
	int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
	BiTreeNode* tree = Construct(preorder, inorder, 8);
	postorder(tree);

	return 0;
}

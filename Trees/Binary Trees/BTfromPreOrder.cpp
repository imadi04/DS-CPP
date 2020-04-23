// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE)
    {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
	if (in[i] == rootData) {
	rootIndex = i;
	break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
	}

	BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
      int size=inLength;
    return buildTreeHelper(inorder, preorder, 0, size - 1, 0, size - 1);
	}

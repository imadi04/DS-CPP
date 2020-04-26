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

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
	if(!root)
        return;
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    BinaryTreeNode<int>*t=new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>*t1=root->left;
    root->left=t;
    t->left=t1;
}

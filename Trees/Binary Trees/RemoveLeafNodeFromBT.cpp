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

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root)
        return NULL;
    if(!root->left && !root->right)
        return NULL;
    BinaryTreeNode<int>* l=removeLeafNodes(root->left);
    BinaryTreeNode<int>*r=removeLeafNodes(root->right);
    root->left=l;
    root->right=r;
    return root;
}

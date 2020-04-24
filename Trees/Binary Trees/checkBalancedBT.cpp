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
#include<algorithm>
int height(BinaryTreeNode<int>*root){
    if(!root)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root)
        return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));

}

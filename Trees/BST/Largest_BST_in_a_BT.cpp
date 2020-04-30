/*Given a Binary tree, find the largest BST subtree. That is, 
you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST..*/
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
#include<climits>
int maximum(BinaryTreeNode<int>*root){
    if(!root)
        return INT_MIN;
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>*root){
    if(!root)
        return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root){
    if(!root)
        return true;
    return (root->data>maximum(root->left)) && (root->data<=minimum(root->right)) && isBST(root->left) && isBST(root->right);

}
int height(BinaryTreeNode<int>*root){
    if(!root)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	if(!root)
        return 0;
    if(isBST(root)){
        int a=height(root);
        return a;
    }
    else{
        int b=largestBSTSubtree(root->left);
        int c=largestBSTSubtree(root->right);
        return max(b,c);
    }
    
}

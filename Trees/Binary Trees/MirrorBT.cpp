
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(!root)
        return;
    BinaryTreeNode<int>* temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

}
int height(BinaryTreeNode<int> *root) {
    
    if(!root)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    if(l>r)
        return 1+l;
    return 1+r;

}

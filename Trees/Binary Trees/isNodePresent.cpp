bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if(!root)
        return NULL;
    if(root->data==x)
        return true;
    bool l=isNodePresent(root->left,x);
    bool r=isNodePresent(root->right,x);
    return l || r;
}
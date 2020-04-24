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

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root)
        return;
    if(root->left && root->right){
        nodesWithoutSibling(root->left);
        nodesWithoutSibling(root->right);
    }
    else if(root->right){
        cout<<root->right->data<<endl;
        nodesWithoutSibling(root->right);
    }
    else if(root->left){
        cout<<root->left->data<<endl;
        nodesWithoutSibling(root->left);
    }

}

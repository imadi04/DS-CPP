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

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    // Write your code here
	if(!root)
        return -1;
    if(root->data==val1 || root->data==val2)
        return root->data;
    int a=lcaBinaryTree(root->left,val1,val2);
    int b=lcaBinaryTree(root->right,val1,val2);
    if(a!=-1 && b!=-1)
        return root->data;
    if(a==-1 && b==-1)
        return -1;
    return a==-1?b:a;
}

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
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root,int &sum){
    if(!root)
        return;
    replaceWithLargerNodesSum(root->right,sum);
    sum=sum+root->data;
    root->data=sum;
    replaceWithLargerNodesSum(root->left,sum);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
   int sum=0;
    replaceWithLargerNodesSum(root,sum);

}

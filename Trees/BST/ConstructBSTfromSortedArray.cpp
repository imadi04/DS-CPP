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
BinaryTreeNode<int>* constructTreeHelper(int *input, int start,int end){
    if(start>end)
        return NULL;
    int mid=(start+end)/2;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(input[mid]);
    root->left=constructTreeHelper(input,start,mid-1);
    root->right=constructTreeHelper(input,mid+1,end);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
     constructTreeHelper(input,0,n-1);
}

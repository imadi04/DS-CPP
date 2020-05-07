/*

Given a binary tree and a number k, print out all root to leaf paths 
where the sum of all nodes value is same as the given number k.


*/

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
#include<string>
void helper(BinaryTreeNode<int> *root, int k,string s){
    if(!root)
        return;
    if(!root->left && !root->right && k-root->data==0){
        s+=to_string(root->data);
        cout<<s<<endl;
    }
    s+=to_string(root->data)+" ";
    if(root->left)
    helper(root->left,k-root->data,s);
    if(root->right)
    helper(root->right,k-root->data,s);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
	helper(root,k,"");
}

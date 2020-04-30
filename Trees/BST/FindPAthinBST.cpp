/
Given a BST and an integer k. Find and return the path from the node with data k and
 root (if a node with data k is present in given BST). Return null otherwise.
Assume that BST contains all unique elements.
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

vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    if(!root)
        return NULL;
    if(root->data==data){
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>*leftoutput=findPath(root->left,data);
    if(leftoutput){
        leftoutput->push_back(root->data);
        return leftoutput;
    }
     vector<int>*rightoutput=findPath(root->right,data);
    if(rightoutput){
        rightoutput->push_back(root->data);
        return rightoutput;
    }
    else
        return NULL;

}

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
vector<int>*longestPath(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        vector<int>* v=new vector<int>();
        return v;
    }
    vector<int>* a=longestPath(root->left);
    vector<int>* b=longestPath(root->right);
    
    if(a->size()>b->size())
    {
        a->push_back(root->data);
        return a;
    }
    else
    {
        b->push_back(root->data);
        return b;
    }
}
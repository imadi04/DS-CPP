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
int findParent(BinaryTreeNode<int> *node,int val,int parent)
{
    if(node==NULL)
        return -1;
    if(node->data==val)
    {
        return parent;
    }
    else
    {
       int  a=-1;
        int b=-1;
        a=findParent(node->left,val,node->data);
        b=findParent(node->right,val,node->data);
        return max(a,b);
    }
}
int getLevel(BinaryTreeNode<int> *node,int data,int level)
{
    if(node==NULL)
    {
        return 0;
    }
    if(node->data==data)
    {
        return level;
    }
    int downlevel=getLevel(node->left,data,level+1);
    if(downlevel!=0)
        return downlevel;
    downlevel=getLevel(node->right,data,level+1);
    return downlevel;
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
int a=getLevel(root,p,1);
    int b=getLevel(root,q,1);
    int f=findParent(root,p,root->data);
    int f1=findParent(root,q,root->data);
    if(f!=f1 && a==b)
        return true;
    else
        return false;
    
}
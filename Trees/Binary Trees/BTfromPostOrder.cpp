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

BinaryTreeNode<int>* getTreeFromPostorderAndInorderHelper(int *postorder,int postStart,int postEnd,int *inorder,int inStart,int inEnd)
{if(postStart>postEnd||inStart>inEnd)
{
    return NULL;
}
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(postorder[postEnd]);
 int rootIndex=-1;
 for(int i=0;i<=inEnd;i++)
 {
     if(root->data==inorder[i])
     {
         rootIndex=i;
             break;
     }
 }
    root->left=getTreeFromPostorderAndInorderHelper(postorder,postStart,postStart+(rootIndex-inStart-1),inorder,inStart,rootIndex-1);
    root->right=getTreeFromPostorderAndInorderHelper(postorder,postStart+(rootIndex-inStart),postEnd-1,inorder,rootIndex+1,inEnd);
 return root;
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) 
{
    // Write your code here
return getTreeFromPostorderAndInorderHelper(postorder,0,postLength-1,inorder,0,inLength-1);
}
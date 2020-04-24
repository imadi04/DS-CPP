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
#include<queue>

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    // Write your code here
	if(!root)
        return;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        int c=0;
        BinaryTreeNode<int>*front=q.front();
        q.pop();
        
        if(!front){
            cout<<endl;
            if(q.empty())
                break;
            q.push(NULL);
        }
            
        if(front){
            	cout<<front->data<<" ";
        if(front->left)
            q.push(front->left);
        if(front->right)
        	q.push(front->right);
        }
    }
}

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
void printDown(BinaryTreeNode<int>*root,int k){
    if(!root || k<0)
        return;
    if(!k){
        cout<<root->data<<endl;
        return;
    }
    printDown(root->left,k-1);
    printDown(root->right,k-1);
    
}
int helper(BinaryTreeNode<int> *root, int node, int k){
    if(!root)
        return -1;
    if(root->data==node){
        printDown(root,k);
        return 0;
    }
    int ld=helper(root->left,node,k);
    if(ld!=-1){
        if(ld+1==k){
            cout<<root->data<<endl;
        }
        else{
            printDown(root->right,k-ld-2);
        }
        return ld+1;
    }
    int rd=helper(root->right,node,k);
    if(rd!=-1){
        if(rd+1==k){
            cout<<root->data<<endl;
        }
        else{
            printDown(root->left,k-rd-2);
        }
        return rd+1;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
	helper(root,node,k);
}

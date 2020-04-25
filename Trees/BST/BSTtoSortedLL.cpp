// Following is the Binary Tree node structure
/**************
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
 
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

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    if(!root)
        return NULL;
    Node<int>*rootHead=new Node<int>(root->data);
    Node<int>* leftHead=constructBST(root->left);
    Node<int>* rightHead=constructBST(root->right);
    Node<int>*temp=leftHead;
    if(!leftHead && rightHead){
        rootHead->next=rightHead;
        return rootHead;
    }
    if(leftHead){
         while(temp->next)
        	temp=temp->next;
    	temp->next=rootHead;
        if(!rightHead)
            return leftHead;
        rootHead->next=rightHead; 
         return leftHead;
    }
    if(!leftHead && !rightHead)
        return rootHead;

   
    
}
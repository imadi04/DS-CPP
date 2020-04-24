/*
Given a binary tree, print the zig zag order i.e print level 1 from left to right, 
level 2 from right to left and so on. 
This means odd levels should get printed from left to right and even level right to left.
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    stack<BinaryTreeNode<int>*>s1,s2;
    s1.push(root);
    //cout<<root->data<<endl;
    while(!s1.empty()){
        BinaryTreeNode<int>*top=s1.top();
        cout<<top->data<<" ";
        s1.pop();
        if(top->left)
            s2.push(top->left);
        if(top->right)
            s2.push(top->right);
        if(s1.empty()){
            cout<<endl;
        }
        else{
            continue;
        }
        while(!s2.empty()){
            BinaryTreeNode<int>*top2=s2.top();
        cout<<top2->data<<" ";
        s2.pop();
            if(top2->right)
                s1.push(top2->right);
            if(top2->left)
                s1.push(top2->left);
            if(s2.empty())
                cout<<endl;
            
        }
        if(s1.empty() && s2.empty())
        	break;
        
    }
    
    

}

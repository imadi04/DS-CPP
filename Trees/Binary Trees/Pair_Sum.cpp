/*Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.*/
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
#include<vector>
#include<algorithm>
vector<int> fillarray(BinaryTreeNode<int>*root,vector<int>&v){
    if(!root)
        return v;
    v.push_back(root->data);
    fillarray(root->left,v);
    fillarray(root->right,v);
    return v;
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	if(!root)
        return;
   vector<int>v;
   fillarray(root,v);
  // for(auto x:v)
      // cout<<x<<" ";
    sort(v.begin(),v.end());
    int i=0,j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==sum){
            int c=0;
             cout<<v[i]<<" "<<v[j]<<endl;
            while(v[j]==v[j-1] && i+1<j){
                j--;
                cout<<v[i]<<" "<<v[j]<<endl;
                c++;
            }
            j+=c;
            i++;
        }
        else if(v[i]+v[j]>sum)
            j--;
        else{
            i++;
        }
    }  
    
    
}

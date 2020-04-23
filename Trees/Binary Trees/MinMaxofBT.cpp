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
 
 // PairAns class -
 class PairAns {
    public :
        int min;
        int max;
 };
 
***************/
//pair<int,int>
#include<algorithm>
PairAns minMax(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
     
    if(!root){
        PairAns p;
        p.min=0;
        p.max=0;
        return p;
    }
    
    int rootData=root->data;
    PairAns ans1=minMax(root->left);
    PairAns ans2=minMax(root->right);
    int leftMax=ans1.max;
    int leftMin=ans1.min?ans1.min:rootData;
    int rightMax=ans2.max;
    int rightMin=ans2.min?ans2.min:rootData;
    PairAns answer;
    answer.max=max(rootData,max(leftMax,rightMax));
    answer.min=min(rootData,min(leftMin,rightMin));
	return answer;
}

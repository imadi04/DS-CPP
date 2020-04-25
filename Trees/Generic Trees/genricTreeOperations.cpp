/*
Input format :
Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Level wise print
Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output :
10:20,30,40
20:40,50
30:
40:
40:
50:
*/

#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <queue>
void printLevelWise(TreeNode<int>* root) {
     queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        cout<<front->data<<":";
        pendingNodes.pop();
        for(int i=0;i<front->children.size();i++){
        	cout<<front->children[i]->data;
            if(i<front->children.size()-1)
                cout<<",";
        	pendingNodes.push(front->children[i]);
    	}
        cout<<endl;
    } 
}


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int numNodes(TreeNodes<int> *root){
    if(!root)
        return 0;
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root) {
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=sumOfNodes(root->children[i]);
    }
    return sum;
}

int height(TreeNode<int>* root) {
    int h=0;
    for(int i=0;i<root->children.size();i++){
        int ans=height(root->children[i]);
        if(ans>h)
            h=ans;
    }
	return 1+h;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    queue<TreeNode<int>*>q;
    q.push(root);
    TreeNode<int> *max=root;
    while(!q.empty()){
        TreeNode<int> *front=q.front();
        q.pop();
        for(int i=0;i<front->children.size();i++){
			
            if(front->children[i]->data>max->data)
                max=front->children[i];
            q.push(front->children[i]);
        }
    }
	return max;
}

void printAllNodesAtDepthK(TreeNode<int>* root,int k){
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printAllNodesAtDepthK(root->children[i],k-1);
    }
}

int numLeafNodes(TreeNode<int>* root) {
    if(!root->children.size())
        return 1;
    int num=0;
    for(int i=0;i<root->children.size();i++){
        int ans=numLeafNodes(root->children[i]);
        num+=ans;
    }
        
	return num;
}

void postOrder(TreeNode<int>* root) {
    if(!root)
        return;
     
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
   cout<<root->data<<" ";

}

void preOrder(TreeNode<int>* root) {
    if(!root)
        return;
     
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preOrder(root->children[i]);
    }
   

}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}

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
int nodesGreaterThanX(TreeNode<int> *root, int x) {
    
    if(!root)
        return 0;
    int ans=0;
    if(root->data>x)
        ans=1;
    for(int i=0;i<root->children.size();i++){
        int say=nodesGreaterThanX(root->children[i],x);
        ans=ans+say;
    }
	return ans;
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

int main() {
    int x;
    cin >> x;
    TreeNode<int>* root = takeInputLevelWise();
    cout << nodesGreaterThanX(root, x) << endl;
}

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
TreeNode<int>* maxSumNode(TreeNode<int> *root){

    queue<TreeNode<int>*>q;
    q.push(root);
    TreeNode<int>*ans=root;
    while(!q.empty()){
        TreeNode<int>* front=q.front();
        q.pop();
        int sum=front->data;
        int max_sum;
        for(int i=0;i<front->children.size();i++){
            sum+=front->children[i]->data;
            q.push(front->children[i]);
        }
        if(sum>max_sum){
            ans=front;
            max_sum=sum;
        }
           
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
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}



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
void secondm(TreeNode<int>* root,TreeNode<int>** first,TreeNode<int>** second){
     if(root==NULL)
         return;
     if(!(*first))
         *first=root;
     else if(root->data>(*first)->data){
         *second=*first;
         *first=root;
     }
     else if(!(*second)||root->data>(*second)->data){
         *second=root;
     }
     for(int i=0;i<root->children.size();i++){
         secondm(root->children[i],first,second);
     }
    }
TreeNode <int>* secondLargest(TreeNode<int> *root) {
   
    TreeNode<int>* second=NULL;
    TreeNode<int>* first=NULL;
    secondm(root,&first,&second);
    if(second==NULL)
        return NULL;
    if(first->data==second->data)
        return NULL;
    return second;
}
#include <climits>

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
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}

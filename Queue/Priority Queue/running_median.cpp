#include<queue>
#include<cstdlib>
using namespace std;
void findMedian(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    priority_queue<int,vector<int>,greater<int>>right;//asce
    priority_queue<int>left;
    left.push(arr[0]);
    cout<<arr[0]<<endl;
    for(int i=1;i<n;i++){
        if(arr[i]>left.top())
            right.push(arr[i]);
        else
            left.push(arr[i]);
        int lsize=left.size(),rsize=right.size();
        if(lsize-rsize>1){
            int t=left.top();
            left.pop();
            right.push(t);
        }
        else if(rsize-lsize>1){
            int t=right.top();
            right.pop();
            left.push(t);
        }
       /// cout<<"lsize:"<<left.size()<<" rigsize:"<<right.size()<<"ltop:"<<left.top()<<endl;
        if(left.size()>right.size()){
            cout<<left.top()<<endl;
        }
        else if(right.size()>left.size())
            cout<<right.top()<<endl;
        else{
            int ans=(left.top()+right.top())/2;
            cout<<ans<<endl;
        }
    }
    

}

#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    priority_queue<int,vector<int>,greater<int>>pq;
    int n=input.size();
    //cout<<n<<endl;
    int fsize=0;
    for(int i=0;i<n;i++){
        vector<int>v;
        v.assign(input[i]->begin(),input[i]->end());
        for(int j=0;j<v.size();j++)
            pq.push(v[j]);
    }
   vector<int>ans;
    int s=pq.size();
  for(int i=0;i<s;i++){
         ans.push_back(pq.top());
        pq.pop();
    }
      return ans;
}

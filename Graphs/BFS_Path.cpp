#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> printBFS(int **edges,int start,int end,int *v,int V){
    unordered_map<int,int>mp;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<V;i++){
            if(edges[t][i] && !v[i]){
                q.push(i);
                v[i]=1;
                mp[i]=t;
                if(t==end)
                    break;
            }
        }
    }
    vector<int>path;
   	int tempEnd=end;
    while(start!=tempEnd){
        path.push_back(tempEnd);
        if(mp.count(tempEnd)){
            int parent=mp[tempEnd];
            mp.erase(tempEnd);
            tempEnd=parent;
        }
        else
            return vector<int>();
    }
    if(!path.empty())
        path.push_back(start);
    return path;
    
}

int main() {
    int V, E,tempX,tempY;
    cin >> V >> E;
    int **edges=new int *[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=edges[b][a]=1;
    }
    int start,end;
    cin>>start>>end;
    int *v=new int[V];
    for(int i=0;i<V;i++)
        v[i]=0;
   // vector<int>ans;
   // 
    vector<int>path=printBFS(edges,start,end,v,V);
    for(auto i:path)
        cout<<i<<" ";
  return 0;
}

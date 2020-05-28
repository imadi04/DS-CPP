#include <iostream>
using namespace std;
vector<int> printDFS(int start,int *v,int end,int V,int **edges){
    if(start==end){
        vector<int>a;
        a.push_back(end);
        return a;
    }
 	v[start]=1;
    for(int i=0;i<V;i++)
    {69
        if(i==start)
        {
            continue;
        }
       	if(edges[start][i]==1)
        {
            if(v[i])
            {
                continue;
            }
            else
            {
                v[i]=1;
                vector<int> a=printDFS(i,v,end,V,edges);
                if(a.size()>0)
                {
                    a.push_back(start);
                    return a;
                }
            }
        }
    }
    vector<int> a;
    return a;
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
    vector<int>ans;
   ans= printDFS(start,v,end,V,edges);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
  return 0;
}

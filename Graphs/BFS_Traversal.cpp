#include<queue>
#include <iostream>
using namespace std;

void print(int **edges,int V,int sv,int *v){
    queue<int>q;
   // cout<<"0"<<" ";
    q.push(sv);
    v[sv]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i=0;i<V;i++){
            if(i==curr)
                continue;
            if(edges[curr][i] && !v[i]){
                q.push(i);
                v[i]=1;
            }
        }
    }
}

int main() {
    int V, E;
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
    int *v=new int[V];
    for(int i=0;i<V;i++)
        v[i]=0;
    for(int i=0;i<V;i++)
        if(!v[i])
            print(edges,V,i,v);
  return 0;
}

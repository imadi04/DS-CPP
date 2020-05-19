/*Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
*/

#include<queue>
#include <iostream>
using namespace std;
bool print(int **edges,int V,int start,int end,int *v){
    queue<int>q;
   // cout<<"0"<<" ";
    q.push(start);
    v[start]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        //cout<<curr<<" ";
        for(int i=0;i<V;i++){
            
            if(i==curr)
                continue;
            if(edges[curr][i] && !v[i]){
                if(i==end)
                    return true;
                q.push(i);
                v[i]=1;
            }
        }
        
    }
    return false;
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
    int start,end;
    cin>>start>>end;
    int *v=new int[V];
    for(int i=0;i<V;i++)
        v[i]=0;
    if(print(edges,V,start,end,v)){
        cout<<"true";
    }
    else
        cout<<"false";

  return 0;
}

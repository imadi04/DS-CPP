#include <bits/stdc++.h>
using namespace std;
int getMinVertex(bool*visited,int* weight,int V)
{
    int minVertex=-1;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && ((minVertex==-1)||(weight[minVertex]>weight[i])))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(int** edges,int V)
{
    int* parent=new int[V];
    int* weight=new int[V];
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<V;i++)
    {
        int mini=getMinVertex(visited,weight,V);
        visited[mini]=true;
        for(int j=0;j<V;j++)
        {
            if(edges[mini][j]!=0)
            {
               if(weight[j]>edges[mini][j] && !visited[j])
               {
                   weight[j]=edges[mini][j];
                   parent[j]=mini;
               }
            }
        }
    }
    for(int i=1;i<V;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    delete [] parent;
    delete [] weight;
    delete [] visited;
}
int main()
{
  int V, E;
  cin >> V >> E;
  int** edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    prims(edges,V);
  return 0;
}
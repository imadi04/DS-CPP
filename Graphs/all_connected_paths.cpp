#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void check(int start,int *v,int V,int **edges,vector<int>&tempPath){
   // vector<int>tempPath;
 	v[start]=1;
    tempPath.push_back(start);
    for(int i=0;i<V;i++)
    {
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
                //v[i]=1;
                //tempPath.push_back(i);
                check(i,v,V,edges,tempPath);
                
            }
        }
    }
    return;
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
   
    int *v=new int[V];
    for(int i=0;i<V;i++)
        v[i]=0;
 	
    vector<vector<int>>components;
    for(int i=0;i<V;i++){
       // cout<<v[i]<<",";
        if(!v[i]){
           vector<int>temp;
            check(i,v,V,edges,temp);
            sort(temp.begin(),temp.end());
           components.push_back(temp);
        }
    }
    for(int i=0;i<components.size();i++){
        for(int j=0;j<components[i].size();j++)
            cout<<components[i][j]<<" ";
        cout<<endl;
    }
  return 0;
}

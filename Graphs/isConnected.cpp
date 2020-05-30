#include <iostream>
using namespace std;
void check(int start,int *v,int end,int V,int **edges){
 	v[start]=1;
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
                v[i]=1;
                check(i,v,end,V,edges);
            }
        }
    }
   // return;
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
 	check(0,v,V-1,V,edges);
    //cout<<V-1<<endl;
    bool ans=true;
    for(int i=0;i<V;i++){
       // cout<<v[i]<<",";
        if(!v[i]){
            ans=false;
            break;
        }
    }
    if(ans)
        cout<<"true";
    else
        cout<<"false";
  return 0;
}

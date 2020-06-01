void check(int start,int *v,int V,int **edges){
 	v[start]=1;
    for(int i=1;i<=V;i++)
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
                check(i,v,V,edges);
                
            }
        }
    }
    return;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here.
    int **edges=new int*[n+1];
    for(int i=0;i<=n;i++){
        edges[i]=new int[n+1];
        for(int j=0;j<=n;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<m;i++){
        edges[u[i]][v[i]]=edges[v[i]][u[i]]=1;
    }
    int *visited=new int[n+1];
    for(int i=0;i<=n;i++)
        visited[i]=0;
    int c=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            c++;
            check(i,visited,n,edges);
        }
    }
    return c;
}
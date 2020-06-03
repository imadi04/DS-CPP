/*
Given a graph with N vertices and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
 */


#include <bits/stdc++.h>
using namespace std;


//Approach 1
int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    unordered_map<int,unordered_set<int> >adj;
    
    for(int i=0;i<m;i++){
        adj[u[i]].insert(v[i]);
        adj[v[i]].insert(u[i]);
    }
    
    
    int thcycle=0;
    for(int i=1;i<=n;i++){
        int node=i;
        
        for(int p=1;p<n;p++){
            for(int q=p+1;q<=n;q++){
                
                if(adj[node].count(p)==0)
                    break;
                if(adj[node].count(q)==0)
                    continue;
                
                if(adj[node].count(p) && adj[node].count(q)){
                    if(adj[p].count(q))
                        thcycle++;
                }
            }
        }
    }
    return thcycle/3;
    
}

//Approach 2
#define NM 105 
vector < int > adj[NM];
int visit[NM];
int solve(int n, int m, vector < int > u, vector < int > v) {
    for (int i = 0; i < m; i++) {
      adj[u[i]].push_back(v[i]);
      adj[v[i]].push_back(u[i]);
    }
    int cycles = 0;
    for (int a = 1; a <= n; a++) {
      for (int j = 1; j <= n; j++) visit[j] = 0;
      for (int j = 0; j < adj[a].size(); j++) {
        visit[adj[a][j]] = 1;
      }
      for (int b = 0; b < adj[a].size(); b++) {
        int u = adj[a][b];
        for (int j = 0; j < adj[u].size(); j++) {
          int v = adj[u][j];
          if (v == a) continue;
          if (visit[v]) // if a,u,v form a cycle :) 
          {
            cycles++;
          }
        }
      }
    }
    return cycles / 6; // A cycle is counted 6 times , (anticlockwise + clockwise )*(from A + from U + from V) }

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
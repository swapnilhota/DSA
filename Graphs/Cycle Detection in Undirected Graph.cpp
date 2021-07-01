/*

Cycle Detection in Undirected Graph

*/

#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> adj, vector<bool> visited, int curr_node, int parent)
{
	visited[curr_node]=true;

	for(auto dest: adj[curr_node])
	{
		if(!visited[dest])
		{
			if(isCycle(adj, visited, dest, curr_node))
			{
				return true;
			}
		}
		else if(dest!=parent)
		{
			return true;
		}
	}

	return false;

}

int main()
{
	int n,m;
	cin>>n>>m;

	vector<vector<int>> adj(n+1);
	
	for(int i=0; i<m; i++)
	{
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> visited(n+1, false);

	for(int i=0; i<n; i++)
	{
		if(!visited[i])
		{
			if(isCycle(adj, visited, i, -1))
			{
				cout<<"Cycle is Present"<<endl;
				return 0;
			}
		}
	}

	cout<<"Cycle is Absent"<<endl;
}

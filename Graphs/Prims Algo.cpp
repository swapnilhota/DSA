#include <bits/stdc++.h>
using namespace std;

int getMinVertex(vector<bool> &visited, vector<int> &weight, int n)
{
    int minVertex;
    int minWt = INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            if(weight[i]<minWt)
            {
                minWt=weight[i];
                minVertex=i;
            }
        }
    }

    return minVertex;
}

void prims(int** edges, int n)
{
    vector<bool> visited(n, false);
    vector<int> parent(n);
    vector<int> weight(n, INT_MAX);

    //src->0
    parent[0] = -1;
    weight[0] = 0;

    for(int i=0; i<n; i++)
    {
        int minVertex = getMinVertex(visited, weight, n);

        visited[minVertex] = true;

        for(int j=0; j<n; j++)
        {
            if(edges[minVertex][j]!=0 && visited[j]==false)
            {
                if(weight[j]>edges[minVertex][j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for(int i=1; i<n; i++)
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
}

int32_t main() 
{
    #ifndef swapnilhota
   	freopen("input.txt", "r", stdin);
   	freopen("output.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, e;
    cin>>n>>e;

    int** edges = new int*[n];
    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            edges[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edges[u][v]=w;
        edges[v][u]=w;
    }

    prims(edges, n);

    for(int i=0; i<n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int wt;
};

bool compare(Edge a, Edge b)
{
    return a.wt<b.wt;
}

int getParent(int* parent, int curr)
{
    if(parent[curr]==curr)
    {
        return curr;
    }
    return getParent(parent, parent[curr]);
}

Edge* kruskal(Edge* edges, int n, int E)
{
    // sort edges in increasing order
    sort(edges, edges+E, compare);

    Edge* output = new Edge[n-1];

    int* parent = new int[n];
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }

    int count=0;
    int i=0;
    //n-1 edges
    while(count<n-1)
    {
        Edge curr = edges[i];
        int srcParent = getParent(parent, curr.src);
        int destParent = getParent(parent, curr.dest);

        if(srcParent!=destParent)
        {
            output[count]=curr;
            count++;
            parent[srcParent]=destParent;
        }
        i++;
    }    

    return output;
}

int32_t main() 
{
    #ifndef swapnilhota
   	freopen("input.txt", "r", stdin);
   	freopen("output.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, E;
    cin>>n>>E;

    Edge* edges = new Edge[E];

    for(int i=0; i<E; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        edges[i].src=a;
        edges[i].dest=b;
        edges[i].wt=c;
    }

    Edge* output = kruskal(edges, n, E);

    for(int i=0; i<n-1; i++)
    {
        if(output[i].src<output[i].dest)
        {
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].wt<<endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].wt<<endl;
        }
    }

    return 0;
}

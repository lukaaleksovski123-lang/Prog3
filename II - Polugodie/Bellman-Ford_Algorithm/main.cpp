#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge
{
    int u,v,w;
};

void bellmanFord(int n, vector<Edge> &edges, int start)
{
    vector<int> dist(n, INT_MAX);

    dist[start] = 0;

    for(int i=0;i<n-1;i++)
    {
        for(auto e : edges)
        {
            if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<"Rastojanie od "<<start<<" do "<<i<<" = "<<dist[i]<<endl;
}

int main()
{
    int n = 5;

    vector<Edge> edges =
    {
        {0,1,6},
        {0,2,7},
        {1,3,5},
        {2,3,-3},
        {3,4,2}
    };

    bellmanFord(n,edges,0);
}
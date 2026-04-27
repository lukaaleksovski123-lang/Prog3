#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(int n, vector<vector<pair<int,int>>> &graf, int start)
{
    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(auto x : graf[u])
        {
            int v = x.first;
            int w = x.second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<"Rastojanie od "<<start<<" do "<<i<<" = "<<dist[i]<<endl;
}

int main()
{
    int n = 5;

    vector<vector<pair<int,int>>> graf(n);

    graf[0].push_back({1,10});
    graf[0].push_back({2,3});
    graf[1].push_back({3,2});
    graf[2].push_back({1,4});
    graf[2].push_back({3,8});
    graf[3].push_back({4,7});

    dijkstra(n,graf,0);
}
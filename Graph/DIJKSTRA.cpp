#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> PII;
#define ll long long
#define INF 1<<30  //2^30
vector <PII> vec[10010];

int node, edge;
vector <int> dist(100010, INF);

void shortestPath(int source)
{
    priority_queue <PII, vector<PII>, greater<PII> > pq;
    pq.push(make_pair(0, source));
    dist[source] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        int l = vec[u].size();
        for(int i=0;i<l;i++)
        {
            PII x = vec[u][i];
            int v = x.first;
            int w = x.second;

            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

int main()
{
    cin>>node>>edge;
    int u, v, cost, source;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v>>cost;
        vec[u].push_back(make_pair(v, cost));
        vec[v].push_back(make_pair(u, cost));
    }
    cin>>source;
    shortestPath(source);
    for(int i=0;i<node;i++)
        cout<<source<< " -- " <<i<< " = " <<dist[i]<<endl;
    return 0;
}


/*
9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 3 7
2 5 4
6 5 2
2 8 2
8 6 6
3 5 14
3 4 9
5 4 10
0
*/

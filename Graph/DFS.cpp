#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define N 100010
#define pi acos(-1)

vector <int> vec[N];
int dis[N];
int visited[N];
int parent[N];

int node, edge;

void DFS(int node)
{
    if(visited[node]==1)
        return;
    visited[node] = 1;
    int l = vec[node].size();
    for(int i=0;i<l;i++)
    {
        if(visited[vec[node][i]]==0)
        {
            parent[vec[node][i]] = node;
            dis[vec[node][i]] = dis[node] + 1;
            DFS(vec[node][i]);
        }
    }
}

int main()
{
    cin>>node>>edge;
    int u, v, root;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cin>>root;
    dis[root] = 0;
    parent[root] = -1;
    memset(visited, 0, sizeof(visited));
    DFS(root);
    cout<<endl;
    cout<<"Distances: "<<endl;
    for(int i=1;i<=node;i++)
        cout<<i<< "-" <<dis[i]<<endl;
    cout<<endl;
    cout<<"Parents: "<<endl;
    for(int i=1;i<=node;i++)
        cout<<i<< "-" <<parent[i]<<endl;
    return 0;
}

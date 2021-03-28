#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define N 100010
#define pi acos(-1)

vector <int> vec[N];
int dis[N];
int visited[N];
int parent[N];

int node, edge;

void BFS(int node)
{
    queue <int> q;
    dis[node] = 0;
    memset(visited, 0, sizeof(visited));
    q.push(node);
    visited[node] = 1;
    parent[node] = -1;
    int x, l;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        l = vec[x].size();
        for(int i=0;i<l;i++)
        {
            if(visited[vec[x][i]]==0)
            {
                visited[vec[x][i]] = 1;
                dis[vec[x][i]] = dis[x] + 1;
                q.push(vec[x][i]);
                parent[vec[x][i]] = x;
            }
        }
        //cout<<x<< " ";
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
    cout<<endl;
    BFS(root);
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


/*
12 11
1 2
1 3
1 4
2 5
2 6
4 7
4 8
5 9
5 10
7 11
7 12
1
*/

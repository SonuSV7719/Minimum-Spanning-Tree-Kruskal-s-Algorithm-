#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N], size[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find(int v)
{
    if(parent[v] == v)
        return parent[v];
    return parent[v] =  find(parent[v]);
}

void Union(int a, int b)
{
    // cout<<"Entering a: "<<a<<" b: "<<b<<endl;
    a = find(a);
    b = find(b);
    // cout<<"a: "<<a<<" b: "<<b<<endl;
    if (a != b)
    {
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int v, e;
    cout<<"Enter Total No. of vertices and edges: ";
    cin>>v>>e;
    vector<pair<int, pair<int, int> > > edges;
    for(int i = 0; i<e; i++)
    {
        int x, y, wt;
        cout<<"Enter vertices where edge is present with weight: ";
        cin>>x>>y>>wt;
        edges.push_back({wt,{x, y}});

    }
    int totalCost = 0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i<v; i++) make(i);
    for(int i = 0; i<edges.size(); i++)
    {
        int wt = edges[i].first;
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        if (find(x) == find(y)) continue;
        Union(x, y);
        totalCost += wt;
        cout<< x <<" "<< y<<endl; 
    }


    cout<<totalCost<<endl;
    return 0;
}
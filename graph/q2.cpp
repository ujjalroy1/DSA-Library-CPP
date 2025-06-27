#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges, idx;
    cin >> nodes >> edges;

    int visited[nodes + 1];
    vector<pair<int, int>> graph[nodes + 1];
    int cost[nodes + 1];
   

    for (idx = 1; idx <= edges; idx++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;


    while (!minQ.empty())
    {
        

      
    }


    return 0;
}

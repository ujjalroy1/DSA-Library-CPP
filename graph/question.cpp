#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges, idx;
    cin >> nodes >> edges;

    int visited[nodes + 1];
    vector<pair<int, int>> graph[nodes + 1];
    int cost[nodes + 1];
    int prev[nodes + 1];

    for (idx = 0; idx <= nodes; idx++)
    {
        cost[idx] = 1e8;
        prev[idx] = idx;
    }

    for (idx = 1; idx <= edges; idx++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;
    cost[1] = 0;
    minQ.push({0, 1});

    while (!minQ.empty())
    {
        int curr = minQ.top().second;
        int currCost = minQ.top().first;
        minQ.pop();

        for (auto edge : graph[curr])
        {
            int neigh = edge.first;
            int wt = edge.second;

            if ((currCost + wt) < cost[neigh])
            {
                cost[neigh] = currCost + wt;
                minQ.push({cost[neigh], neigh});
                prev[neigh] = curr;
            }
        }
    }

    for (idx = 0; idx <= nodes; idx++)
    {
        cout << cost[idx] << " ";
    }
    cout << endl;


    return 0;
}

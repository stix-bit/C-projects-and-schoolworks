#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 999999;

class Graph 
{
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int v) 
    {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, int weight, bool directed = false) 
    {
        while(u >= vertices || v >= vertices || u < 0 || v < 0)
            {
                cout << "Error: Invalid edge: (" << u << ", " << v << ")\n";
                cout << "Enter a valid edge: ";
                cin >> u >> v;
            }
        adjList[u].push_back({v, weight});
        if (!directed) {
            adjList[v].push_back({u, weight});
        }
    }

    void dijkstra(int start) 
    {
        vector<int> dist(vertices, INF);  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) 
        {
            int currentDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (currentDist > dist[node]) 
            {
                continue;
            }

            for (auto& neighbor : adjList[node]) 
            {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;
                int newDist = dist[node] + edgeWeight;

                if (newDist < dist[nextNode]) 
                {
                    dist[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }

        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < vertices; i++) 
        {
            cout << "To " << i << " -> " << (dist[i] == INF ? "INF" : to_string(dist[i])) << endl;
        }
    }
};

int main() 
{
    // DIJKSTRA'S ALGORITHM 

    Graph graph(4);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 3);

    int startNode;
    cout << "Enter the starting node for Dijkstra's algorithm: ";
    cin >> startNode;

    graph.dijkstra(startNode);

    return 0;
}

#include <iostream>
#include <vector>
    
using namespace std;
    
class Graph 
{
    private:
        int vertices;
        vector<vector<int>> edges; 
    
    public:
        Graph(int v) 
        {
            vertices = v;
        }
    
        void addEdge(int u, int v, int weight) 
        {
            while(u >= vertices || v >= vertices || u < 0 || v < 0)
            {
                cout << "Error: Invalid edge: (" << u << ", " << v << ")\n";
                cout << "Enter a valid edge: ";
                cin >> u >> v;
            }
            edges.push_back({u, v, weight});
        }
    
        void bellmanFord(int start) 
        {
            int INF = 1e9;
            vector<int> dist(vertices, INF);
            dist[start] = 0;
    
            for (int i = 0; i < vertices - 1; i++) 
            {
                for (const auto& edge : edges) 
                {
                    int u = edge[0], v = edge[1], weight = edge[2];
                    if (dist[u] != INF && dist[u] + weight < dist[v]) 
                    {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
    
            for (const auto& edge : edges) 
            {
                int u = edge[0], v = edge[1], weight = edge[2];
                if (dist[u] != INF && dist[u] + weight < dist[v]) 
                {
                    cout << "Graph contains a negative weight cycle!\n";
                    return;
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

        // BELLMAN-FORD'S ALGORITHM - Dijkstra fails when given negative values as edges. Bellman-Ford only applies to directed graphs. 
        // if given an undirected graph, make the undirected graph a directed graph by making separate edges that point to each other 
        // with same weight.

        Graph graph(3);
    
        graph.addEdge(0, 1, 4);
        graph.addEdge(1, 2, -2);
        graph.addEdge(0, 2, 5);
    
        int startNode;
        cout << "Enter the starting node for Bellman-Ford: ";
        cin >> startNode;
    
        graph.bellmanFord(startNode);
    
        return 0;
    }
    
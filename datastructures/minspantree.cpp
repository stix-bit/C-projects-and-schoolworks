#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

    void addEdge(int u, int v, int weight) 
    {
        while(u >= vertices || v >= vertices || u < 0 || v < 0)
            {
                cout << "Error: Invalid edge: (" << u << ", " << v << ")\n";
                cout << "Enter a valid edge: ";
                cin >> u >> v;
            }
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); 
    }

    void primMST() 
    {
        vector<bool> inMST(vertices, false);  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<int> parent(vertices, -1); 
        vector<int> key(vertices, 1e9); 

        key[0] = 0; 
        pq.push({0, 0}); 

        int totalWeight = 0;

        while (!pq.empty()) 
        {
            int u = pq.top().second; 
            pq.pop(); 

            if (inMST[u]) continue; 
            inMST[u] = true; 

            if (parent[u] != -1) 
            {
                totalWeight += key[u]; 
            }

            for (auto& [v, weight] : adjList[u]) 
            {
                if (!inMST[v] && weight < key[v]) 
                {
                    key[v] = weight; 
                    pq.push({key[v], v}); 
                    parent[v] = u;
                }
            }
        }

        cout << "Minimum Spanning Tree Edges:\n";
        for (int i = 1; i < vertices; i++) 
        {
            cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
        }

        cout << "Total weight of the MST: " << totalWeight << endl;
    }
};

int main() 
{
    Graph graph(6);

    graph.addEdge(0, 5, 2);
    graph.addEdge(0, 1, 4);
    graph.addEdge(1, 5, 3);
    graph.addEdge(1, 2, 6);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 5, 1);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 4);

    graph.primMST();

    return 0;
}
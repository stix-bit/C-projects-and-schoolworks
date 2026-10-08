#include <iostream>
#include <vector>
#include <algorithm>

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
        edges.push_back({weight, u, v});
    }

    void dfs(int node, vector<bool>& visited, vector<vector<pair<int, int>>>& adjList) {
        visited[node] = true;
        for (auto& neighbor : adjList[node]) 
        {
            if (!visited[neighbor.first]) 
            {
                dfs(neighbor.first, visited, adjList);
            }
        }
    }

    bool isConnected(int excludeU = -1, int excludeV = -1) 
    {
        vector<vector<pair<int, int>>> adjList(vertices);
        for (auto& edge : edges) 
        {
            int w = edge[0], u = edge[1], v = edge[2];
            if ((u == excludeU && v == excludeV) || (u == excludeV && v == excludeU))
                continue;
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        vector<bool> visited(vertices, false);
        
        int startNode = -1;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                startNode = i;
                break;
            }
        }

        if (startNode == -1) return false;  
        dfs(startNode, visited, adjList);

        for (bool v : visited) 
        {
            if (!v) return false;  
        }
        return true;
    }

    void reverseDeleteMST() 
    {
        sort(edges.rbegin(), edges.rend()); 
        vector<vector<int>> mstEdges; 
        int totalWeight = 0;

        for (auto it = edges.begin(); it != edges.end(); ) 
        {
            int w = (*it)[0], u = (*it)[1], v = (*it)[2];

            if (isConnected(u, v)) 
            {
                it = edges.erase(it); 
            } 
            else 
            {
                totalWeight += w; 
                mstEdges.push_back({w, u, v});
                ++it;
            }
        }

        cout << "Minimum Spanning Tree Edges:\n";
        for (auto& edge : mstEdges) 
        {
            cout << edge[1] << " - " << edge[2] << " (Weight: " << edge[0] << ")\n";
        }
        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};

int main() {
    Graph graph(6); // MINIMUM SPANNING TREE - REVERSE-DELETE ALGORITHM

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 9);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 5, 7);

    graph.reverseDeleteMST();

    return 0;
}

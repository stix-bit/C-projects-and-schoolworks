#include <iostream>
#include <vector>

using namespace std;

class Graph 
{
private:
    int vertices;
    vector<vector<int>> adjList;
    vector<pair<int, int>> spanningTreeEdges;

public:
    Graph(int v) 
    {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) 
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void buildSpanningTree(int start) 
    {
        vector<bool> visited(vertices, false);
        dfs(start, visited);

        cout << "Spanning Tree Edges:\n";
        for (auto edge : spanningTreeEdges) 
        {
            cout << edge.first << " - " << edge.second << endl;
        }
    }

private:
    void dfs(int node, vector<bool>& visited) 
    {
        visited[node] = true;

        for (int neighbor : adjList[node]) 
        {
            if (!visited[neighbor]) 
            {
                spanningTreeEdges.push_back({node, neighbor});
                dfs(neighbor, visited);
            }
        }
    }
};

int main() 
{
    Graph graph(6); // Spanning Tree

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    graph.buildSpanningTree(0);

    return 0;
}

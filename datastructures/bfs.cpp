#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

class Graph 
{
private:
    int vertices; 
    vector<vector<int>> adjList; 

public:
    Graph(int v) 
    {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, bool directed = false) 
    {
        while(u >= vertices || v >= vertices || u < 0 || v < 0)
            {
                cout << "Error: Invalid edge: (" << u << ", " << v << ")\n";
                cout << "Enter a valid edge: ";
                cin >> u >> v;
            }
        adjList[u].push_back(v);
        if (!directed) 
        {
            adjList[v].push_back(u);
        }
    }

    void BFS(int start) 
    {
        vector<bool> visited(vertices, false); 
        queue<int> q; 
        visited[start] = true; 
        q.push(start);

        cout << "BFS Traversal starting from node " << start << ": ";

        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) 
            {
                if (!visited[neighbor]) 
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void printGraph() 
    {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++) 
        { 
            cout << i << " -> ";
            for (int neighbor : adjList[i]) 
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    int vertices, edges;
    bool isDirected;

    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
   
    cout << "Is the graph directed? (1 for yes, 0 for no): ";
    cin >> isDirected;

    Graph graph(vertices);

    cout << "Enter " << edges << " edges (format: u v):\n";
    for (int i = 0; i < edges; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v, isDirected);
    }

    graph.printGraph();

    int startNode;
    cout << "\nEnter starting node for BFS: ";
    cin >> startNode;

    graph.BFS(startNode);

    return 0;
}

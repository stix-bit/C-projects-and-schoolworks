#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
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

    int findParent(int node, vector<int>& parent) 
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) 
    {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (rootU != rootV) 
        {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else 
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end()); 

        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);

        for (int i = 0; i < vertices; i++) 
            parent[i] = i;

        int totalWeight = 0;
        cout << "Minimum Spanning Tree Edges:\n";

        for (auto& edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (findParent(u, parent) != findParent(v, parent)) {
                cout << u << " - " << v << " (Weight: " << weight << ")\n";
                cout << "Current Total Weight: " << totalWeight << " + " << weight << " = ";
                totalWeight += weight;
                cout << totalWeight << endl;
                unionSets(u, v, parent, rank);
            }
        }

        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};

int main() {
    // MINIMUM SPANNING TREE - KRUSKAL'S ALGORITHM
    Graph graph(5);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    graph.kruskalMST();

    return 0;
}

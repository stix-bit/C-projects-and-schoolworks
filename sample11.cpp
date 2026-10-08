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
        edges.push_back({weight, u, v});
    }

    int findParent(int node, vector<int>& parent) 
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
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

    void boruvkaMST() 
    {
        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);
        vector<int> cheapest(vertices, -1);

        for (int i = 0; i < vertices; i++) 
            parent[i] = i;

        int totalWeight = 0;
        int components = vertices;

        cout << "Minimum Spanning Tree Edges:\n";

        while (components > 1) 
        {
            fill(cheapest.begin(), cheapest.end(), -1);

            for (int i = 0; i < edges.size(); i++) 
            {
                int u = edges[i][1];
                int v = edges[i][2];
                int weight = edges[i][0];

                int rootU = findParent(u, parent);
                int rootV = findParent(v, parent);

                if (rootU != rootV) 
                {
                    if (cheapest[rootU] == -1 || edges[cheapest[rootU]][0] > weight)
                        cheapest[rootU] = i;
                    if (cheapest[rootV] == -1 || edges[cheapest[rootV]][0] > weight)
                        cheapest[rootV] = i;
                }
            }

            for (int i = 0; i < vertices; i++) 
            {
                if (cheapest[i] != -1) {
                    int u = edges[cheapest[i]][1];
                    int v = edges[cheapest[i]][2];
                    int weight = edges[cheapest[i]][0];

                    if (findParent(u, parent) != findParent(v, parent)) 
                    {
                        cout << u << " - " << v << " (Weight: " << weight << ")\n";
                        totalWeight += weight;
                        unionSets(u, v, parent, rank);
                        components--;
                    }
                }
            }
        }

        cout << "Total Weight of MST: " << totalWeight << endl;
    }
};

int main() 
{
    Graph graph(6); // MINIMUM SPANNING TREE - BORUVKA's ALGORITHM

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 9);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 5, 7);

    graph.boruvkaMST();

    return 0;
}

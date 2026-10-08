#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; 

class Graph 
{
private:
    int vertices;
    vector<vector<int>> dist;

public:
    Graph(int v) 
    {
        vertices = v;
        dist.assign(v, vector<int>(v, INF));


        for (int i = 0; i < v; i++) 
        {
            dist[i][i] = 0;
        }
    }

    void addEdge(int u, int v, int weight) 
    {
        dist[u][v] = weight; 
    }

    void floydWarshall() 
    {
        for (int k = 0; k < vertices; k++) 
        {
            for (int i = 0; i < vertices; i++) 
            {
                for (int j = 0; j < vertices; j++) 
                {
                    if (dist[i][k] != INF && dist[k][j] != INF) 
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        cout << "Shortest distances between every pair of vertices:\n";
        for (int i = 0; i < vertices; i++) 
        {
            for (int j = 0; j < vertices; j++) 
            {
                if (dist[i][j] == INF) 
                {
                    cout << "INF ";
                } else 
                {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() 
{
    Graph graph(4); // SHORTEST PATH

    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 2, 10);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 2);
    graph.addEdge(1, 3, 7);

    cout << endl;
    graph.floydWarshall();

    return 0;
}

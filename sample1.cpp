#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    private:
        vector<vector<int>> adjMatrix;
        int vertices;

    public:
        Graph(int v) {
            vertices = v;
            adjMatrix.resize(v, vector<int>(v, 0));
        }

        void addEdge(int u, int v, bool isDirected = false)
        {   
            //while(u >= vertices || v >= vertices || u < 0 || v < 0)
            //{
            //    cout << "Error: Invalid edge: (" << u << ", " << v << ")\n";
            //    cout << "Enter a valid edge: ";
            //    cin >> u >> v;
            //}

            adjMatrix[u][v] = 1;
            if(!isDirected)
            {
                adjMatrix[v][u] = 1;
            }
        }

        void display()
        {
            cout << "Adjacency Matrix: \n";
            for(int i = 0; i < vertices; i++)
            {
                for(int j = 0; j < vertices; j++)
                {
                cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    // ADJACENCY MATRIX

    int vertices = 4;
    Graph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(0, 2);

    graph.display();


    return 0;
}

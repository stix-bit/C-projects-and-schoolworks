#include <iostream>
#include <vector>

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

        void addEdge(int u, int v, bool isDirected = false)
        {
            //while(u >= vertices || v >= vertices || u < 0 || v < 0)
            //{
            //    cout << "Error: Invalid edge: (" << u << ", " << v << ")\n";
            //    cout << "Enter a valid edge: ";
            //    cin >> u >> v;
            //}
            
            adjList[u].push_back(v);
            if(!isDirected)
            {
                adjList[v].push_back(u);
            }
        }

        void display()
        {
            for(int i = 0; i < vertices; i++)
            {
                cout << i << " -> ";
                for(int neighbor : adjList[i])
                {
                    cout << neighbor << " ";
                }
                cout << endl;
            }
        }
    
};

int main()
{
    // ADJACENCY LIST

    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;
    bool isDirected;

    cout << "Is the graph directed? (1 for yes, 0 for no): ";
    cin >> isDirected;
    
    Graph graph(vertices);

    cout << "Enter " << edges << " edges (format: u v): \n";
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v, isDirected);
    }

    graph.display();

    /*
    int vertices = 5;
    Graph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);

    graph.display();

    */
    

    return 0;
}

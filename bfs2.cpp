#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph{
    public:
    int V;
    bool isdirected;
    vector<vector<int>> adj;

    Graph(int num_vertices, bool directed = true){
        V = num_vertices;
        isdirected =directed;
        adj.resize(V);
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
        if(!isdirected){
            adj[v].push_back(u);
        }
    }
    
    void BFS(int s){
        vector <bool> visited(V,false);
        queue <int> q;
        visited[s] = true;
        q.push(s);

        while(!q.empty()){
            int current = q.front();
            q.pop();
            cout << current <<" ";

            for( auto i : adj[current]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void DFS(int s){
        vector<bool> visited(V, false);
        stack<int> stk;
        stk.push(s);
        visited[s] = true;

        while (!stk.empty()) {
            int current = stk.top();
            stk.pop();
            cout << current << " ";

            for (auto i : adj[current]) {
                if (!visited[i]) {
                    visited[i] = true;
                    stk.push(i);
                }
            }
        }
    }
};

int main(){
    char choice;
    bool isDirected;

    cout << "Is the graph directed? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
        isDirected = true;
    else
        isDirected = false;

    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cin.ignore();

    Graph graph(numVertices, isDirected);

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    int u, v;
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        cin >> u >> v;
        graph.add_edge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex;

    cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    graph.BFS(startVertex);
    cout << endl;

    cout << "DFS Traversal starting from vertex " << startVertex << ": ";
    graph.DFS(startVertex);
    cout << endl;

    return 0;
}

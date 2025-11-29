#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int adj[100][100];

 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int src;
    cin >> src;

    int dist[100];
    bool visited[100] = {false};

    
    for (int i = 0; i < n; i++)
        dist[i] = 999999;

    dist[src] = 0;

   
    for (int step = 0; step < n; step++) {

        int u = -1;

       
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = true;

      
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

   
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";

    return 0;
}

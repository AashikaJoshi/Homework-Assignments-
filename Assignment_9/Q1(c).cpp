#include <iostream>
using namespace std;

int parent[100];

int findSet(int x) {
    if (parent[x] == x) return x;
    parent[x] = findSet(parent[x]);
    return parent[x];
}


void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    parent[b] = a;
}

struct Edge {
    int u, v, w;
};

int main() {
    int n, e;
    cin >> n >> e;

    int adj[100][100] = {0};

    Edge edges[100];
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        adj[edges[i].u][edges[i].v] = edges[i].w;
        adj[edges[i].v][edges[i].u] = edges[i].w;
    }

   
    for (int i = 0; i < n; i++) parent[i] = i;

   
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int kruskalCost = 0;
    for (int i = 0; i < e; i++) {
        int pu = findSet(edges[i].u);
        int pv = findSet(edges[i].v);

        if (pu != pv) {
            kruskalCost += edges[i].w;
            unionSet(pu, pv);
        }
    }


    int key[100], parentPrim[100];
    bool inMST[100] = {false};

    for (int i = 0; i < n; i++) {
        key[i] = 1e9;
        parentPrim[i] = -1;
    }

    key[0] = 0;

    for (int c = 0; c < n; c++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parentPrim[v] = u;
            }
        }
    }

    int primCost = 0;
    for (int i = 1; i < n; i++) {
        primCost += adj[i][parentPrim[i]];
    }

    cout << kruskalCost << endl;
    cout << primCost << endl;

    return 0;
}

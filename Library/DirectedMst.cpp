struct Edge {
  int u, v, cost;
};
Edge edge[1111];

int directed_mst(int V, int E, int root) {
  static int pred[33], best[33], id[33], vis[33];
  int res = 0;
  while (true) {
    memset(best, 0x7f, sizeof(best));
    //find minimum incident edges
    for (int e = 0, u, v; e < E; e++) {
      u = edge[e].u;
      v = edge[e].v;
      if (u != v && edge[e].cost < best[v]) {
        best[v] = edge[e].cost;
        pred[v] = u;
      }
    }
    memset(vis, -1, sizeof(vis));
    memset(id, -1, sizeof(id));
    best[root] = id[root] = 0;
    int nV = 1, nE = 0;
    //TODO: improve from current O(V^2)
    for (int v = 0, at; v < V; v++) { //find cycles
      res += best[v];
      for (at = v; id[at] == -1 && vis[at] != v; at = pred[at])
        vis[at] = v;
      if (id[at] == -1) {
        for (int x = pred[at]; x != at; x = pred[x])
          id[x] = nV;
        id[at] = nV++;
      }
    }
    if (nV == 1)
      break;
    for (int v = 0; v < V; v++)
      if (id[v] == -1)
        id[v] = nV++;
    for (int e = 0, u, v; e < E; e++) {
      u = edge[e].u;
      v = edge[e].v;
      if (id[u] != id[v]) {
        edge[nE++] = {id[u], id[v], edge[e].cost - best[v]};
      }
    }
    V = nV, E = nE;
    root = 0;
  }
  return res;
}

#include "Azn.cpp"

namespace simple {
const int k_max_len = 410;
int matchLeft[k_max_len], matchRight[k_max_len];
bool seen[k_max_len];
int graph[k_max_len][k_max_len], degree[k_max_len];

bool canMatch(int guy) {
  for (int i = 0; i < degree[guy]; i++) {
    if (seen[graph[guy][i]])
      continue;
    int girl = graph[guy][i];
    seen[girl] = true;
    if (matchRight[girl] < 0 || canMatch(matchRight[girl])) {
      matchLeft[guy] = girl;
      matchRight[girl] = guy;
      return true;
    }
  }
  return false;
}

int maxMatching(int guys) {
  memset(matchLeft, 0xFF, sizeof (matchLeft));
  memset(matchRight, 0xFF, sizeof (matchRight));
  int matches = 0;
  for (int i = 0; i < guys; i++) {
    memset(seen, false, sizeof (seen));
    matches += canMatch(i);
  }
  return matches;
}
}

template <size_t MAXL, size_t MAXR, size_t MAXE> struct BipartiteMatcher {
  #define NIL MAXL
  static const int INF = 13371337;
  int matchleft[MAXL + 1], matchright[MAXR], edgecnt, leftcnt, rightcnt;
  int last[MAXL], to[MAXE], next[MAXE];
  int dist[MAXL + 1], queue[MAXL];

  void init(int boys, int girls) {
    memset(last, -1, sizeof (last));
    edgecnt = 0;
    leftcnt = boys;
    rightcnt = girls;
  }

  void addedge(int boy, int girl) {
    to[edgecnt] = girl;
    next[edgecnt] = last[boy];
    last[boy] = edgecnt++;
  }

  bool bfs() {
    int qf = 0, qb = 0;
    for (int v = 0; v < leftcnt; v++)
      if (matchleft[v] == NIL)
        dist[queue[qb++] = v] = 0;
      else dist[v] = INF;
    for (dist[NIL] = INF; qf < qb; qf++)
      for (int at = queue[qf], e = last[at]; e > -1; e = next[e])
        if (dist[matchright[to[e]]] == INF)
          dist[queue[qb++] = matchright[to[e]]] = dist[at] + 1;
    return dist[NIL] != INF;
  }

  bool dfs(int at) {
    if (at == NIL) return true;
    for (int e = last[at]; e > -1; e = next[e])
      if (dist[matchright[to[e]]] == dist[at] + 1 && dfs(matchright[to[e]])) {
        matchleft[at] = to[e];
        matchright[to[e]] = at;
        return true;
      }
    dist[at] = INF;
    return false;
  }

  int go() {
    fill(matchleft, matchleft + leftcnt, NIL);
    fill(matchright, matchright + rightcnt, NIL);
    int matches = 0;
    for (int v = 0; v < leftcnt; v++)
      for (int e = last[v]; e > -1; e = next[e])
        if (matchright[to[e]] == NIL) {
          matchright[to[e]] = v;
          matchleft[v] = to[e];
          matches++;
          break;
        }
    while (bfs())
      for (int v = 0; v < leftcnt; v++)
        if (matchleft[v] == NIL && dfs(v))
          matches++;
    return matches;
  }
} ;
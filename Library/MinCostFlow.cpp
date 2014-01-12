#include "Azn.cpp"

namespace SPFA{

/**
 * spfa, doesnt work with negative cost cycles
 */
template <class Flow, class Cost, size_t MAXV, size_t MAXE> struct MinCostFlow {
  int last[MAXV], to[MAXE << 1], next[MAXE << 1], queue[8 * MAXV], prev[MAXV];
  Flow cap[MAXE << 1], flow[MAXE << 1], amount[MAXV];
  Cost cost[MAXE << 1], dist[MAXV];
  bool vis[MAXV];
  int edgecnt;

  void init() {
    memset(last, -1, sizeof (last));
    edgecnt = 0;
  }

  void __addedge(int s, int t, Flow f, Cost c) {
    to[edgecnt] = t;
    next[edgecnt] = last[s];
    cap[edgecnt] = f;
    flow[edgecnt] = 0;
    cost[edgecnt] = c;
    last[s] = edgecnt++;
  }

  void addedge(int from, int to, Flow flow, Cost cost) {
    __addedge(from, to, flow, cost);
    __addedge(to, from, 0, -cost);
  }

  pair<Flow, Cost> go(int source, int sink) {
    Flow maxflow = 0;
    Cost mincost = 0;
    const Flow INF_FLOW = numeric_limits<Flow>::max();
    const Cost INF_COST = numeric_limits<Cost>::max();
    while (true) {
      fill(dist, dist + MAXV, INF_COST);
      memset(vis, false, sizeof (vis));
      prev[source] = -2;
      dist[source] = 0;
      amount[source] = INF_FLOW;
      int qf = 0, qb = 0;
      queue[qb++] = source;
      vis[source] = true;
      for (; qf < qb; qf++) {
        int at = queue[qf];
        Cost cdist = dist[at];
        for (int id = last[at], v; id != -1; id = next[id]) {
          v = to[id];
          if (flow[id] < cap[id] && cdist + cost[id] < dist[v]) {
            dist[v] = cdist + cost[id];
            prev[v] = id;
            amount[v] = min(amount[at], cap[id] - flow[id]);
            if (!vis[v])
              vis[queue[qb++] = v] = true;
          }
        }
        vis[at] = false;
      }
      if (dist[sink] == INF_COST) break;
      Flow by = amount[sink];
      maxflow += by;
      mincost += dist[sink] * by;
      for (int e = prev[sink]; e > -1; e = prev[to[e ^ 1]])
        flow[e] += by, flow[e ^ 1] -= by;
    }
    return make_pair(maxflow, mincost);
  }

} ;

}

namespace DIJKSTRA {
template <class Flow, class Cost, size_t MAXV, size_t MAXE> struct MinCostFlow {
  typedef long long llong;
  int last[MAXV], to[MAXE << 1], next[MAXE << 1], prev[MAXV];
  priority_queue<llong, vector<llong>, greater<llong> > q;
  Flow cap[MAXE << 1], flow[MAXE << 1], amount[MAXV];
  Cost cost[MAXE << 1], dist[MAXV];
  int edgecnt;

  void init() {
    memset(last, -1, sizeof (last));
    edgecnt = 0;
  }

  void __addedge(int s, int t, Flow f, Cost c) {
    to[edgecnt] = t;
    next[edgecnt] = last[s];
    cap[edgecnt] = f;
    flow[edgecnt] = 0;
    cost[edgecnt] = c;
    last[s] = edgecnt++;
  }

  void addedge(int from, int to, Flow flow, Cost cost) {
    __addedge(from, to, flow, cost);
    __addedge(to, from, 0, -cost);
  }

  pair<Flow, Cost> go(int source, int sink) {
    Flow maxflow = 0;
    Cost mincost = 0;
    const Flow INF_FLOW = numeric_limits<Flow>::max();
    const Cost INF_COST = numeric_limits<Cost>::max();
    while (true) {
      fill(dist, dist + MAXV, INF_COST);
      prev[source] = -2;
      dist[source] = 0;
      amount[source] = INF_FLOW;
      while (!q.empty()) q.pop();
      q.push(source);
      while (!q.empty()) {
        int at = q.top() & 4294967295LL;
        Cost cdist = q.top() >> 32;
        q.pop();
        if (at == sink)
          break;
        if (cdist > dist[at]) continue;
        for (int id = last[at], v; id != -1; id = next[id]) {
          v = to[id];
          if (flow[id] < cap[id] && cdist + cost[id] < dist[v]) {
            dist[v] = cdist + cost[id];
            prev[v] = id;
            amount[v] = min(amount[at], cap[id] - flow[id]);
            q.push(llong(dist[v]) << 32 | v);
          }
        }
      }
      if (dist[sink] == INF_COST) break;
      Flow by = amount[sink];
      maxflow += by;
      mincost += dist[sink] * by;
      for (int e = prev[sink]; e > -1; e = prev[to[e ^ 1]])
        flow[e] += by, flow[e ^ 1] -= by;
    }
    return make_pair(maxflow, mincost);
  }
} ;

}

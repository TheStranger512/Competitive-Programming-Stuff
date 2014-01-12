#include "Azn.cpp"

template <size_t MAXSIZE> struct DisjointSet {
  int tree[MAXSIZE];

  void makeset(int size = MAXSIZE) {
    memset(tree, -1, sizeof (int) * size);
  }

  void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (tree[a] > tree[b]) tree[a] = b;
    else {
      if (tree[a] == tree[b]) tree[a]--;
      tree[b] = a;
    }
  }

  int find(int node) {
    return tree[node] < 0 ? node : (tree[node] = find(tree[node]));
  }
} ;
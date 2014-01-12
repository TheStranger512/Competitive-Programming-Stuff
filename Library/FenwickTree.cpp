#include "Azn.cpp"

template <class T, size_t size> struct FenwickTree {
  T tree[size + 1];

  void init() {
    memset(tree, 0, sizeof (tree));
  }

  void update(int pos, T val) {
    for (int i = pos; i <= size; i += i&-i)
      tree[i] += val;
  }

  T query(int pos) const {
    T ans = 0;
    for (int i = pos; i > 0; i -= i&-i)
      ans += tree[i];
    return ans;
  }

  int lowerbound(T val) {
    int pos = 0, add = 1;
    while (add < size) add <<= 1;
    for (; add > 0; add >>= 1)
      if (pos + add <= size && tree[pos + add] < val)
        val -= tree[pos += add];
    return pos + 1;
  }

} ;

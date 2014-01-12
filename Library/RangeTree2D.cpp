#include "Azn.cpp"

struct Point {
  int x, y;
} ;

struct RangeTree2D {

  struct CompareY {
    const Point* pts;

    bool operator()(int a, int b) const {
      //pln("Comparing", a, b);
      return pts[a].y < pts[b].y;
    }

    CompareY(const Point * pts) {
      this-> pts = pts;
    }

  } ;

  static int* alloc(int size) {
    static int pool[1 << 20], *ptr = pool;
    ptr += size;
    return ptr - size;
  }

  struct Node {
    int* yorder;
    int length;

    void createleaf(const Point* pts, int start, int end) {
      length = end - start + 1;
      yorder = alloc(length);
      for (int i = 0, j = start; i < length; i++, j++)
        yorder[i] = j;
      sort(yorder, yorder + length, CompareY(pts));
      //      for (int i = 0; i < length - 1; i++)
      //        assert(pts[yorder[i]].y <= pts[yorder[i + 1]].y);
    }

    void mergefrom(const Point* pts, const Node& left, const Node & right) {
      //pln(left, right);
      length = left.length + right.length;
      yorder = alloc(length);
      for (int i = 0, p = 0, q = 0; i < length; i++) {
        if (q >= right.length || (p < left.length && pts[left[p]].y <= pts[right[q]].y))
          yorder[i] = left[p++];
        else
          yorder[i] = right[q++];
      }
      //      for (int i = 0; i < length - 1; i++)
      //        assert(pts[yorder[i]].y <= pts[yorder[i + 1]].y);
    }

    int lowerbound(const Point* pts, int val) const {
      int ans = length;
      for (int low = 0, high = length - 1; low <= high; ) {
        int mid = (low + high) >> 1;
        if (pts[yorder[mid]].y >= val)
          high = mid - 1, ans = min(ans, mid);
        else low = mid + 1;
      }
      return ans;
    }

    int upperbound(const Point* pts, int val) const {
      int ans = -1;
      for (int low = 0, high = length - 1; low <= high; ) {
        int mid = (low + high) >> 1;
        if (pts[yorder[mid]].y <= val)
          low = mid + 1, ans = max(ans, mid);
        else high = mid - 1;
      }
      return ans + 1;
    }

    void report(const Point* pts, bool* covered, int y1, int y2) const {
      //assert(y1 <= y2);
      //pln("Node Reporting:", *this);
      //      for (int i = 0; i < length; i++)
      //        cout << pts[yorder[i]] << ' ';
      //      cout << endl;
      int st = lowerbound(pts, y1), ed = upperbound(pts, y2);
      for (int i = st; i < ed; i++)
        covered[yorder[i]] = true;
      // plnarr(yorder + st, yorder + ed);
    }

    int operator[](int pos) const {
      return yorder[pos];
    }

    friend ostream& operator<<(ostream& out, const Node & n) {
      out << '[';
      for (int i = 0; i < n.length; i++) {
        if (i) out << ',';
        out << n[i];
      }
      return out << ']';
    }

  } ;
  Node tree[1 << 19];
  bool covered[1 << 18];
  const Point* pts;
  int size;

  inline int left(int node) {
    return node << 1;
  }

  inline int right(int node) {
    return (node << 1) + 1;
  }

  void build(Point* pts, int size) {
    this->pts = pts;
    this->size = size;
    build(1, 0, size - 1);
  }

  void build(int node, int start, int end) {
    if (start == end || pts[start].x == pts[end].x)
      tree[node].createleaf(pts, start, end);
    else {
      int mid = (start + end) >> 1;
      build(left(node), start, mid);
      build(right(node), mid + 1, end);
      tree[node].mergefrom(pts, tree[left(node)], tree[right(node)]);
    }
    //pln(tree[node]);
  }

  void query(const Point& a, const Point & b) {
    //pln("Querying", a, b);
    query(1, 0, size - 1, a, b);
  }

  int count() const {
    int ans = 0;
    for (int i = 0; i < size; i++) ans += covered[i];
    return ans;
  }

  void query(int node, int start, int end, const Point& a, const Point & b) {
    if (a.x > pts[end].x || b.x < pts[start].x)
      return;
    if (a.x <= pts[start].x && pts[end].x <= b.x)
      tree[node].report(pts, covered, a.y, b.y);
    else {
      int mid = (start + end) >> 1;
      query(left(node), start, mid, a, b);
      query(right(node), mid + 1, end, a, b);
    }
  }

} ;

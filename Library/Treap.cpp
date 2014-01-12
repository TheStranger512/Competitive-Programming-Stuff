#include "Azn.cpp"

template <class T> struct Treap {

  struct Node {
    T key;
    int pri, cnt;
    Node* left, *right;

    void update() {
      cnt = leftcnt() + 1 + rightcnt();
    }

    int leftcnt() {
      return left ? left->cnt : 0;
    }

    int rightcnt() {
      return right ? right->cnt : 0;
    }
  };
  typedef Node* pNode;
  pNode root;

  static pNode make(T val) {
    pNode ptr = new Node();
    ptr->key = val;
    ptr->cnt = 1;
    ptr->pri = rand();
    ptr->left = ptr->right = NULL;
    return ptr;
  }

  static pNode rotateRight(pNode node) {
    static pNode temp;
    temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->update();
    return temp;
  }

  static pNode rotateLeft(pNode node) {
    static pNode temp;
    temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->update();
    return temp;
  }

  pNode insert(pNode at, T val) {
    if (!at)
      return make(val);
    else if (val < at->key) {
      at->left = insert(at->left, val);
      if (at->left->pri < at->pri)
        at = rotateRight(at);
    } else {
      at->right = insert(at->right, val);
      if (at->right->pri < at->pri)
        at = rotateLeft(at);
    }
    at->update();
    return at;
  }

  pNode erase(pNode at, T val) {
    if (!at)
      return NULL;
    if (val < at->key)
      at->left = erase(at->left, val);
    else if (val > at->key)
      at->right = erase(at->right, val);
    else {
      if (at->left == NULL)
        return at->right;
      else if (at->right == NULL)
        return at->left;
      else if (at->left->pri < at->right->pri) {
        at = rotateRight(at);
        at->right = erase(at->right, val);
      } else {
        at = rotateLeft(at);
        at->left = erase(at->left, val);
      }
    }
    at->update();
    return at;
  }

  void erase(T val) {
    root = erase(root, val);
  }

  void insert(T val) {
    root = insert(root, val);
  }

  int get_less(T val) {
    int res = 0;
    for (pNode at = root; at;) {
      if (at->key < val) {
        res += at->leftcnt() + 1;
        at = at->right;
      } else
        at = at->left;
    }
    return res;
  }

  int get_great(T val) {
    int res = 0;
    for (pNode at = root; at;) {
      if (at->key > val) {
        res += at->rightcnt() + 1;
        at = at->left;
      } else
        at = at->right;
    }
    return res;
  }

};

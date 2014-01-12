#include "Azn.cpp"

template <size_t MAXLEN, size_t ALPHABET> struct SuffixAutomaton {

  struct Node {
    Node * child[ALPHABET], *suff, *next;
    int len, pos, cnt;
  } ;
  Node pool[2 * MAXLEN], *root, *nextnode, *last, *first[MAXLEN + 1];

  Node * makenode(int length) {
    memset(nextnode, 0, sizeof (Node));
    nextnode->len = length;
    return nextnode++;
  }

  void init() {
    nextnode = pool;
    last = root = makenode(0);
    root->pos = -1;
    memset(first, 0, sizeof (first));
  }

  void extend(int ch) {
    Node* p = last, *cur = makenode(p->len + 1);
    cur->cnt = 1;
    cur->pos = cur->len - 1;
    for (; p != NULL && p->child[ch] == NULL; p = p->suff)
      p->child[ch] = cur;
    if (p == NULL)
      cur->suff = root;
    else {
      Node* q = p->child[ch];
      if (p->len + 1 == q->len)
        cur->suff = q;
      else {
        Node* copy = makenode(p->len + 1);
        copy->pos = q->pos;
        memcpy(copy->child, q->child, sizeof (q->child));
        copy->suff = q->suff;
        q->suff = cur->suff = copy;
        for (; p != NULL && p->child[ch] == q; p = p->suff)
          p->child[ch] = copy;
      }
    }
    last = cur;
  }

  void go() {
    for (Node* i = pool; i < nextnode; i++) {
      i->next = first[i->len];
      first[i->len] = i;
    }
    for (int len = MAXLEN; len > 0; len--)
      for (Node* i = first[len]; i != NULL; i = i->next)
        i->suff->cnt += i->cnt;
  }
} ;
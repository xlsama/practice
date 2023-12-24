typedef char BiElemType;
typedef struct BiTNode {
  BiElemType c;
  struct BiTNode *lchild;
  struct BiTNode *rchild;
} BiTNode, *BiTree;

// 辅助队列
typedef struct tag {
  BiTree p; // 树的某一个结点的指针
  struct tag *pnext;
} tag_t, *ptag_t;

typedef BiTree ElemType;
typedef struct LinkNode {
  ElemType data;
  struct LinkNode *next;
} LinkNode;
typedef struct {
  LinkNode *front, *rear;
} LinkQueue;

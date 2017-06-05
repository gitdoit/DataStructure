typedef struct QNode{//队列成员数据结构 
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{//队列指针数据结构,头尾指针和next都是同样的指针类型； 
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

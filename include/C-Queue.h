typedef struct QNode{//���г�Ա���ݽṹ 
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{//����ָ�����ݽṹ,ͷβָ���next����ͬ����ָ�����ͣ� 
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){//构造一个头结点，头尾指针都指向这个头结点，该头结点无指向； 
	Q.front = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERFLOW);
	Q.rear = Q.front;
	Q.front->next = NULL;
}

Status EnQueue(LinkQueue &Q,QElemType e){//向队列尾部插入元素e 
	Q.rear->next = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.rear->next) exit(OVERFLOW);
	Q.rear = Q.rear->next;//头指针不动，尾指针指向新构造的节点； 
	Q.rear->data = e;
	Q.rear->next = NULL;
}

Status DeQueue(LinkQueue &Q,QElemType &e){//返回队列首元结点的数据域，并删除首元结点； 
	QueuePtr p = Q.front->next;//p指向首元结点； 
	if(Q.front == Q.rear) return ERROR;
	e = p->data;
	Q.front->next = p->next;//头结点的指针域从新指向原首节点的后面一个节点；
	if(Q.rear == p) Q.rear = Q.front;//如果删掉的是唯一一个节点，那么头尾指针都从新指向头结点； 
	free(p);
	return OK;
	
}

Status QueueEmpty(LinkQueue Q){ //判断队列是否为空，空返回真，不空返回假； 
	if(Q.front == Q.rear) return TRUE;
	else return FALSE;
}

int QueueLength(LinkQueue Q){//返回队列长度； 
	int i = 1;
	QueuePtr p = Q.front->next;
	if(Q.front == Q.rear) return 0;
	while(p != Q.rear){
		i++;
		p = p->next;
	}
	return i;
}

Status DestroyQueue(LinkQueue &Q){//连新指针都不用定义了，直接拿尾指针交替； 
	while(Q.front){
		QueuePtr p;
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
	}
	return OK;
}

Status InitQueue(LinkQueue &Q){//����һ��ͷ��㣬ͷβָ�붼ָ�����ͷ��㣬��ͷ�����ָ�� 
	Q.front = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERFLOW);
	Q.rear = Q.front;
	Q.front->next = NULL;
}

Status EnQueue(LinkQueue &Q,QElemType e){//�����β������Ԫ��e 
	Q.rear->next = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.rear->next) exit(OVERFLOW);
	Q.rear = Q.rear->next;//ͷָ�벻����βָ��ָ���¹���Ľڵ㣻 
	Q.rear->data = e;
	Q.rear->next = NULL;
}

Status DeQueue(LinkQueue &Q,QElemType &e){//���ض�����Ԫ���������򣬲�ɾ����Ԫ��㣻 
	QueuePtr p = Q.front->next;//pָ����Ԫ��㣻 
	if(Q.front == Q.rear) return ERROR;
	e = p->data;
	Q.front->next = p->next;//ͷ����ָ�������ָ��ԭ�׽ڵ�ĺ���һ���ڵ㣻
	if(Q.rear == p) Q.rear = Q.front;//���ɾ������Ψһһ���ڵ㣬��ôͷβָ�붼����ָ��ͷ��㣻 
	free(p);
	return OK;
	
}

Status QueueEmpty(LinkQueue Q){ //�ж϶����Ƿ�Ϊ�գ��շ����棬���շ��ؼ٣� 
	if(Q.front == Q.rear) return TRUE;
	else return FALSE;
}

int QueueLength(LinkQueue Q){//���ض��г��ȣ� 
	int i = 1;
	QueuePtr p = Q.front->next;
	if(Q.front == Q.rear) return 0;
	while(p != Q.rear){
		i++;
		p = p->next;
	}
	return i;
}

Status DestroyQueue(LinkQueue &Q){//����ָ�붼���ö����ˣ�ֱ����βָ�뽻�棻 
	while(Q.front){
		QueuePtr p;
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
	}
	return OK;
}

void InitList(LinkList &L)
{//����һ��ͷָ��L��������һ���յ����Ա�ʹLָ��ͷ��㣻 
	L = (LinkList)malloc(sizeof(LNode));//����һ��ͷ��� 
	if(!L)exit(OVERFLOW);
	L->next = NULL;//��ͷ����ڵ� next��Ա ָ��NULL�� 
}

Status ListInsert(LinkList L, int i ,ElemType e){
	//�������Ԫ�أ� 
	int j = 0;
	LinkList s,p = L;
	while(p && j < i - 1)
	{
		j++;
		p = p->next;
	} 
	if(!p || j > i-1)
	return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;//s������P�����ˣ�����p->next��ǰ����p�ĺ�̣� 
	p->next = s;
	return OK;
}

Status ListDelete(LinkList &L,int i ,ElemType &e)
{
	int j = 0;//��������ʼֵΪ0��
	LinkList q,p = L;//pҲ��Lһ��ָ��ͷ��㣬������pָ��ͷָ�롣
	while(p->next && j < i-1)
	{//Ѱ�Ҵ�ɾ���ڵ㡣�˳�ѭ��ʱp->next��ָ��Ϊ��ɾ���ڵ㡣 
		j++;
		p = p->next;
	} 
	if(!p->next || j > i - 1)
	return ERROR;//�����ɾ���ڵ�ΪNULL�򱨴� 
	q = p->next;//��qָ���ɾ���ڵ㡣 
	p->next = q->next;//��ɾ���ڵ��ǰ����p->next���ղ�ָ���ɾ���ڵ㣬����Ҫ��ǰ��ָ���ɾ���ڵ�ĺ���ˡ� 
	e = q->data;
	free(q);
	return OK;
} 

void  MergeList(LinkList &La,LinkList &Lb,LinkList &Lc)
{//�鲢��������Ϊһ������ 
	LinkList pa,pb,pc;
	pa = La->next;//pa.pbָ��LA��LB����Ԫ��㣻 
	pb = Lb->next;
	Lc = pc = La;//�����ÿ���Lc����La���鲢��������� 
	while(pa && pb)//����һ������ΪNull�����ѭ�� 
	{
		if(pa->data >= pb->data)
		{ 
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(Lb);
}









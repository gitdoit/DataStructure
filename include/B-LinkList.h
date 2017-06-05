void InitList(LinkList &L)
{//产生一个头指针L，并构造一个空的线性表，使L指向头结点； 
	L = (LinkList)malloc(sizeof(LNode));//开辟一个头结点 
	if(!L)exit(OVERFLOW);
	L->next = NULL;//将头结点内的 next成员 指向NULL； 
}

Status ListInsert(LinkList L, int i ,ElemType e){
	//链表插入元素； 
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
	s->next = p->next;//s加塞到P后面了，成了p->next的前驱，p的后继； 
	p->next = s;
	return OK;
}

Status ListDelete(LinkList &L,int i ,ElemType &e)
{
	int j = 0;//计数器初始值为0；
	LinkList q,p = L;//p也和L一样指向头结点，并不是p指向头指针。
	while(p->next && j < i-1)
	{//寻找待删除节点。退出循环时p->next的指向为待删除节点。 
		j++;
		p = p->next;
	} 
	if(!p->next || j > i - 1)
	return ERROR;//如果待删除节点为NULL则报错。 
	q = p->next;//将q指向待删除节点。 
	p->next = q->next;//待删除节点的前驱（p->next）刚才指向待删除节点，现在要将前驱指向待删除节点的后继了。 
	e = q->data;
	free(q);
	return OK;
} 

void  MergeList(LinkList &La,LinkList &Lb,LinkList &Lc)
{//归并两个链表为一个链表； 
	LinkList pa,pb,pc;
	pa = La->next;//pa.pb指向LA，LB的首元结点； 
	pb = Lb->next;
	Lc = pc = La;//并不用开辟Lc，用La做归并后的新链表 
	while(pa && pb)//若有一个链表为Null则结束循环 
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









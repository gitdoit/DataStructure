#define ClearBiTree DestroyBiTree


void InitBiTree(BiTree &T){//����յĶ����� 
	T = NULL;
} 

void DestroyBiTree(BiTree &T){//ʹ�õݹ����ٶ����� 
	if(T){
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);//�ݹ��������������� 
		free(T);//�ͷŽڵ㡣 
		T = NULL;//ָ��Ϊ�� 
	}
} 

void PreOrderTraverse(BiTree T,void(*Visit)(TElemType)){//������������� 
	if(T){
		Visit(T->data);
		PreOrderTraverse(T->lchild,Visit);
		PreOrderTraverse(T->rchild,Visit); 
	}
} 

void InOrderTraverse(BiTree T,void(*Visit)(TElemType)){//��������������� 
	if(T){
	InOrderTraverse(T->lchild,Visit);
	Visit(T->data);
	InOrderTraverse(T->rchild,Visit);
	}
}

Status BiTreeEmpty(BiTree T){//������Ϊ�շ����棬����Ϊ�� 
	if(T)
		return FALSE;
	else
		return TRUE;
} 

int BiTreeDepth(BiTree T){//�õ��������Ĳ�������ȣ��� 
	int i,j;
	if(!T)
		return 0;
	i = BiTreeDepth(T->lchild);//�ȱ������������õ������������ 
	j = BiTreeDepth(T->rchild);//�ٱ������������õ������������ 
	return i > j ? i+1 : j+1;//ÿִ�е��ˣ��Ƚ�i,j�Ĵ�С�����ؽ���� 
}

TElemType Root(BiTree T){//�õ� ����������ֵ 
	if(BiTreeEmpty(T))
		return Nil;
	else
	return T->data;
}

TElemType Value(BiTree T){//�õ��������ڵ�T�������� 
	return T->data;
}


//����ķ������õ����У����ｫ�������������Ϊ��������
typedef BiTree QElemType; 
#include <C-Queue.h>
#include <B-Queue.h>


BiTree Point(BiTree T,TElemType s){//���ض�����T��������Ϊs�Ľڵ� 
	LinkQueue q;
	QElemType a;//�����е�������Ϊ���������� 
	if(T){
		InitQueue(q);//��ʼ������ 
		EnQueue(q,T);//��ָ����� 
		while(!QueueEmpty(q)){
			DeQueue(q,a);//����Ԫ�س��ӣ�������a 
			if(a->data == s){//��a����������s������˳�ѭ��������a 
				DestroyQueue(q);
				return a;
			}
			if(a->lchild)//�����Ӳ�������� 
				EnQueue(q,a->lchild);
			if(a->rchild)//���Һ��Ӳ�������� 
				EnQueue(q,a->rchild);
		}
		DestroyQueue(q);//��û���ҵ������ٶ��У�����NULL 
	}
	return NULL;
}

TElemType LeftChild(BiTree T,TElemType e){//����������Ϊe������ 
	BiTree a;
	if(T){
		a = Point(T,e);
		if(a && a->lchild)
			return a->lchild->data;
	}
	return Nil;
}

TElemType RightChild(BiTree T,TElemType e){//����������Ϊe���Һ��� 
	BiTree a;
	if(T){
		a = Point(T,e);
		if(a && a->rchild)
		return a->rchild->data; 
	}
	return Nil;
}

Status DeleteChild(BiTree p,int LR){//����LRѡ��ɾ���ڵ�p�����ӻ��Һ��� 
	if(p){
		if(LR == 0)
			ClearBiTree(p->lchild);
		else if(LR == 1)
			ClearBiTree(p->rchild);	
		return OK;	
	}
	return ERROR;
}

void PostOrderTraverse(BiTree T,void(* Visit)(TElemType)){//�������������T 
	if(T){
		PostOrderTraverse(T->lchild,Visit);
		PostOrderTraverse(T->rchild,Visit);
		Visit(T->data);
	} 
} 

void LevelOrderTraverse(BiTree T,void(* Visit)(TElemType)){//������������� 
	LinkQueue q;//����һ������ָ�� 
	QElemType a;//����һ��������ָ�� 
	if(T){
		InitQueue(q);//����һ������qָ���� 
		EnQueue(q,T);//����T��� 
		while(!QueueEmpty(q)){//���в��� 
			DeQueue(q,a);//����Ԫ�س��ӣ���ֵ��a 
			Visit(a->data);//��ӡa�������� 
			if(a->lchild)//�����Һ��Ӳ�������� 
				EnQueue(q,a->lchild);
			if(a->rchild);
				EnQueue(q,a->rchild); 
		}
		printf("\n");
	}
}
void CreateBiTree(BiTree &T){//������������ 
	TElemType ch;
	cin>>ch;//form�ɶ���Ϊ"%d",��"%c"
	 
	if(ch == Nil)
	 	T = NULL;
	else{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);//����ݹ� 
		CreateBiTree(T->rchild);
	}
	return;
}

TElemType Parent(BiTree T,TElemType e){//��e��T�ķǸ��ڵ㣬�򷵻�����˫�� 
	LinkQueue q;
	QElemType a;
	if(T){
		InitQueue(q);
		EnQueue(q,T);
		while(!QueueEmpty(q)){
			DeQueue(q,a);
			if(a->lchild && a->lchild->data == e || a->rchild && a->rchild->data == e)
				return a->data;//��e��a�����ӻ��ֺ�����򷵻�a��������
			else{//��e����a�����Һ���������Һ�����Ӽ���Ѱ����ȥ 
				if(a->lchild)
					EnQueue(q,a->lchild);
				if(a->rchild);
					EnQueue(q,a->rchild);
			} 
		}
	} 
	return Nil; 
} 

TElemType LeftSibling(BiTree T,TElemType e){//����������Ϊe�Ľڵ�����ֵ� 
	TElemType a;
	BiTree p;
	if(T){//������T�ǿ� 
		a = Parent(T,e);//�õ�e��˫�׵������� 
		if(a != Nil){//���ҵ�˫�� 
			p = Point(T,a);//�õ�˫�׵Ľڵ�ָ�� 
			if(p->lchild && p->rchild && p->rchild->data == e)//����˫�׽ڵ������Һ��ӣ����Һ��ӵ������������e��ͬ 
				return p->lchild->data;//��ýڵ�Ϊ��Ҫ�ҵ����ֵ� 
		}
	}
	return Nil;
} 

TElemType RigthSibling(BiTree T,TElemType e){//����������Ϊe�Ľڵ�����ֵ� 
	TElemType a;
	BiTree p;
	if(T){//������T�ǿ� 
		a = Parent(T,e);//�õ�e��˫�׵������� 
		if(a != Nil){//���ҵ�˫�� 
			p = Point(T,a);//�õ�˫�׵Ľڵ�ָ�� 
			if(p->lchild && p->rchild && p->lchild->data == e)//����˫�׽ڵ������Һ��ӣ������ӵ������������e��ͬ 
				return p->rchild->data;//��ýڵ�Ϊ��Ҫ�ҵ����ֵ� 
		}
	}
	return Nil;
} 

Status InsertChild(BiTree p,int LR,BiTree c){//��������T�е�ĳ�ڵ�P����ڵ�c��c���Һ��ӣ�ԭP����/�Һ��ӳ�Ϊc���Һ���
	if(p){
		if(LR == 0){
			c->rchild = p->lchild;
			p->lchild = c;
		}
		else{
			c->rchild = p->rchild;
			p->rchild = c;
		}
		return OK;
	} 
	return ERROR;
}  

typedef BiTree SElemType;//ջ��Ԫ�����Ͷ���Ϊ������ 
#include<C-Stack.h>
#include<B-Stack.h> 

void InOrDerTraverse1(BiTree T,void(* Visit)(TElemType)){//�ǵݹ��������˫���� 
	SqStack S;
	InitStack(S);//����ջS 
	while(T||!StackEmpty(S)){//T��ջ���� 
		if(T){//���������� ��ֱ���ײ� 
			Push(S,T);//T��ջ 
			T = T->lchild;//Tָ�����ӣ�����ѭ������ 
		}
		else{//���׺�ָ����ջ 
			Pop(S,T);//˫�׳�ջ 
			Visit(T->data);//��ӡ˫�� 
			T = T->rchild;//���������� 
		}
	}//����Ϊ�գ��ڵ��ջ����ӡ�ڵ㡣�����ӣ�����Ϊ�գ���˫�׳�ջ�� 
	printf("\n");
	DestroyStack(S);
}


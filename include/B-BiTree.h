#define ClearBiTree DestroyBiTree


void InitBiTree(BiTree &T){//构造空的二叉树 
	T = NULL;
} 

void DestroyBiTree(BiTree &T){//使用递归销毁二叉树 
	if(T){
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);//递归销毁左右子树； 
		free(T);//释放节点。 
		T = NULL;//指针为空 
	}
} 

void PreOrderTraverse(BiTree T,void(*Visit)(TElemType)){//先序遍历二叉树 
	if(T){
		Visit(T->data);
		PreOrderTraverse(T->lchild,Visit);
		PreOrderTraverse(T->rchild,Visit); 
	}
} 

void InOrderTraverse(BiTree T,void(*Visit)(TElemType)){//中序遍历二叉树； 
	if(T){
	InOrderTraverse(T->lchild,Visit);
	Visit(T->data);
	InOrderTraverse(T->rchild,Visit);
	}
}

Status BiTreeEmpty(BiTree T){//二叉树为空返回真，不空为假 
	if(T)
		return FALSE;
	else
		return TRUE;
} 

int BiTreeDepth(BiTree T){//得到二叉树的层数（深度）。 
	int i,j;
	if(!T)
		return 0;
	i = BiTreeDepth(T->lchild);//先遍历左子树，得到左子树的深度 
	j = BiTreeDepth(T->rchild);//再遍历右子树，得到右子树的深度 
	return i > j ? i+1 : j+1;//每执行到此，比较i,j的大小。返回较深的 
}

TElemType Root(BiTree T){//得到 二叉树根的值 
	if(BiTreeEmpty(T))
		return Nil;
	else
	return T->data;
}

TElemType Value(BiTree T){//得到二叉树节点T的数据域 
	return T->data;
}


//后面的方法会用到队列，这里将队里的数据域定义为二叉树型
typedef BiTree QElemType; 
#include <C-Queue.h>
#include <B-Queue.h>


BiTree Point(BiTree T,TElemType s){//返回二叉树T中数据域为s的节点 
	LinkQueue q;
	QElemType a;//队列中的数据域为二叉树类型 
	if(T){
		InitQueue(q);//初始化队列 
		EnQueue(q,T);//跟指针入队 
		while(!QueueEmpty(q)){
			DeQueue(q,a);//队首元素出队，并赋给a 
			if(a->data == s){//若a的数据域与s相等则退出循环。返回a 
				DestroyQueue(q);
				return a;
			}
			if(a->lchild)//若左孩子不空则入队 
				EnQueue(q,a->lchild);
			if(a->rchild)//若右孩子不空则入队 
				EnQueue(q,a->rchild);
		}
		DestroyQueue(q);//若没有找到则销毁队列，返回NULL 
	}
	return NULL;
}

TElemType LeftChild(BiTree T,TElemType e){//返回数据域为e的左孩子 
	BiTree a;
	if(T){
		a = Point(T,e);
		if(a && a->lchild)
			return a->lchild->data;
	}
	return Nil;
}

TElemType RightChild(BiTree T,TElemType e){//返回数据域为e的右孩子 
	BiTree a;
	if(T){
		a = Point(T,e);
		if(a && a->rchild)
		return a->rchild->data; 
	}
	return Nil;
}

Status DeleteChild(BiTree p,int LR){//根据LR选择删除节点p的左孩子或右孩子 
	if(p){
		if(LR == 0)
			ClearBiTree(p->lchild);
		else if(LR == 1)
			ClearBiTree(p->rchild);	
		return OK;	
	}
	return ERROR;
}

void PostOrderTraverse(BiTree T,void(* Visit)(TElemType)){//后序遍历二叉树T 
	if(T){
		PostOrderTraverse(T->lchild,Visit);
		PostOrderTraverse(T->rchild,Visit);
		Visit(T->data);
	} 
} 

void LevelOrderTraverse(BiTree T,void(* Visit)(TElemType)){//层序遍历二叉树 
	LinkQueue q;//声明一个队列指针 
	QElemType a;//声明一个二叉树指针 
	if(T){
		InitQueue(q);//构造一个队列q指向它 
		EnQueue(q,T);//树根T入队 
		while(!QueueEmpty(q)){//队列不空 
			DeQueue(q,a);//队首元素出队，赋值给a 
			Visit(a->data);//打印a的数据域 
			if(a->lchild)//左孩子右孩子不空则入队 
				EnQueue(q,a->lchild);
			if(a->rchild);
				EnQueue(q,a->rchild); 
		}
		printf("\n");
	}
}
void CreateBiTree(BiTree &T){//先序建立二叉树 
	TElemType ch;
	cin>>ch;//form可定义为"%d",或"%c"
	 
	if(ch == Nil)
	 	T = NULL;
	else{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(!T)
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);//先序递归 
		CreateBiTree(T->rchild);
	}
	return;
}

TElemType Parent(BiTree T,TElemType e){//若e是T的非根节点，则返回它的双亲 
	LinkQueue q;
	QElemType a;
	if(T){
		InitQueue(q);
		EnQueue(q,T);
		while(!QueueEmpty(q)){
			DeQueue(q,a);
			if(a->lchild && a->lchild->data == e || a->rchild && a->rchild->data == e)
				return a->data;//若e在a的左孩子或又孩子里，则返回a的数据域
			else{//若e不在a的左右孩子里，则左右孩子入队继续寻找下去 
				if(a->lchild)
					EnQueue(q,a->lchild);
				if(a->rchild);
					EnQueue(q,a->rchild);
			} 
		}
	} 
	return Nil; 
} 

TElemType LeftSibling(BiTree T,TElemType e){//返回数据域为e的节点的左兄弟 
	TElemType a;
	BiTree p;
	if(T){//二叉树T非空 
		a = Parent(T,e);//得到e的双亲的数据域 
		if(a != Nil){//若找到双亲 
			p = Point(T,a);//得到双亲的节点指针 
			if(p->lchild && p->rchild && p->rchild->data == e)//若该双亲节点有左右孩子，且右孩子的数据域与参数e相同 
				return p->lchild->data;//则该节点为所要找的左兄弟 
		}
	}
	return Nil;
} 

TElemType RigthSibling(BiTree T,TElemType e){//返回数据域为e的节点的右兄弟 
	TElemType a;
	BiTree p;
	if(T){//二叉树T非空 
		a = Parent(T,e);//得到e的双亲的数据域 
		if(a != Nil){//若找到双亲 
			p = Point(T,a);//得到双亲的节点指针 
			if(p->lchild && p->rchild && p->lchild->data == e)//若该双亲节点有左右孩子，且左孩子的数据域与参数e相同 
				return p->rchild->data;//则该节点为所要找的右兄弟 
		}
	}
	return Nil;
} 

Status InsertChild(BiTree p,int LR,BiTree c){//将二叉树T中的某节点P接入节点c，c无右孩子，原P的左/右孩子成为c的右孩子
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

typedef BiTree SElemType;//栈的元素类型定义为二叉树 
#include<C-Stack.h>
#include<B-Stack.h> 

void InOrDerTraverse1(BiTree T,void(* Visit)(TElemType)){//非递归中序遍历双叉树 
	SqStack S;
	InitStack(S);//建立栈S 
	while(T||!StackEmpty(S)){//T或栈不空 
		if(T){//遍历左子树 ，直至底部 
			Push(S,T);//T入栈 
			T = T->lchild;//T指向左孩子，继续循环左孩子 
		}
		else{//到底后指针退栈 
			Pop(S,T);//双亲出栈 
			Visit(T->data);//打印双亲 
			T = T->rchild;//访问右子树 
		}
	}//左子为空，节点出栈。打印节点。试右子，右子为空，则双亲出栈。 
	printf("\n");
	DestroyStack(S);
}


#define CHAR 1
using namespace std;
#include <F-BiTree.h>//�������� 
#include <c1.h> 
#include <C-BiTree.h>
#include <B-BiTree.h>

//char flag;

int main(){
	int i;
	BiTree T,p,c;
	TElemType e1,e2;
	InitBiTree(T);
	printf("����ն�����֮�����շ�%d��1���� 0����\n�������Ϊ��%d��\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1 = Root(T);
	if(e1 != Nil)
		printf("�������ĸ�Ϊ"form"��\n",e1);
	else
		printf("�������޸�\n");
	#if CHAR 
		printf("�밴����������������磺ab###��ʾaΪ���ڵ㣬bΪ�������Ķ�������:\n");
	#else
		printf("�밴����������������磺1 2 0 0 0��ʾ1Ϊ���ڵ㣬2Ϊ�������Ķ�������:\n");
	#endif
	
	CreateBiTree(T);
	/*
	//printf("%d   %d",sizeof(TElemType),sizeof(BiTree));
	CreateBiTree(T);
	
	T = (BiTree)malloc(sizeof(BiTNode));
	
	T->data = 'a';
	T->lchild = (BiTree)malloc(sizeof(BiTNode));
	T->lchild->data = 'b';
	T->lchild->lchild =NULL;
	T->lchild->rchild = NULL;
	T->rchild = (BiTree)malloc(sizeof(BiTNode));
	T->rchild->data = 'c';
	T->rchild->lchild =NULL;
	T->rchild->rchild = NULL;*/
	printf("���������������Ƿ�գ�%d(1:�� 0����)���������Ϊ��%d��\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1 = Root(T);
	if(e1 != Nil)
		printf("�������ĸ�Ϊ"form"��\n",e1);
	else
		printf("�������޸�\n");
	printf("���������������\n");
	InOrderTraverse(T,visit); 
	
	return 0;
}

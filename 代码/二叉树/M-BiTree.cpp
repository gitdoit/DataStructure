#define CHAR 1
using namespace std;
#include <F-BiTree.h>//条件编译 
#include <c1.h> 
#include <C-BiTree.h>
#include <B-BiTree.h>

//char flag;

int main(){
	int i;
	BiTree T,p,c;
	TElemType e1,e2;
	InitBiTree(T);
	printf("构造空二叉树之后，树空否？%d（1：是 0：否）\n树的深度为：%d。\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1 = Root(T);
	if(e1 != Nil)
		printf("二叉树的根为"form"。\n",e1);
	else
		printf("空树，无根\n");
	#if CHAR 
		printf("请按先序输入二叉树（如：ab###表示a为根节点，b为左子树的二叉树）:\n");
	#else
		printf("请按先序输入二叉树（如：1 2 0 0 0表示1为根节点，2为左子树的二叉树）:\n");
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
	printf("二叉树建立后，树是否空？%d(1:是 0：否)。树的深度为：%d。\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1 = Root(T);
	if(e1 != Nil)
		printf("二叉树的根为"form"。\n",e1);
	else
		printf("空树，无根\n");
	printf("中序遍历二叉树：\n");
	InOrderTraverse(T,visit); 
	
	return 0;
}

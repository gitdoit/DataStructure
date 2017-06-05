#include <c1.h>
enum GraphKind {DG,DN,UDG,UDN};//有向图，有向网，无向图，无向网 
typedef char InfoType;
struct ArcNode//表节点 
{
	int adjvex;//该节点在节点列表中的位置
	InfoType *info;
	ArcNode *nextarc;//下一个节点 
}; 

struct VertexType{//顶点的数据结构 
	char name[20];
};

typedef struct//头结点 
{
	VertexType data;//顶点信息 
	ArcNode *firstarc;//头节点的第一个邻接点 
}VNode,AdjList[20];

struct ALGraph//图的结构 
{
	AdjList vertices;//头结点数组
	int vexnum,arcnum;//图的顶点数目 ，和弧的数目 
	GraphKind kind;//图的种类 
};
 

void Visit(VertexType ver){//打印顶点名字 
	printf("%s",ver.name);
} 

void InPut(VertexType &ver){//输入顶点名字 
	scanf("%s",ver.name);
}

void InPutArc(InfoType * &arc){//输入弧的相关信息 
	char s[20];
	int m;
	printf("请输入小于20个字符的弧的相关信息：");
	gets(s);
	m = strlen(s);
	if(m){
		arc = (char *)malloc((m + 1) * sizeof(char));
		strcpy(arc,s);
	} 
}

void OutputArc(InfoType *arc){//打印弧的相关信息 
	printf("%s",arc);
}

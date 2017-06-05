 enum GraphKind {DG,DN,UDG,UDN};//有向图，有向网，无向图，无向网 
 struct InfoType//弧的信息 
 {
 	int weight;
 };
 
 void InputArc(InfoType *&arc)//输入弧的信息 
 {
 	arc = (InfoType *)malloc(sizeof(InfoType));
 	scanf("%d",&arc->weight);
 }
 
 void OutputArc(InfoType *arc)//输出弧的信息0 
 {
 	printf(": %d",arc->weight);
 }
 
 
 struct ElemType//表节点中数据类型 
 {
 	int adjvex;
 	InfoType *info;
 };
 
 typedef struct ArcNode//表节点 
 {
 	ElemType data;
 	ArcNode *nextarc;
 }*ArcList;
 Status ListInsert(ArcList &L,int i,ElemType e)//不带头结点链表的插入操作 
 {
 	int j = 1;
 	ArcList s,p = L;
 	if(i < 1)
 		return ERROR;
 	s = (ArcList)malloc(sizeof(ArcNode));
 	s->data = e;
 	if(i == 1)
 	{
 		s->nextarc = L;
		L = s;	
	}
	else
	{
		while(p && j < i - 1)
		{
			j++;
			p = p->nextarc;
		}
		if(!p)
			return ERROR;
		s->nextarc = p->nextarc;
		p->nextarc = s;
	}
	return OK;
 }
 
 struct VertexType
 {//顶点的数据结构 
	char name[20];
 };

 typedef struct//头结点 
 {
 	VertexType data;//顶点的数据类型，这里只包含顶点的名字 
 	ArcNode *firstarc;//头结点所指的第一个表节点 
 }VNode,AdjList[20];
 
 struct ALGraph
 {
 	AdjList vertices;//头结点数组
	int vexnum,arcnum;//图中顶点和弧的个数 
	GraphKind kind;//图的种类 
 };
 
 //#define LNode ArcNode
 //#define next nextarc
 //typedef ArcNode *LinkList; 
 

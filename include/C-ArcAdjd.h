 enum GraphKind {DG,DN,UDG,UDN};//����ͼ��������������ͼ�������� 
 struct InfoType//������Ϣ 
 {
 	int weight;
 };
 
 void InputArc(InfoType *&arc)//���뻡����Ϣ 
 {
 	arc = (InfoType *)malloc(sizeof(InfoType));
 	scanf("%d",&arc->weight);
 }
 
 void OutputArc(InfoType *arc)//���������Ϣ0 
 {
 	printf(": %d",arc->weight);
 }
 
 
 struct ElemType//��ڵ����������� 
 {
 	int adjvex;
 	InfoType *info;
 };
 
 typedef struct ArcNode//��ڵ� 
 {
 	ElemType data;
 	ArcNode *nextarc;
 }*ArcList;
 Status ListInsert(ArcList &L,int i,ElemType e)//����ͷ�������Ĳ������ 
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
 {//��������ݽṹ 
	char name[20];
 };

 typedef struct//ͷ��� 
 {
 	VertexType data;//������������ͣ�����ֻ������������� 
 	ArcNode *firstarc;//ͷ�����ָ�ĵ�һ����ڵ� 
 }VNode,AdjList[20];
 
 struct ALGraph
 {
 	AdjList vertices;//ͷ�������
	int vexnum,arcnum;//ͼ�ж���ͻ��ĸ��� 
	GraphKind kind;//ͼ������ 
 };
 
 //#define LNode ArcNode
 //#define next nextarc
 //typedef ArcNode *LinkList; 
 

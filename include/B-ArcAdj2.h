  int LocateVex(ALGraph G,VertexType u)//���Ҷ����ڶ����б��е�λ�� 
 {
 	int i;
 	for(i = 0 ; i < G.vexnum; i++)
	{
		if(strcmp(u.name,G.vertices[i].data.name) == 0)
		return i;
	}
	return -1;
 }
 
 void CreateGraph(ALGraph &G)//����ͼ 
 {
 	int i ,j,k;
	VertexType v1,v2;
	ElemType e; 
	char s[3] = "��";
	printf("������ͼ������ 0 1 2 3 �� ����ͼ ������ ����ͼ ������\n");
	scanf("%d",&G.kind)	;
	if(G.kind < 2)
		strcpy(s,"��");
	printf("�����붥����������\n");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	printf("������%d�����������\n",G.vexnum);
	for(i = 0 ; i < G.vexnum; i++)
	{
		scanf("%s",&G.vertices[i].data.name);
		G.vertices[i].firstarc == NULL;
	}
	
	printf("��ֱ�����%d��%s��",G.arcnum,s);
	switch(G.kind)
	{
		case DG:printf("��β����ͷ��\n");
		break;
		case DN:printf("��β����ͷ��������Ϣ��\n");
		break;
		case UDG:printf("����1������2��\n");
		break;
		case UDN:printf("����1������2���ߵ���Ϣ��\n");
	}
	for(k = 0; k < G.arcnum ; k++)
	{
		printf("��%d��%s����Ϣ",k+1,s);
		scanf("%s%s",&v1.name,&v2.name);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		e.info = NULL;
		if(G.kind%2)//��Ϊ����������ߵ���Ϣ 
			InputArc(e.info); 
		e.adjvex = j;
		ListInsert(G.vertices[i].firstarc,1,e);
		if(G.kind >= 2)//��Ϊ����ģ���Ӧ�Գ� 
		{
			e.adjvex = i;
			ListInsert(G.vertices[j].firstarc,1,e);
		}
	}
		 
 } 
 
  void Visit(VertexType ver){//��ӡ�������� 
	printf("%s",ver.name);
} 

 VertexType GetVex(ALGraph G,int v)
 {
 	if(v >= G.vexnum || v < 0)
 		exit(OVERFLOW);
 	return G.vertices[v].data;
 }
 
 int FirstAdjVex(ALGraph G,int v)
 {
 	ArcNode *p = G.vertices[v].firstarc;
 	if(p)
 		return p->data.adjvex;
 	else
 	return -1;
 }
 
 Status equalvex(ElemType a,ElemType b)
 {
 	if(a.adjvex == b.adjvex)
 		return OK;
 	else
 		return ERROR;
 }
 
 int LocateElem(ArcList L,ElemType e,Status(*compare)(ElemType,ElemType))
  {
  	int i = 0;
  	ArcList p = L->nextarc;
  	while(p)
  	{
  		i++;
		if(compare(p->data,e))
			return i;
		p=p->nextarc;		
	}
	return 0;
  }
 
  ArcList Point(ArcList L,ElemType e,Status(* equal)(ElemType,ElemType),ArcList &p)
 {
 	int j , i = LocateElem(L,e,equal);
 	if(i)
 	{
 		if(i == 1)
 		{
 			p = NULL;
			return L;	
		}
		p = L;
		for(j = 2; j < i;j++)
			p = p->nextarc;
		return p->nextarc;
	}
	return NULL;
 }
 
int NextAdjVex(ALGraph G,int v,int w)
{
 	ArcList p,p1;
 	ElemType e;
 	e.adjvex = w;
 	p = Point(G.vertices[v].firstarc,e,equalvex,p1);
 	if(!p || !p->nextarc)
 		return -1;
 	else
 		return p->nextarc->data.adjvex;
}
 
 
typedef int QElemType;\

#include <C-Queue.h>
#include <B-Queue.h>

int visite[20];

void BFSTraverse(ALGraph G,void (*Visit)(VertexType))
{
	int v,u,w;
	LinkQueue Q;
	for(v = 0; v < G.vexnum;v++)
		visite[v] = FALSE;
	InitQueue(Q);
	for(v = 0; v < G.vexnum;v++)
	if(!visite[v])
		{
			visite[v] = TRUE;
			Visit(GetVex(G,v));
			EnQueue(Q,v);
			while(!QueueEmpty(Q))
			{
				DeQueue(Q,u);
				for(w = FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
					if(!visite[w])
					{
						visite[w] = TRUE;
						Visit(GetVex(G,w));
						EnQueue(Q,w);
					}
			}
			
		}
	printf("\n");	
} 


 int LocateVex(ALGraph G,VertexType u)//查找顶点在顶点列表中的位置 
 {
 	int i;
 	for(i = 0 ; i < G.vexnum; i++)
	{
		if(strcmp(u.name,G.vertices[i].data.name) == 0)
		return i;
	}
	return -1;
 }
 
 
 void CreateGraph(ALGraph &G)//创建图 
 {
 	int i ,j,k;
	VertexType v1,v2;
	ElemType e; 
	char s[3] = "边";
	printf("请输入图的类型 0 1 2 3 即 有向图 有向网 无向图 无向网\n");
	scanf("%d",&G.kind)	;
	if(G.kind < 2)
		strcpy(s,"弧");
	printf("请输入顶点数，边数\n");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	printf("请输入%d个顶点的名称\n",G.vexnum);
	for(i = 0 ; i < G.vexnum; i++)
	{
		scanf("%s",&G.vertices[i].data.name);
		G.vertices[i].firstarc == NULL;
	}
	
	printf("请分别输入%d条%s的",G.arcnum,s);
	switch(G.kind)
	{
		case DG:printf("弧尾、弧头：\n");
		break;
		case DN:printf("弧尾、弧头、弧的信息：\n");
		break;
		case UDG:printf("顶点1、顶点2：\n");
		break;
		case UDN:printf("顶点1、顶点2、边的信息：\n");
	}
	for(k = 0; k < G.arcnum ; k++)
	{
		printf("第%d条%s的信息",k+1,s);
		scanf("%s%s",&v1.name,&v2.name);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		e.info = NULL;
		if(G.kind%2)//若为网，则输入边的信息 
			InputArc(e.info); 
		e.adjvex = j;
		ListInsert(G.vertices[i].firstarc,1,e);
		if(G.kind >= 2)//若为无向的，则应对称 
		{
			e.adjvex = i;
			ListInsert(G.vertices[j].firstarc,1,e);
		}
	}
		 
 } 
 
 void Visit(VertexType ver){//打印顶点名字 
	printf("%s",ver.name);
} 

 /* 
 void DFS(ALGraph g,int v ,void(* Visit)(VertexType))
 {
 	
 	ArcList p;//表节点变量 
	visited[v] =  TRUE;//设该表节点已访问
	if(v < 20 && v >= 0) 
		Visit(g.vertices[v].data);//访问该节点 
	for(p = g.vertices[v].firstarc;p != NULL;p = p->nextarc)//从头结点开始向后开始传递性访问 
	{		
		if( p->data.adjvex >= 0 && p->data.adjvex < 20 && !visited[p->data.adjvex])//若该节点未被访问 
			DFS(g,p->data.adjvex,Visit);//递归调用 
	}
 }
 
 void DFSTraverse(ALGraph G,void(* Visit)(VertexType))
 {
 	int v = 0;
 	for(v = 0;v < G.vexnum;v++)//初始化访问列表 
 		visited[v] = FALSE;
 	for(v = 0;v < G.vexnum; v++)//若是连通图，则一次即可访问全部 
 		if(!visited[v]) DFS(G,v,Visit);
 	printf("\n");
 }*/

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
 
 Boolean visite[20];
 void(*VisitFunc)(VertexType);
 void DFS(ALGraph G,int v)
 {
 	int w;
 	visite[v] = TRUE;
 	VisitFunc(GetVex(G,v));
 	for(w = FirstAdjVex(G,v); w > 0; w = NextAdjVex(G,v,w))
 		if(!visite[w])
		{
			printf("%d",visite[w]);
			DFS(G,w);
		}
 			
 }
 
 void DFSTraverse(ALGraph G,void(*Visit)(VertexType))
 {
 	int v;
 	VisitFunc = Visit;
 	for(v = 0; v<G.vexnum;v++)
 		visite[v] = FALSE;
 	//for(v = 0;v < G.vexnum;v++)
 		//if(!visite[v])
 		v = 0;
 			DFS(G,v);
 	printf("\n");
 }

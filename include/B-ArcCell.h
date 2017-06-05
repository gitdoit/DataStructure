int LocateVex(MGraph G,VertexType u){//查找顶点u，在图中的位置 
	int i;
	for(i = 0 ; i < G.vexnum; i++){
		if(strcmp(u.name,G.vexs[i].name))
			return i;
	}
	return -1;
}

void CreateDG(MGraph &G){
	int i,j,k,IncInfo;
} 

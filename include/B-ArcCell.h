int LocateVex(MGraph G,VertexType u){//���Ҷ���u����ͼ�е�λ�� 
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

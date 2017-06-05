#define INFINITY INT_MAX //用整形最大值代表无穷大
typedef int VRType; // 定义顶点关系类型为整形
typedef char InfoType;//存储弧的相关信息 
#define MAX_VERTEX_NUM 26 //最大顶点个数为26
#define MAX_NAME 9 //顶点名字长度 
enum GraphKind{DG,DN,UDG,UDN};//{有向图，有向网，无向图，无向网}

struct VertexType{//顶点的数据结构 
char name[MAX_NAME];
};

typedef struct{//弧的数据结构 
	VRType adj;//顶点关系类型，无权图1,0表示是否相邻。有权图则为权值 
	InfoType *info;//弧的相关信息 
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

struct MGraph{//图的数据结构 
	VertexType vexs[MAX_VERTEX_NUM];//vexs;所有顶点信息（名字）依次放在该一维数组中 
	AdjMatrix arcs;//一张记录弧的二位表格，图的邻接矩阵 
	int vexnum,arcnum;//图的顶点和弧的个数 
	GraphKind kind;//图的种类 
}; 

void Visit(VertexType ver){//打印顶点名字 
	
} 

void InPut(VertexType &ver){//输入顶点名字 
	
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

void OutputArc(InofType *arc){//打印弧的相关信息 
	printf("%s",arc);
}

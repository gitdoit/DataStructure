#define INFINITY INT_MAX //���������ֵ���������
typedef int VRType; // ���嶥���ϵ����Ϊ����
typedef char InfoType;//�洢���������Ϣ 
#define MAX_VERTEX_NUM 26 //��󶥵����Ϊ26
#define MAX_NAME 9 //�������ֳ��� 
enum GraphKind{DG,DN,UDG,UDN};//{����ͼ��������������ͼ��������}

struct VertexType{//��������ݽṹ 
char name[MAX_NAME];
};

typedef struct{//�������ݽṹ 
	VRType adj;//�����ϵ���ͣ���Ȩͼ1,0��ʾ�Ƿ����ڡ���Ȩͼ��ΪȨֵ 
	InfoType *info;//���������Ϣ 
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

struct MGraph{//ͼ�����ݽṹ 
	VertexType vexs[MAX_VERTEX_NUM];//vexs;���ж�����Ϣ�����֣����η��ڸ�һά������ 
	AdjMatrix arcs;//һ�ż�¼���Ķ�λ���ͼ���ڽӾ��� 
	int vexnum,arcnum;//ͼ�Ķ���ͻ��ĸ��� 
	GraphKind kind;//ͼ������ 
}; 

void Visit(VertexType ver){//��ӡ�������� 
	
} 

void InPut(VertexType &ver){//���붥������ 
	
}

void InPutArc(InfoType * &arc){//���뻡�������Ϣ 
	char s[20];
	int m;
	printf("������С��20���ַ��Ļ��������Ϣ��");
	gets(s);
	m = strlen(s);
	if(m){
		arc = (char *)malloc((m + 1) * sizeof(char));
		strcpy(arc,s);
	} 
}

void OutputArc(InofType *arc){//��ӡ���������Ϣ 
	printf("%s",arc);
}

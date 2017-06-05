#include <c1.h>
enum GraphKind {DG,DN,UDG,UDN};//����ͼ��������������ͼ�������� 
typedef char InfoType;
struct ArcNode//��ڵ� 
{
	int adjvex;//�ýڵ��ڽڵ��б��е�λ��
	InfoType *info;
	ArcNode *nextarc;//��һ���ڵ� 
}; 

struct VertexType{//��������ݽṹ 
	char name[20];
};

typedef struct//ͷ��� 
{
	VertexType data;//������Ϣ 
	ArcNode *firstarc;//ͷ�ڵ�ĵ�һ���ڽӵ� 
}VNode,AdjList[20];

struct ALGraph//ͼ�Ľṹ 
{
	AdjList vertices;//ͷ�������
	int vexnum,arcnum;//ͼ�Ķ�����Ŀ ���ͻ�����Ŀ 
	GraphKind kind;//ͼ������ 
};
 

void Visit(VertexType ver){//��ӡ�������� 
	printf("%s",ver.name);
} 

void InPut(VertexType &ver){//���붥������ 
	scanf("%s",ver.name);
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

void OutputArc(InfoType *arc){//��ӡ���������Ϣ 
	printf("%s",arc);
}

#include <c1.h>
#include <C-LinkList.h>
#include <B-LinkList.h>
int main()
{
	int j,i;
	LinkList La,Lb,Lc;
	InitList(La);
	InitList(Lb);
	printf("请为La输入5个数据\n");
	for(j = 1;j<=5;j++)
	{
		scanf("%d",&i);
		ListInsert(La,1,i);
	}
	printf("请为Lb输入5个数据\n");
	for(j = 1;j<=5;j++)
	{
		scanf("%d",&i);
		ListInsert(Lb,1,i);
	}
	MergeList(La,Lb,Lc);
	printf("归并后的链表为：\n");
	while(Lc->next != NULL)
	{
		printf("%d  ",Lc->next->data);
		Lc = Lc->next;
	}
	return 0;
}

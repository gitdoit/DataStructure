#include <c1.h>
#include <C-ChuankLinkList.h>
#include <B-ChuankLinkList.h>
#include <string>
using namespace std;
typedef HString String;
int main()
{
	int i;
	char c[50],*q,*p;
	HString t,s,r;
	InitString(t);
	InitString(s);
	InitString(r); 
	puts("Please input some words for t");                    
	//scanf("%s",c);
	gets(c);
	StrAssign(t,c);
	puts("Please input some words for s");
	gets(c);
	StrAssign(s,c);
	puts("The chuank T is:");
	StrPrint(t);
	printf("The length of s is %d\n",s.length);
	i = StrCompare(t,s);
	if(i > 0)
		puts("t > s");
	else if(i == 0)
		puts("t == s");
	else
		puts("t < s");
	ConCat(r,t,s);
	puts("��T�봮S���Ӻ��´�Ϊ");
	StrPrint(r);
	ClearString(r);
	printf("��r��պ󣬴��ĳ���Ϊ%d,�Ƿ�Ϊ�գ�%d��1���� 0����",StrLength(r),StrEmpty(r));
	
	 
	 
} 

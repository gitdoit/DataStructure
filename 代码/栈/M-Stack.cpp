#include <c1.h>
#include <C-Stack.h>
#include <B-Stack.h>

int main(int argc, char** argv) {
	char c;
	int len,i = 0;
	SqStack S;
	InitStack(S);
	printf("������һ����Ҫ�жϵ��ַ���");
	scanf("%c",&c);
	while(c != '\n'){//�Ӽ������μ���Ԫ����ջ 
		Push(S,c);
		scanf("%c",&c);
	}
	len = StackLength(S);//�õ�ջ�ĳ��� 
	while(S.base != S.top&&i < len/2){//��ָ���붥ָ������ʱ��Ƚϳ����м�Ԫ�����˳�ѭ�� 
		if(*S.base == *(S.top - 1)){
			S.base++;
			S.top--;
			i++;
			continue;
		}
		printf("���ǻ����ַ�\n",i);
		return 0;
		
	}
	printf("�ǻ����ַ���\n");
	return 0;
}

#include <c1.h>
#include <C-Stack.h>
#include <B-Stack.h>

int main(int argc, char** argv) {
	char c;
	int len,i = 0;
	SqStack S;
	InitStack(S);
	printf("请输入一段需要判断的字符串");
	scanf("%c",&c);
	while(c != '\n'){//从键盘依次键入元素入栈 
		Push(S,c);
		scanf("%c",&c);
	}
	len = StackLength(S);//得到栈的长度 
	while(S.base != S.top&&i < len/2){//基指针与顶指针相遇时或比较超过中间元素则退出循环 
		if(*S.base == *(S.top - 1)){
			S.base++;
			S.top--;
			i++;
			continue;
		}
		printf("不是回文字符\n",i);
		return 0;
		
	}
	printf("是回文字符串\n");
	return 0;
}

# define DestroyString ClearString

void InitString(HString &S){//初始化串 
	S.length = 0;
	S.ch = NULL;
}

void ClearString(HString &S){//清空串 
	free(S.ch);
	InitString(S);
}

void StrAssign(HString &T,char *chars){//生成一个值为chars指向的串T 
	int i,j;
	if(T.ch)
		free(T.ch);
	i = strlen(chars);//求目标串的长度 
	if(!i)//若目标串为空，则生成空串T 
		InitString(T);
	else{//不空则开辟等长空间，循环赋值； 
		T.ch = (char *)malloc(i * sizeof(char));
		if(!T.ch)
			exit(OVERFLOW);
		for( j = 0; j < i; j++)
			T.ch[j] = chars[j];
		T.length = i;
	} 
}


Status StrEmpty(HString S){//判断串S是否为空串 
	if(S.ch == NULL || S.length == 0)
		return TRUE;
	return FALSE;
} 

int StrCompare(HString S,HString T){//比较两串。若S>T则返回值大于零，相等为零，小于为负 
	int i;
	for( i = 0 ; i < S.length && i < T.length; i++){
		if(S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	} 
	return S.length - T.length;
}

int StrLength(HString S){//返回串的长度 
	return S.length;
} 

void ConCat(HString &T,HString S1,HString S2){//连接串S1，S2生成新串T 
	int i;
	if(T.ch)
		free(T.ch);
	T.length = S1.length +S2.length;
	T.ch = (char *)malloc(T.length * sizeof(char));
	if(!T.ch)
		exit(OVERFLOW);
	for(i = 0; i < S1.length; i++)
		T.ch[i] = S1.ch[i];
	for(i = 0; i < S2.length;i++)
		T.ch[S1.length+i] = S2.ch[i];
}

Status SubString(HString &Sub,HString S,int pos,int len){//截取串S中起始位置为POS长度为LEN的子串赋给Sub； 
	int i;//pos从1开始。 
	if(pos < 1|| pos > S.length || len < 0||len > S.length - pos +1)
		return ERROR;
	if(Sub.ch)
		free(Sub.ch);
	if(!len)
		InitString(Sub);
	else{
		Sub.ch = (char *)malloc(len * sizeof(char));
		if(!Sub.ch)
			exit(OVERFLOW);
		for(i = 0; i < len -1;i++)
			Sub.ch[i] = S.ch[pos -1 + i];
		Sub.length = len;
	}
	return OK;
}

Status StrInsert(HString &S,int pos,HString T){//在串S位置为Pos字符前插入串T
	int i;
	if(pos < 1 || pos > S.length + 1)//POS位置是否合法 
		return ERROR;
	if(T.length){//T串不空 
	
		S.ch = (char *)realloc(S.ch,(S.length + T.length)*sizeof(char));//从新开辟空间 
		if(!S.ch)
			exit(OVERFLOW);
		for(i = S.length -1; i > pos -1;i--)//从pos位置开始向后腾位置 
			S.ch[i + T.length] = S.ch[i];
		for(i = 0; i < T.length; i++) //从pos位置开始复制串T 
			S.ch[pos - 1 + i] = T.ch[i];
		S.length += T.length;//更新长度 
	}
	return OK;
} 

Status StrDelete(HString &S,int pos,int len){//删除从pos开始长度为len的子串 
	int i;
	if(S.length < pos + len -1)
		return ERROR;
	for(i = pos -1; i <=S.length -len;i++)
		S.ch[i] = S.ch[i + len];//在i与i+len之间的字符为待删除，所以将区间内的字符覆盖
	S.length -= len;
	S.ch = (char *)realloc(S.ch,S.length * sizeof(char));
	return OK; 
}

void StrPrint(HString S){//打印串S 
	int i;
	for(i = 0; i < S.length; i++)
		printf("%c",S.ch[i]);
	printf("\n");
} 

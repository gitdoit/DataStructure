# define DestroyString ClearString

void InitString(HString &S){//��ʼ���� 
	S.length = 0;
	S.ch = NULL;
}

void ClearString(HString &S){//��մ� 
	free(S.ch);
	InitString(S);
}

void StrAssign(HString &T,char *chars){//����һ��ֵΪcharsָ��Ĵ�T 
	int i,j;
	if(T.ch)
		free(T.ch);
	i = strlen(chars);//��Ŀ�괮�ĳ��� 
	if(!i)//��Ŀ�괮Ϊ�գ������ɿմ�T 
		InitString(T);
	else{//�����򿪱ٵȳ��ռ䣬ѭ����ֵ�� 
		T.ch = (char *)malloc(i * sizeof(char));
		if(!T.ch)
			exit(OVERFLOW);
		for( j = 0; j < i; j++)
			T.ch[j] = chars[j];
		T.length = i;
	} 
}


Status StrEmpty(HString S){//�жϴ�S�Ƿ�Ϊ�մ� 
	if(S.ch == NULL || S.length == 0)
		return TRUE;
	return FALSE;
} 

int StrCompare(HString S,HString T){//�Ƚ���������S>T�򷵻�ֵ�����㣬���Ϊ�㣬С��Ϊ�� 
	int i;
	for( i = 0 ; i < S.length && i < T.length; i++){
		if(S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	} 
	return S.length - T.length;
}

int StrLength(HString S){//���ش��ĳ��� 
	return S.length;
} 

void ConCat(HString &T,HString S1,HString S2){//���Ӵ�S1��S2�����´�T 
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

Status SubString(HString &Sub,HString S,int pos,int len){//��ȡ��S����ʼλ��ΪPOS����ΪLEN���Ӵ�����Sub�� 
	int i;//pos��1��ʼ�� 
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

Status StrInsert(HString &S,int pos,HString T){//�ڴ�Sλ��ΪPos�ַ�ǰ���봮T
	int i;
	if(pos < 1 || pos > S.length + 1)//POSλ���Ƿ�Ϸ� 
		return ERROR;
	if(T.length){//T������ 
	
		S.ch = (char *)realloc(S.ch,(S.length + T.length)*sizeof(char));//���¿��ٿռ� 
		if(!S.ch)
			exit(OVERFLOW);
		for(i = S.length -1; i > pos -1;i--)//��posλ�ÿ�ʼ�����λ�� 
			S.ch[i + T.length] = S.ch[i];
		for(i = 0; i < T.length; i++) //��posλ�ÿ�ʼ���ƴ�T 
			S.ch[pos - 1 + i] = T.ch[i];
		S.length += T.length;//���³��� 
	}
	return OK;
} 

Status StrDelete(HString &S,int pos,int len){//ɾ����pos��ʼ����Ϊlen���Ӵ� 
	int i;
	if(S.length < pos + len -1)
		return ERROR;
	for(i = pos -1; i <=S.length -len;i++)
		S.ch[i] = S.ch[i + len];//��i��i+len֮����ַ�Ϊ��ɾ�������Խ������ڵ��ַ�����
	S.length -= len;
	S.ch = (char *)realloc(S.ch,S.length * sizeof(char));
	return OK; 
}

void StrPrint(HString S){//��ӡ��S 
	int i;
	for(i = 0; i < S.length; i++)
		printf("%c",S.ch[i]);
	printf("\n");
} 

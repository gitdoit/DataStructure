Status InitStack(SqStack &S){
	S.base = (SElemType*)malloc(100 * sizeof(SElemType));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = 100;
	return OK;
}

Status DestroyStack(SqStack &S){
	free(S.base);
	S.top = S.base = NULL;
	S.stacksize = 0; 
	return OK;
}

Status Push(SqStack &S,SElemType e){
	if(S.top - S.base >=S.stacksize){
		S.base = (SElemType*)realloc(S.base,(S.stacksize + 10) * sizeof(SElemType));
		if(!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;//Ω√’˝top÷∏’Î 
		S.stacksize +=10;
	}
	*S.top++ =e;
	return OK;
}

Status Pop(SqStack &S,SElemType &e){
	if(S.base == S.top) return ERROR;
	S.top--;
	e = *S.top;
	return OK;
}

Status GetTop(SqStack &S,SElemType &e){
	if(S.base == S.top) return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status StackEmpty(SqStack &S){
	if(S.base == S.top) return TRUE;
	else return FALSE;
}

int StackLength(SqStack S){
	return S.top - S.base;
}

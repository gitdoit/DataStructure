Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3)
{//������Ԫ�飬��V1,V2��V3�������ٵĿռ䣻 
	T = (ElemType *)malloc(3 * sizeof(ElemType));
	if(!T) exit(OVERFLOW);
	T[0]= v1;T[1]=v2;T[2]=v3;
	return OK;
}
Status DrestroyTriplet(Triplet &T)
{
	free(T);
	T=NULL;
	return OK;
}
Status Get(Triplet T,int i,ElemType &e)
{//�õ���i��Ԫ�ص�ֵ������e�� 
	if(i<1 || i>3)
	return ERROR;
	e = T[i - 1];
	return OK;
}
Status Put(Triplet T,int i ,ElemType e)
{//����i��Ԫ�ص�ֵ�ı�Ϊe 
	if(i<1 || i>3)
	return ERROR;
	T[i - 1] = e;
	return OK;
}
Status IsAscending(Triplet T)
{//��Ԫ���Ƿ����������У� 
	return(T[0]<=T[1]<=T[2]);
}
Status IsDescending(Triplet T)
{//�Ƿ������У� 
	return(T[0]>=T[1]>=T[2]);
}
Status Max(Triplet T,ElemType &e)
{//�õ�����Ԫ�أ� 
	e = (T[0]>=t[1])?(T[0]>=T[2]?T[0]:T[2]):(T[1]>=T[2]?T[1]:T[2]);
	return OK;
}
Status Min(Triplet T,ElemType &e)
{//�õ���С��Ԫ�أ� 
	e = (T[0]<=t[1])?(T[0]<=T[2]?T[0]:T[2]):(T[1]<=T[2]?T[1]:T[2]);
	return OK;
} 


Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3)
{//构造三元组，将V1,V2，V3付给开辟的空间； 
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
{//得到第i个元素的值，赋给e； 
	if(i<1 || i>3)
	return ERROR;
	e = T[i - 1];
	return OK;
}
Status Put(Triplet T,int i ,ElemType e)
{//将第i个元素的值改变为e 
	if(i<1 || i>3)
	return ERROR;
	T[i - 1] = e;
	return OK;
}
Status IsAscending(Triplet T)
{//三元组是否按照升序排列； 
	return(T[0]<=T[1]<=T[2]);
}
Status IsDescending(Triplet T)
{//是否降序排列； 
	return(T[0]>=T[1]>=T[2]);
}
Status Max(Triplet T,ElemType &e)
{//得到最大的元素； 
	e = (T[0]>=t[1])?(T[0]>=T[2]?T[0]:T[2]):(T[1]>=T[2]?T[1]:T[2]);
	return OK;
}
Status Min(Triplet T,ElemType &e)
{//得到最小的元素； 
	e = (T[0]<=t[1])?(T[0]<=T[2]?T[0]:T[2]):(T[1]<=T[2]?T[1]:T[2]);
	return OK;
} 


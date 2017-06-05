//typedef unsigned char SString[226];
#include <string>
using namespace std;

int StrLength(string S){
	int i = 0;
	if(S[0] == '\0') return i;
	while(S[i++] != '\0');
	return i;
}


Status StrAssign(string &T,string chars){
	int i;
	for(i = 0; i < StrLength(chars);i++){
		T[i] = chars[i];
	}
	T[i] = '\0';
	return OK;
}

Status StrCopy(string &T,string S){
	int i;
	if(!StrLength(S)) return ERROR;
	if(StrLength(T)){
		for(i = 1; i <= T[0];i++){
			T[i] = '\0';
		}
	}
	for(i = 0; i < StrLength(S);i++){
		T[i] = S[i];
	}
	T[i] = '\0';
	return OK;
}

Status StrEmpty(string S){
	if(StrLength(S)) return FALSE;
	return TRUE;
}

int StrCompare(string S,string T){
	int i,n;
	n = StrLength(T) < StrLength(S) ? StrLength(T):StrLength(S);
	if(StrLength(S) || StrLength(T)) exit(OVERFLOW);
	for(i = 0; i < n; i++){
		if(T[i] == S[i]) continue;
		else if(T[i] > S[i]) return FALSE;
		else return TRUE;
	}
	return 0;
}

Status Concat(string &T,string S1,string S2){
	int i =0,j;
	if(StrLength(S1) || StrLength(S2)) exit(OVERFLOW);
	for(j = 0; j < StrLength(S1); j++){
		T[j] = S1[j];
	}
	while(S2[i] != '\0'){
		T[j++] = S2[i++];
	}
	T[j] = '\0';
	return OK;
	
}

Status SubString(string &Sub,string S,int pos,int len){
	int i = pos + len,j = 0;
	if(StrEmpty(S)) exit(OVERFLOW);
	if(pos < 1 || pos > StrLength(S) ) return ERROR;
	else if(len < 0 || len > StrLength(S) - pos + 1) return ERROR;
	while(pos <= i){
		Sub[j++] = S[pos++];

	}
	Sub[j] = '\0'; 
	return OK;
	
}

int Index(string S,string T,int pos){
	int index,i = pos,TLen = StrLength(T),m;
	string Sub;
	if(StrEmpty(S) || StrEmpty(T)) exit(OVERFLOW);
	if(pos < 1 || pos > StrLength(S)) exit(OVERFLOW);
	for(m = 0; m <= StrLength(S) - TLen; m++){
		SubString(Sub,S,m,TLen);
		if(StrCompare(Sub,T) == 0) return m;
	}
	return 0;
}

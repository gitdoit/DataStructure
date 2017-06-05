#include <c1.h>
#include <C-Queue.h>
#include <B-Queue.h>
 
int main(int argc, char** argv) {
	LinkQueue Q;
	InitQueue(Q);
	int n;
	for(int i = 0; i < 10 ;i++){
		EnQueue(Q,i);
	}
	printf("%d \n",QueueLength(Q));
	printf("%d",QueueEmpty(Q));
	return 0;
}

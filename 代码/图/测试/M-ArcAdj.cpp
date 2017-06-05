#include <c1.h>
#include <C-ArcAdjd.h>
#include <B-ArcAdj2.h>

int main()
{
	ALGraph g;
	CreateGraph(g);
	BFSTraverse(g,Visit);
	
	return 0;
}

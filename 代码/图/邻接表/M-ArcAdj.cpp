#include <c1.h>
#include <C-ArcAdjd.h>
#include <B-ArcAdj.h>

int main()
{
	ALGraph g;
	CreateGraph(g);
	DFSTraverse(g,Visit);
	return 0;
}

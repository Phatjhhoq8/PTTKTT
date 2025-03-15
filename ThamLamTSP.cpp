#include<stdio.h>
#include<malloc.h>
#define MAXN 101
typedef struct {
	int u,v;
	float w;
}Edge;
typedef struct {
	int n,m;
	Edge edges[MAXN];
}Graph;
void initGraph(Graph* g,int n) {
	g->n=n,g->m=0;
}
void add_edges(Graph* g,int u,int v,float w) {
	int m=g->m++;
	g->edges[m].u=u;
	g->edges[m].v=v;
	g->edges[m].w=w;
}
void Swap(Edge* a,Edge* b) {
	Edge c=*a;
	*a=*b;
	*b=c;
}
void sort(Graph* g) {
	for(int i=0;i<g->m-1;i++) for(int j=g->m-1;j>i;j--) if(g->edges[j].w<g->edges[j-1].w) Swap(&g->edges[j],&g->edges[j-1]);
}
Graph* readData() {
	freopen("TSP1.txt","r",stdin);
	int n;scanf("%d",&n);
	Graph *g=(Graph*)malloc(sizeof(Graph));
	initGraph(g,n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		float m;scanf("%f",&m);
		if(i>=j) continue;
		add_edges(g,i,j,m);
	}
	freopen("CON","r",stdin);
	return g;
}
void printData(Graph* g) {
	for(int i=0;i<g->m;i++) printf("%d %d %.2f\n",g->edges[i].u,g->edges[i].v,g->edges[i].w);
}
int parent[MAXN],indeg[MAXN];
int find(int u) {
	return u==parent[u]?u:find(parent[u]);
}
void Union(int u,int v) {
	u=find(u),v=find(v);
	parent[v]=u;
}
int bac3(int u,int v) {
	return (indeg[u]==2||indeg[v]==2);
}
int cycle(int u,int v) {
	u=find(u),v=find(v);
	return (u==v);
}
Graph* thamlam(Graph* g,float* weight) {
	Graph *t=(Graph*)malloc(sizeof(Graph));
	for(int i=1;i<=g->n;i++) parent[i]=i,indeg[i]=0;
	int i=0;
	for(;i<g->m;i++) {
		if(t->m==g->n-1) break;
		int u=g->edges[i].u;
		int v=g->edges[i].v;
		float w=g->edges[i].w;
		if(!bac3(u,v)&&!cycle(u,v)) {
			Union(u,v);
			add_edges(t,u,v,w);
			indeg[u]++,indeg[v]++;
			(*weight)+=w;
		}
	}
	for(;i<g->m;i++) {
		int u=g->edges[i].u;
		int v=g->edges[i].v;
		float w=g->edges[i].w;
		if(!bac3(u,v)&&cycle(u,v)) {
			Union(u,v);
			add_edges(t,u,v,w);
			indeg[u]++,indeg[v]++;
			(*weight)+=w;
			break;
		}
	}
	return t;
}
int main() {
	Graph* g=readData();
	printf("Danh sach canh chua sap xep: \n");
	printData(g);
	printf("Danh sach canh da sap xep: \n");
	sort(g);
	printData(g);
	float weight=0;
	Graph *t = thamlam(g,&weight);
	printf("Do lon cua duong di: %.2f\n",weight);
	printf("Danh sach duong di: \n");
	printData(t);
	return 0;
}

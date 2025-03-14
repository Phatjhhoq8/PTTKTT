#include<stdio.h>
#include<malloc.h>
#define MAXN 101
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
typedef struct {
	int tl,gt,sl,pa;
	char name[100];
}DoVat;
DoVat* readData(int *n,int *W) {
	freopen("CaiBalo2.txt","r",stdin);
	scanf("%d",W);
	DoVat *dv =(DoVat*)malloc(sizeof(DoVat));
	while(scanf("%d%d%d%[^\n]",&dv[*n].tl,&dv[*n].gt,&dv[*n].sl,&dv[*n].name)!=EOF) {
		(*n)++;
		dv=(DoVat*)realloc(dv,sizeof(DoVat)*(*n+1));
	}
	freopen("CON","r",stdin);
	return dv;
}
void printData(DoVat* dv,int n,int ok=0) {
	if(!ok) for(int i=0;i<n;i++) printf("%d %d %s \n",dv[i].tl,dv[i].gt,dv[i].name);
	else for(int i=0;i<n;i++) printf("%d %d %s %d\n",dv[i].tl,dv[i].gt,dv[i].name,dv[i].pa);
}
void quyhoachdong(DoVat* dv,int f[][MAXN],int x[][MAXN],int n,int W) {
	for(int i=0;i<=W;i++) x[0][i]=min(i/dv[0].tl,dv[0].sl),f[0][i]=x[0][i]*dv[0].gt;
	for(int i=1;i<n;i++) {
		for(int j=0;j<=W;j++) {
			int yk=min(j/dv[i].tl,dv[i].sl);
			f[i][j]=f[i-1][j];x[i][j]=0;
			for(int k=1;k<=yk;k++) {
				int u=k*dv[i].tl;
				if(f[i][j]<f[i-1][j-u]+dv[i].gt*k) f[i][j]=f[i-1][j-k*dv[i].tl]+dv[i].gt*k,x[i][j]=k;
			}
		}
	}
}
void printTable(int f[][MAXN],int x[][MAXN],int n,int W) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<=W;j++) printf("%d-%d\t",f[i][j],x[i][j]);
		printf("\n");
	}
}
void printPath(DoVat* dv,int f[][MAXN],int x[][MAXN],int n,int W) {
	for(int i=n-1;i>=0;i--) {
		dv[i].pa=x[i][W];
		W-=x[i][W]*dv[i].tl;
	}
}
int main() {
	int n=0,W;
	DoVat* dv=readData(&n,&W);
	printData(dv,n);
	int f[MAXN][MAXN],x[MAXN][MAXN];
	quyhoachdong(dv,f,x,n,W);
	printTable(f,x,n,W);
	printf("Gia tri lon nhat: %d\n",f[n-1][W]);
	printPath(dv,f,x,n,W);
	printData(dv,n,1);
	return 0;
}

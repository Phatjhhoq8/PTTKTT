#include<stdio.h>
#include<malloc.h>
#define MAXN 101
typedef struct {
	int tl,gt,pa;
	float dg;
	char name[100];
}Item;
Item* readData(int *n,int *W) {
	freopen("CaiBalo1.txt","r",stdin);
	Item *ds =(Item*)malloc(sizeof(Item));
	scanf("%d",W);
	while(scanf("%d%d%[^\n]",&ds[*n].tl,&ds[*n].gt,&ds[*n].name)!=EOF) {
		ds[*n].dg=1.0f*ds[*n].gt/ds[*n].tl;
		ds[*n].pa=0;
		(*n)++;
		ds=(Item*)realloc(ds,sizeof(Item)*(*n+1));
	}
	freopen("CON","r",stdin);
	return ds;
}
void Swap(Item* a,Item* b) {
	Item c=*a;
	*a=*b;
	*b=c;
}
void sort(Item* ds,int n) {
	for(int i=0;i<n-1;i++) for(int j=n-1;j>i;j--) if(ds[j].dg>ds[j-1].dg) Swap(&ds[j],&ds[j-1]);
}
void printData(Item* ds,int n,int ok=0) {
	if(!ok) for(int i=0;i<n;i++) printf("%d %d %s\n",ds[i].tl,ds[i].gt,ds[i].name);
	else for(int i=0;i<n;i++) printf("%d %d %s %d\n",ds[i].tl,ds[i].gt,ds[i].name,ds[i].pa);
}
int x[MAXN],GTLNTT=0;
void nhanhcan(Item* ds,int n,int W,int TGT,int idx) {
	int yk=W/ds[idx].tl;
	for(int i=yk;i>=0;i--) {
		x[idx]=i;
		int u=W-x[idx]*ds[idx].tl;
		if(idx==n-1||W==0) {
			int total=TGT+x[idx]*ds[idx].gt;
			if(total>GTLNTT) {
				GTLNTT=total;
				for(int i=0;i<n;i++) ds[i].pa=x[i];
			}
		}else if(TGT+x[idx]*ds[idx].gt+u*ds[idx+1].dg>GTLNTT) nhanhcan(ds,n,u,TGT+x[idx]*ds[idx].gt,idx+1);
		x[idx]=0;
	}
}
int main() {
	int n=0,W;
	Item *ds=readData(&n,&W);
	printf("Danh sach do vat truoc khi sap xep: \n");
	printData(ds,n);
	printf("Danh sach do vat sau khi sap xep: \n");
	sort(ds,n);
	printData(ds,n);
	nhanhcan(ds,n,W,0,0);
	printf("Gia tri lon nhat: %d\n",GTLNTT);
	printData(ds,n,1);
	return 0;
}

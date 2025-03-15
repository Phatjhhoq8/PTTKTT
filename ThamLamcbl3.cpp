#include<stdio.h>
#include<malloc.h>
#define min(a,b) ((a<b)?(a):(b))
typedef struct {
	int tl,gt,pa;
	float dg;
	char name[100];
}DoVat;
DoVat* readData(int *n,int *W) {
	freopen("CaiBalo3.txt","r",stdin);
	DoVat* ds = (DoVat*)malloc(sizeof(DoVat));
	scanf("%d",W);
	while(scanf("%d%d%[^\n]",&ds[*n].tl,&ds[*n].gt,&ds[*n].name)!=EOF) {
		ds[*n].dg=1.0f*ds[*n].gt/ds[*n].tl;
		ds[*n].pa=0;
		(*n)++;
		ds=(DoVat*)realloc(ds,sizeof(DoVat)*(*n+1));
	}
	freopen("CON","r",stdin);
	return ds;
}
void printData(DoVat* ds,int n,int ok=0) {
	if(!ok) for(int i=0;i<n;i++) printf("%d %d %s\n",ds[i].tl,ds[i].gt,ds[i].name);
	else for(int i=0;i<n;i++) printf("%d %d %s %d\n",ds[i].tl,ds[i].gt,ds[i].name,ds[i].pa);
}
void Swap(DoVat* a,DoVat* b) {
	DoVat c=*a;
	*a=*b;
	*b=c;
}
void sort(DoVat* ds,int n) {
	for(int i=0;i<n;i++) for(int j=n-1;j>i;j--) if(ds[j].dg>ds[j-1].dg) Swap(&ds[j],&ds[j-1]);
}
int thamlam(DoVat* ds,int n,int W) {
	int sum=0,i=0;
	while(i<n&&W>0) {
		ds[i].pa=min(W/ds[i].tl,1);
		sum+=ds[i].pa*ds[i].gt;
		W-=ds[i].pa*ds[i].tl;
		i++;
	}
	return sum;
}
int main() {
	int n=0,W;
	DoVat* ds = readData(&n,&W);
	printf("Danh sach do vat chua sap xep: \n");
	printData(ds,n);
	printf("Danh sach do vat sap xep theo don gia: \n");
	sort(ds,n);
	printData(ds,n);
	printf("Tong khoi luong la: %d\n",thamlam(ds,n,W));
	printData(ds,n,1);
	
	return 0;
}

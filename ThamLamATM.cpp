#include<stdio.h>
#include<malloc.h>
typedef struct {
	long price;
	int pa;
	char name[100];
}Money;
Money* readData(int *n) {
	freopen("ATM.txt","r",stdin);
	Money *ds =(Money*)malloc(sizeof(Money));
	while(scanf("%d%[^\n]",&ds[*n].price,&ds[*n].name)!=EOF) {
		ds[*n].pa=0;
		(*n)++;
		ds=(Money*)realloc(ds,sizeof(Money)*(*n+1));
	}
	freopen("CON","r",stdin);
	return ds;
}
void printData(Money* ds,int n,int ok=0) {
	if(!ok) for(int i=0;i<n;i++) printf("%d %s\n",ds[i].price,ds[i].name);
	else for(int i=0;i<n;i++) printf("%d %s %d\n",ds[i].price,ds[i].name,ds[i].pa);
}
void Swap(Money* a,Money* b) {
	Money c=*a;
	*a=*b;
	*b=c;
}
void sort(Money* ds,int n) {
	for(int i=0;i<n-1;i++) for(int j=n-1;j>i;j--) if(ds[j].price>ds[j-1].price) Swap(&ds[j],&ds[j-1]);
}
void thamlam(Money* ds,int n,long m) {
	int i=0;
	while(i<n&&m>0) {
		ds[i].pa=m/ds[i].price;
		m-=ds[i].price*ds[i].pa;
		i++;
	}
}
int main() {
	int n=0;
	Money* ds=readData(&n);
	printf("Menh gia truoc khi sap xep la: \n");
	printData(ds,n);
	printf("Menh gia sau khi sap xep la: \n");
	sort(ds,n);
	printData(ds,n);
	printf("Nhap so tien can doi: ");
	long m;scanf("%d",&m);
	thamlam(ds,n,m);
	printData(ds,n,1);
	return 0;
}

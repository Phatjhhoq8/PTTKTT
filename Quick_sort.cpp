#include<stdio.h>
#include<malloc.h>
typedef struct {
	int key;
	float value;
}Node;
Node* readData(int *n) {
	freopen("data.txt","r",stdin);
	Node* ds = (Node*)malloc(sizeof(Node));
	while(scanf("%d%f",&ds[*n].key,&ds[*n].value)!=EOF) {
		(*n)++;
		ds=(Node*)realloc(ds,sizeof(Node)*(*n+1));
	}
	freopen("CON","r",stdin);
	return ds;
}
void printData(Node* ds,int n) {
	for(int i=0;i<n;i++) printf("%d %.2f\n",ds[i].key,ds[i].value);
}
void Swap(Node* a,Node*b) {
	Node c=*a;
	*a=*b;
	*b=c;
}
int findPivot(Node* ds,int l,int r) {
	int k=l+1;
	while(k<=r&&ds[k].key==ds[l].key) k++;
	if(k>r) return -1;
	return ds[k].key>ds[l].key?k:l;
}
int partition(Node* ds,int l,int r,int pivot) {
	while(l<=r) {
		while(ds[l].key<pivot) l++;
		while(ds[r].key>=pivot) r--;
		if(l<r) Swap(&ds[l],&ds[r]);
	}
	return l;
}
void QuickSort(Node* ds,int l,int r) {
	int idx=findPivot(ds,l,r);
	if(idx!=-1) {
		int pivot = partition(ds,l,r,ds[idx].key);
		QuickSort(ds,l,pivot-1);
		QuickSort(ds,pivot,r);
	}
}
int main() {
	int n=0;
	Node* ds = readData(&n);
	printf("Mang chua sap xep: \n");
	printData(ds,n);
	printf("Mang sau khi sap xep dung Quick Sort: \n");
	QuickSort(ds,0,n-1);
	printData(ds,n);
	return 0;
}

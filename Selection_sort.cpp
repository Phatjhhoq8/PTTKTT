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
void SelectionSort(Node* ds,int n) {
	for(int i=0;i<n-1;i++) {
		int idx=i;
		for(int j=i+1;j<n;j++) if(ds[idx].key>ds[j].key) idx=j;
		Swap(&ds[idx],&ds[i]);
	}
}
int main() {
	int n=0;
	Node* ds = readData(&n);
	printf("Mang chua sap xep: \n");
	printData(ds,n);
	printf("Mang sau khi dung Selection Sort sap xep: \n");
	SelectionSort(ds,n);
	printData(ds,n);
	return 0;
}
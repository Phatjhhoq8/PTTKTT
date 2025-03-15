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
void InsertionSort(Node* ds,int n) {
	for(int i=1;i<n;i++) {
		int j=i;
		while(j>0&&ds[j].key<ds[j-1].key) {
			Swap(&ds[j],&ds[j-1]);
			j--;
		}
	}
}
int main() {
	int n=0;
	Node* ds = readData(&n);
	printf("Mang chua sap xep: \n");
	printData(ds,n);
	printf("Mang sau khi dung Insertion Sort sap xep: \n");
	InsertionSort(ds,n);
	printData(ds,n);
	return 0;
}
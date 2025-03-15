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
void pushDown(Node* ds,int first,int last) {
	int r=first;
	while(r<=(last-1)/2) {
		if(last==2*r+1) {
			if(ds[last].key<ds[r].key) Swap(&ds[last],&ds[r]);
			r=last;
		}else if(ds[r].key>ds[2*r+1].key&&ds[2*r+1].key<=ds[2*r+2].key) {
			Swap(&ds[r],&ds[2*r+1]);
			r=2*r+1;
		}else if(ds[r].key>ds[2*r+2].key) {
			Swap(&ds[r],&ds[2*r+2]);
			r=2*r+2;
		}else r=last;
	}
}
void heapify(Node* ds,int i,int n) {
	int temp=i;
	if(i*2+1<=n&&ds[temp].key>ds[2*i+1].key) temp=2*i+1;
	if(i*2+2<=n&&ds[temp].key>ds[2*i+2].key) temp=2*i+2;
	if(temp!=i) {
		Swap(&ds[i],&ds[temp]);
		heapify(ds,temp,n);
	}
}
void HeapSort(Node* ds,int n) {
	for(int i=(n-1)/2;i>=0;i--) heapify(ds,i,n);
	for(int i=n;i>1;i--) {
		Swap(&ds[i],&ds[0]);
		heapify(ds,0,i-1);
	}
	Swap(&ds[0],&ds[1]);
}
int main() {
	int n=0;
	Node* ds = readData(&n);
	printf("Mang chua sap xep: \n");
	printData(ds,n);
	printf("Mang sau khi sap xep dung Heap Sort: \n");
	HeapSort(ds,n-1);
	printData(ds,n);
	return 0;
}

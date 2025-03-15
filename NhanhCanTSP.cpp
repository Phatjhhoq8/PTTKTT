#include<stdio.h>
#include<malloc.h>
#define MAXN 101
const float oo =3.40282e+38;
typedef struct {
	float value;
	int used;
}Data;
void readData(int *n,Data arr[][MAXN]) {
	freopen("TSP.txt","r",stdin);
	scanf("%d",n);
	for(int i=1;i<=*n;i++) for(int j=1;j<=*n;j++) scanf("%f",&arr[i][j].value),arr[i][j].used=0;
	freopen("CON","r",stdin);
}
void printData(Data arr[][MAXN],int n) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) printf("%.2f ",arr[i][j].value);
		printf("\n");
	}
}
int path[MAXN],x[MAXN],used[MAXN];
float GTNNTT=oo;
int minW(Data arr[][MAXN],int n) {
	float minimum=oo;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) if(minimum>arr[i][j].value&&!arr[i][j].used) minimum=arr[i][j].value;
	}
	return minimum;
}
void nhanhcan(Data arr[][MAXN],float TGT,int idx,int level,int n) {
	x[level]=idx;
	used[idx]=1;
	if(level==n) {
		TGT+=arr[x[n]][x[1]].value;
		if(TGT<GTNNTT) {
			GTNNTT=TGT;
			for(int i=1;i<=n;i++) path[i]=x[i];
		}
	}else {
		for(int i=1;i<=n;i++) {
			if(!used[i]&&TGT+arr[idx][i].value+(n-level)*minW(arr,n)<GTNNTT) {
				arr[idx][i].used=arr[i][idx].used=1;
				nhanhcan(arr,TGT+arr[idx][i].value,i,level+1,n);
				arr[idx][i].used=arr[i][idx].used=0;
			}
		}
	}
	used[idx]=0;
}
int main() {
	int n;
	Data arr[MAXN][MAXN];
	readData(&n,arr);
	printData(arr,n);
	while(1) {
		printf("Nhap vi tri bat dau: \n");
		int position;scanf("%d",&position);
		if(position<1||position>n) break;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) arr[i][j].used=0;
		nhanhcan(arr,0,position,1,n);
		printf("Gia tri nho nhat la: %.2f\n",GTNNTT);
		printf("Danh sach cac canh: \n");
		for(int i=2;i<=n;i++) printf("%d %d\n",path[i-1],path[i]);
		printf("%d %d\n",path[n],path[1]);
	}
	return 0;
}

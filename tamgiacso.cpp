#include<stdio.h>
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
#define MAXN 101
const int oo = 0x3f3f3f3f;
void readData(int dp[][MAXN],int *n) {
	freopen("tam_giac_so.txt","r",stdin);
	int ok=0;
	while(1) {
		(*n)++;
		for(int i=1;i<=(*n);i++) {
			if(scanf("%d",&dp[*n][i])==EOF) {ok=1;break;}
		}
		if(ok) {(*n)--;break;}
	}
	freopen("CON","r",stdin);
}
void printData(int dp[][MAXN],int n) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) printf("%d ",dp[i][j]);
		printf("\n");
	}
}
int quyhoachdong(int arr[][MAXN],int dp[][MAXN],int n) {
	dp[1][1]=arr[1][1];
	for(int i=1;i<n;i++) {
		for(int j=1;j<=i;j++) {
			if(j-1>0&&j-1<=i+1&&dp[i+1][j-1]<dp[i][j]+arr[i+1][j-1]) dp[i+1][j-1]=dp[i][j]+arr[i+1][j-1];
			if(j>0&&j<=i+1&&dp[i+1][j]<dp[i][j]+arr[i+1][j]) dp[i+1][j]=dp[i][j]+arr[i+1][j];
			if(j+1>0&&j+1<=i+1&&dp[i+1][j+1]<dp[i][j]+arr[i+1][j+1]) dp[i+1][j+1]=dp[i][j]+arr[i+1][j+1];
		}
	}
	int maximum=-oo,idx=-1;
	for(int i=1;i<=n;i++) if(maximum<dp[n][i]) maximum=dp[n][i],idx=i;
	return idx;
}
int main() {
	int arr[MAXN][MAXN]={0},n=0,dp[MAXN][MAXN]={0},path[MAXN]={0};
	readData(arr,&n);
	printData(arr,n);
	int t=quyhoachdong(arr,dp,n);
	printData(dp,n);
	printf("Tong gia tri: %d\n",dp[n][t]);
	printf("Duong di co trong so lon nhat: ");
	int m=1;
	for(int i=2;i<=n;i++) if(dp[n][i]>dp[n][m]) m=i;
	path[n]=m;
	for(int i=n;i>1;i--) {
		int maximum=0;
		if(path[i]-1>0&&path[i]-1<=i-1&&dp[i-1][path[i]-1]>dp[i-1][maximum]) maximum=path[i]-1;
		if(path[i]>0&&path[i]<=i-1&&dp[i-1][path[i]]>dp[i-1][maximum]) maximum=path[i];
		if(path[i]+1>0&&path[i]+1<=i-1&&dp[i-1][path[i]+1]>dp[i-1][maximum]) maximum=path[i]+1;
		path[i-1]=maximum;
	}
	for(int i=1;i<=n;i++) printf("%d ",arr[i][path[i]]);
	return 0;
}

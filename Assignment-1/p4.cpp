#include <iostream>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int a[n]; //theorems;
	int b[n]; //sleep
	long long int max=0, nth=0, startc=0;
	bool start=false;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];
	int i, j;
	for (i=0; i<n; i++){
		nth=0;
		for (int x=0; x<i; x++)
			if (b[x]==1)
				nth=nth+a[x];
		start=false;
		startc=0;
		for (j=i; j<n; j++){
			if (b[j]==1 && start==false)
				nth=nth+a[j];
			if (b[j]==0 && start==false){
				start=true;
			}
			if (start==true && startc<k){
				startc++;
				nth=nth+a[j];
			}
			else if (startc>=k && b[j]==1)
				nth=nth+a[j];
			else if (startc>=k && b[j]==0)
				break;
		}
		for (int x=j+1; x<n; x++)
			if (b[x]==1)
				nth=nth+a[x];
		if (nth>max) max=nth;
	}
	cout << max;
}
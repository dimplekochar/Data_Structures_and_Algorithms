#include <iostream>
using namespace std;

void merge(int l, int mid, int r, int arr[]){
	int i=mid-l+1;
	int j=r-mid;
	int p=l, q=mid+1, x=0;
	int a[r-l+1];
	while(true){
		if (arr[p]<=arr[q] && i>0 && j>0){
			a[x]=arr[p];
			x++;
			p++;
			i--;
		}
		else if (arr[p]>arr[q] && i>0 && j>0){
			a[x]=arr[q];
			x++;
			q++;
			j--;
		}
		else if (j==0 && i!=0){
			a[x]=arr[p];
			x++;
			p++;
			i--;
		}
		else if (i==0 && j!=0){
			a[x]=arr[q];
			x++;
			q++;
			j--;
		}
		else if (i==0 && j==0)
			break;
	}
	for (int i=l; i<=r; i++){
		arr[i]=a[i-l];
	}
}


void mergesort(int l, int r, int arr[]){
	if (l<r){
		int mid=l+ (r-l)/2;
		mergesort(l, mid, arr);
		mergesort(mid+1, r, arr);
		merge(l, mid, r, arr);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	mergesort(0, n-1, arr);
	for (int i=0; i<n; i++){
		cout << arr[i] << " ";
	}

	
}
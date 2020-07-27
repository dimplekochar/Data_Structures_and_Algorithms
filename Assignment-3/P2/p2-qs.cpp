#include <iostream>
using namespace std;

// Taking the first element as pivot

int quick_div(int l, int h, int arr[]){
	int t;
	int pivot=arr[h];
	int i=l-1;
	for (int j=l; j<=h-1; j++){
		if (arr[j]<=pivot){
			i++;
			t = arr[i]; 
    		arr[i] = arr[j]; 
    		arr[j] = t; 
		}
	}		
	t = arr[i+1]; 
    arr[i+1] = arr[h]; 
    arr[h] = t; 
    return (i + 1); 
}

void quick_sort(int l, int h, int arr[]){
	if(l<h){
		int p=quick_div(l, h, arr);
		quick_sort(l, p-1, arr); 
        quick_sort(p+1, h, arr); 
	}
}


int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	quick_sort(0, n-1, a);
	for (int i=0; i<n; i++)
		cout << a[i] << " ";
}
#include <iostream>
using namespace std;

int maxOnes(int arr[], int n){
	int ones=0; 
    int mini=n; 
    int curr=n; 
    for (int i=0; i<n; i++){ 
        if (arr[i]==1) 
           ones++; 
        curr=min(arr[i], curr+arr[i]); 
        mini=min(curr, mini); 
    } 
    mini=min(n, mini); 
    return ones-mini; 
} 

int main(){ 
	int n;
	cin >> n;
    int arr[n], a;

    for (int i=0; i<n; i++){
    	cin >> a;
    	if (a==1)
    		arr[i]=1;
    	else
    		arr[i]=-1; 
    }
    cout << maxOnes(arr, n);
} 
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i=0; i<n; i++){
		cin >> a[i];
		b[i]=1;
	}
	for (int i=0; i<n; i++){
		for (int j=i-a[i]; j<i; j++){
			if (j>=0){
				b[j]=0;
			}
		}
	}
	int count=0;
	for (int i=0; i<n; i++){
		if (b[i]==1)
			count++;
	}
	cout << count;


	
}
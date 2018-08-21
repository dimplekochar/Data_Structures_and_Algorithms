#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	long long int count;
	long long int majority=-1;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++){
		count=0;
		for (int j=0; j<n; j++){
			if (a[i]==a[j]) count++;
		}
		if (count >= (n/2)+1){
			majority=a[i];
			break;
		}
	}
	cout << majority;

	
}
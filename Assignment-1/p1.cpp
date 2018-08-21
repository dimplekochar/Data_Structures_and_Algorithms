#include <iostream>
using namespace std;

int main(){
	int n, t, count=0;
	cin >> n >> t;
	int a[n];
	bool majority=false;
	for (int i=0; i<n; i++){
		cin>>a[i];
		if (a[i]==t) count++;
	}
	if (count >= (n/2)+1) majority=true;
	cout << majority;
	
}
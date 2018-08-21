#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	bool enter=false;
	for (int i=0; i<n; i++){
		cin >> a[i];
		a[i]=a[i]-i;
		if (a[i]<= 0) {
			cout << i+1;
			enter=true;
			break;
		}
	}
	while (enter==false){
		for (int i=0; i<n; i++){
			a[i]=a[i]-n;
			if (a[i]<=0) {
				cout << i+1;
				enter=true;
				break;
			}
		}
	}
}
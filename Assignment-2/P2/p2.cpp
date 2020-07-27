#include <iostream>
using namespace std;

int tour(long long n, int p[], int d[]){  //p= petrol, d=distance
	for (int i=0; i<n; i++){
		int t=0, j=i+1, cp=p[i]-d[i];
		while(t<n && cp>=0){
			cp=cp+p[j%n]-d[j%n];
			j++;
			t++;
		}
		if (t==n) {
			return i;			
		}

	}
	int m=-1;
	return m;
}


int main(){
	long long n;
	cin>>n;
	int p[n], d[n];
	for (int i=0; i<n; i++) {
		cin >> p[i];
		cin >> d[i];
	}
	cout << tour(n, p, d);

	
}
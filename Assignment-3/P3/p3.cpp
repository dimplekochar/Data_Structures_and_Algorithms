#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int main(){
	int min=101, ansl;
	int n;
	cin >> n;
	string mins, ans, s="";
	string arr[n];
	for (int i=0; i<n; i++){
		cin >> arr[i];
		if (arr[i].length()<min){
			min=arr[i].length();
			mins=arr[i];
		}
	}
	ansl=min;
	ans=mins;
	for (int i=0; i<n; i++){
		for (int j=0; j<ansl; j++){
			if ((arr[i])[j]==ans[j]){
				s=s+ans[j];
			}
			if (j==n){
				ans=s;
				ansl=s.length();
				s="";
				break;
			}
			if ((arr[i])[j]!=ans[j]){
				ans=s;
				ansl=s.length();
				s="";
				break;
			}
		}
	}
	if (ans!="")
		cout << ans;
	else 
		cout << "-1";
}
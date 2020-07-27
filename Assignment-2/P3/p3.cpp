#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

void small(int n, int a[]){
	stack <int> s, inx; //stacks of the values and index
	unordered_map <int, int> ans; //a map between the index of an element and index of next smaller value
	s.push(a[0]);
	inx.push(0);

	for (int i=1; i<n; i++){
		if (s.empty()==1){
			s.push(a[i]);
			inx.push(i);
			continue;
		}
		while (true){
		if(s.empty()==0 && a[i]<s.top()) {
			ans[inx.top()]=i;
			s.pop();
			inx.pop();
		}
		else break;}
		s.push(a[i]);
		inx.push(i);
	}
	while (s.empty()==0){
		ans[inx.top()]=-1;
		s.pop();
		inx.pop();
	}
	for (int i=0; i<n; i++){
		cout << ans[i] << " ";
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	small(n, a);

	
}
#include <iostream>
#include <stack>
using namespace std;

int area(int n, int a[]){
	stack <int> s;
	int max=0; //max as of now
	int top; //top of stack
	int curr; //current area
	int i=0;

	while (i<n){		
		if (s.empty()==1 || a[i]>=a[s.top()]){
			s.push(i);
			i++;
		}

		else{
			top=s.top();
			s.pop();
			if (s.empty()==1)
				curr=a[top]*(i);
			else
				curr=a[top]*(i-s.top()-1);
			if (max<curr)
				max=curr;

		}
	}
	while (s.empty()==0){
		top=s.top();
		s.pop();
			if (s.empty()==1)
				curr=a[top]*(i);
			else
				curr=a[top]*(i-s.top()-1);
			if (max<curr)
				max=curr;

		}
	return max;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	cout << area(n, a);

	
}
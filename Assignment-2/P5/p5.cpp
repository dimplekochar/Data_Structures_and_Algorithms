#include <iostream>
#include <stack>
using namespace std;


int main(){
	int n;
	cin >> n;
	int q, x;
	stack <int> s1, s2;
	for (int i=0; i<n; i++){
		cin >> q;
		if (q==1){
			cin >> x;
			s1.push(x);
		}
		else if (q==2){
			if (s2.empty()==1){
				while (s1.empty()==0){
					s2.push(s1.top());
					s1.pop();
				}
			}
			s2.pop(); 
		}
		else if (q==3){
			if (s2.empty()==0){
				cout << s2.top();
			}
			else{
				if (s1.empty()==0){
					while (s1.empty()==0){
						s2.push(s1.top());
						s1.pop();
					}
					cout << s2.top() << endl;
				}
				else
					cout << "-1" <<endl;
			}
		}
	}
}
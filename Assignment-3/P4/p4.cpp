#include <iostream>
#include <string>
using namespace std;

// note that: for every comparison, whether it gives me false or true, I have considered it as a good access (except for the bad access comparison)

int access(int g, int b, string data[], int l, int h, string key){
	if (b==1){
		while(true){
			if(std::string(key) > data[l]){
				l++;
				g=g+1;  //increment good access by 1 since only one comparison.
				if (l>h){
					cout << l << endl;
					cout << g << endl;
					return 0;}
				continue;
			}
			else if(std::string(key) == data[l]){
				g=g+2; //increment good access by 2 since this + previous if(std::string(key) > data[l]) comparison.
				cout << l << endl;
				cout << g << endl;
				return 0;
			}
			else{ //increment good access by 2 since *else if(std::string(key) == data[l])* + *if(std::string(key) > data[l])* comparison.
				g=g+2;
				cout << "-1" << endl;
				cout << g << endl;
				return 0;
			}
		}
	}
	else if (b==0){
		int mid=l+(h-l)/2;
		if (std::string(key) < data[mid]){ //no increment in good access as bad access
			b=1;
			access(g, b, data, l, mid, key);
		}
		else if (std::string(key) == data[mid]){
			g=g+1; //increment in good access by 2 as this access + not(bad) access
			cout << mid << endl;
			cout << g << endl;
			return 0;
		}
		else{
			g=g+1; //increment in good access by 2 as if and else if loop comparisons.
			access(g, b, data, mid+1, h, key);
		}
	}
}

int main(){
	int n, b=0;
	cin >> n;
	string data[n];
	for (int i=0; i<n; i++){
		cin >> data[i];
	}
	string key;
	cin >> key;
	access(0, b, data, 0, n-1, key);
}